<?xml version="1.0" encoding="UTF-8"?>

<!--
	
	This source file is part of XBiG
		(XSLT Bindings Generator)
	For the latest info, see http://sourceforge.net/projects/xbig
	
	Copyright (c) 2006 The XBiG Development Team
	Also see acknowledgements in Readme.html
	
	This program is free software; you can redistribute it and/or modify it under
	the terms of the GNU Lesser General Public License as published by the Free Software
	Foundation; either version 2 of the License, or (at your option) any later
	version.
	
	This program is distributed in the hope that it will be useful, but WITHOUT
	ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
	FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with
	this program; if not, write to the Free Software Foundation, Inc., 59 Temple
	Place - Suite 330, Boston, MA 02111-1307, USA, or go to
	http://www.gnu.org/copyleft/lesser.txt.
	
	Author: Frank Bielig
			Christoph Nenning
	
-->

<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions"
	xmlns:xdt="http://www.w3.org/2005/xpath-datatypes"
	xmlns:xd="http://www.pnp-software.com/XSLTdoc">

	<xsl:import href="../../util/metaTypeInfo.xslt" />
	<xsl:import href="../../util/firstLetterToUpperCase.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single type</xd:short>
	</xd:doc>

	<xsl:template name="javaType">
		<xsl:param name="config" />
		<xsl:param name="param" />
		<xsl:param name="writingNativeMethod" />

		<!-- extract jni type depending on meta type, const/non-const, pass type -->
		<xsl:variable name="type_info">
			<xsl:call-template name="metaFirstTypeInfo">
				<xsl:with-param name="root" 
					select="$config/config/java/types" />
				<xsl:with-param name="param" select="$param" />
			</xsl:call-template>
		</xsl:variable>

		<!-- print first type found in result list -->
		<xsl:choose>

			<!-- write pointer class -->
			<xsl:when test="($param/@passedBy='pointer' or $param/@passedBy='reference')
						 and ($writingNativeMethod ne 'true')">
				<xsl:call-template name="javaPointerClass">
					<xsl:with-param name="config" select="$config" />
					<xsl:with-param name="param" select="$param" />
				</xsl:call-template>
			</xsl:when>

			<xsl:otherwise>
				<xsl:value-of select="$type_info/type/@java" />
			</xsl:otherwise>
		</xsl:choose>

	</xsl:template>


	<xsl:template name="javaPointerClass">
		<xsl:param name="config" />
		<xsl:param name="param" />

		<!-- extract jni type depending on meta type, const/non-const, pass type -->
		<xsl:variable name="type_info">
			<xsl:call-template name="metaFirstTypeInfo">
				<xsl:with-param name="root" 
					select="$config/config/java/types" />
				<xsl:with-param name="param" select="$param" />
			</xsl:call-template>
		</xsl:variable>

		<xsl:choose>
			<xsl:when test="$param/type ne 'int'">
				<xsl:value-of>
					<xsl:call-template name="firstLetterToUpperCase">
						<xsl:with-param name="name">
							<xsl:choose>
								<xsl:when test="contains($type_info/type/@java, ' ')">
									<xsl:value-of select="substring-after($type_info/type/@java, ' ')" />
								</xsl:when>
								<xsl:otherwise>
									<xsl:value-of select="$type_info/type/@java" />
								</xsl:otherwise>
							</xsl:choose>
						</xsl:with-param>
					</xsl:call-template>
					<xsl:value-of select="'Pointer'" />
				</xsl:value-of>
			</xsl:when>

			<!-- IntegerPointer is a special name -->
			<xsl:when test="$param/type eq 'int'">
				<xsl:value-of select="'IntegerPointer'" />
			</xsl:when>
		</xsl:choose>

	</xsl:template>

</xsl:stylesheet>
