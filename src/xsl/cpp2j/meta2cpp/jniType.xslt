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
	xmlns:xd="http://www.pnp-software.com/XSLTdoc"
	xmlns:xbig="http://xbig.sourceforge.net/XBiG">

	<xsl:import href="../../util/metaTypeInfo.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single type</xd:short>
	</xd:doc>

	<xsl:template name="jniType">
		<xsl:param name="config" />
		<xsl:param name="param" />
		<xsl:param name="class" />

		<xsl:variable name="type_info">
			<xsl:call-template name="metaExactTypeInfo">
				<xsl:with-param name="root"
					select="$config/config/cpp/jni/types" />
				<xsl:with-param name="param" select="$param" />
			</xsl:call-template>
		</xsl:variable>

		<!-- check if there is a type in config -->
		<xsl:choose>

			<!-- if no type info is found -> we are dealing with a class / enum / ... -->
			<xsl:when test="not($type_info/type/@jni)">
				<xsl:choose>

					<!-- if this type is an enum -->
					<xsl:when test="xbig:isEnum($param/type, $class, $root)">
						<xsl:value-of select="'jint'"/>
					</xsl:when>

					<!-- if this type is a class or struct -->
					<xsl:when test="xbig:isClassOrStruct($param/type, $class, $root)">
						<xsl:value-of select="'jlong'"/>
					</xsl:when>

					<xsl:otherwise>
						<xsl:value-of select="$param/type"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>

			<!-- print first type found in result list -->
			<xsl:otherwise>
				<xsl:value-of select="$type_info/type/@jni" />
			</xsl:otherwise>
		</xsl:choose>

	</xsl:template>

</xsl:stylesheet>
