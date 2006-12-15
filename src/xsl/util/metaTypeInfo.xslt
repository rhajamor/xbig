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
	
-->

<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions"
	xmlns:xdt="http://www.w3.org/2005/xpath-datatypes"
	xmlns:xd="http://www.pnp-software.com/XSLTdoc">

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single type</xd:short>
	</xd:doc>

	<xsl:template name="metaTypeInfo">
		<xsl:param name="root" />
		<xsl:param name="param" />

		<!-- shortcut for meta type -->
		<xsl:variable name="meta_type"
			select="if($param/type) then $param/type else 'long'" />

		<!-- shortcut for param passing type -->
		<xsl:variable name="pass_type" select="$param/@passedBy" />

		<!-- shortcut for const type -->
		<xsl:variable name="const_type" select="$param/type/@const" />

		<!-- extract jni type depending on meta type, const/non-const, pass type -->


		<!-- iterator through all entries for given type -->
		<xsl:for-each select="$root/type">

			<!-- build a element which contains all types from config as children -->
			<xsl:if test="@meta eq $meta_type">
				<xsl:element name="types">
					<xsl:copy-of select="."/>
				</xsl:element>
			</xsl:if>

		</xsl:for-each>

	</xsl:template>


	<xsl:template name="metaFirstTypeInfo">
		<xsl:param name="root" />
		<xsl:param name="param" />

		<!-- calculate all suitable type informations -->
		<xsl:variable name="type_infos">
			<xsl:call-template name="metaTypeInfo">
				<xsl:with-param name="root" select="$root" />
				<xsl:with-param name="param" select="$param" />
			</xsl:call-template>
		</xsl:variable>

		<!-- ensure valid signature -->
		<xsl:if test="count($type_infos) = 0">
			<xsl:message terminate="yes">
				ERROR: no type info for meta type '
				<xsl:value-of select="$param/type" />
				' found.
			</xsl:message>
		</xsl:if>

		<!-- take first type info-->
		<xsl:copy-of select="$type_infos/types/type[1]" />

	</xsl:template>

	<xsl:template name="metaExactTypeInfo">
		<xsl:param name="root" />
		<xsl:param name="param" />

		<!-- calculate all suitable type informations -->
		<xsl:variable name="type_infos">
			<xsl:call-template name="metaTypeInfo">
				<xsl:with-param name="root" select="$root" />
				<xsl:with-param name="param" select="$param" />
			</xsl:call-template>
		</xsl:variable>

		<!-- ensure valid signature -->
		<xsl:if test="count($type_infos) = 0">
			<xsl:message terminate="yes">
				ERROR: no type info for meta type '
				<xsl:value-of select="$param/type" />
				' found.
			</xsl:message>
		</xsl:if>
 
		<!-- find exact type info-->
		<xsl:for-each select="$type_infos/types/type">
			<xsl:choose>

				<!-- when passed by value, the pass attribute is missing in config.xml -->
				<xsl:when test="not(@pass) and ($param/@passedBy eq 'value')">
					<xsl:copy-of select="."/>
				</xsl:when>

				<xsl:when test="@pass eq $param/@passedBy">
					<xsl:copy-of select="."/>
				</xsl:when>

			</xsl:choose>
		</xsl:for-each>

	</xsl:template>

</xsl:stylesheet>
