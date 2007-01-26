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

	<xsl:import href="../../util/metaMethodName.xslt" />
	<xsl:import href="../../util/metaTypeInfo.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single original class</xd:short>
	</xd:doc>

	<xsl:template name="javaMethodParameterList">
		<xsl:param name="config" />
		<xsl:param name="class" />
		<xsl:param name="method" />
		<xsl:param name="with_types" />
		<xsl:param name="writingNativeMethod" />
		<xsl:param name="callingNativeMethod" />

		<!-- iterator through all parameters -->
		<xsl:for-each select="$method/parameters/parameter">

			<!-- if writing java types switched on -->
			<xsl:if test="$with_types eq 'true'">

				<!-- write parameter type -->
				<xsl:choose>
					<xsl:when test="($writingNativeMethod eq 'true') and
						 ((./@passedBy eq 'pointer') or (./@passedBy eq 'reference'))">
						<xsl:value-of select="'long'" />
					</xsl:when>

					<!-- if this parameter is a parametrized template -->
					<xsl:when test="($writingNativeMethod eq 'true') and
						 (contains(./type, '&lt;'))">
						<xsl:value-of select="'long'" />
					</xsl:when>

					<xsl:otherwise>
						<xsl:call-template name="javaType">
							<xsl:with-param name="config" select="$config" />
							<xsl:with-param name="param" select="." />
							<xsl:with-param name="class" select="$class" />
							<xsl:with-param name="writingNativeMethod" select="$writingNativeMethod" />
							<xsl:with-param name="typeName" select="./type" />
						</xsl:call-template>
					</xsl:otherwise>
				</xsl:choose>

			</xsl:if>

			<!-- seperator type and name -->
			<xsl:text>&#32;</xsl:text>

			<!-- write parameter name -->
			<xsl:value-of select="name" />

			<!-- if we call a native method and have to pass an InstancePointer -->
			<xsl:if test="($callingNativeMethod eq 'true') and
				 		  ((./@passedBy eq 'pointer') or (./@passedBy eq 'reference'))">
				<xsl:value-of select="'.object.pointer'" />
			</xsl:if>

			<!-- resolve typedefs -->
			<xsl:variable name="resolvedType" select="xbig:resolveTypedef(./type, $class, $root)"/>

			<!-- if this parameter is a enum -->
			<xsl:if test="($callingNativeMethod eq 'true') and
				 		  (xbig:isEnum($resolvedType, $class, $root))">
				<xsl:value-of select="'.value'" />
			</xsl:if>

			<!-- if this parameter is a class or struct -->
			<xsl:if test="($callingNativeMethod eq 'true') and
				 		  (xbig:isClassOrStruct($resolvedType, $class, $root))">
				<xsl:value-of select="'.getInstancePointer().pointer'" />
			</xsl:if>

			<!-- if this parameter is a parametrized template -->
			<xsl:if test="($callingNativeMethod eq 'true') and
				 		  (contains($resolvedType, '&lt;'))">
				<xsl:value-of select="'.getInstancePointer().pointer'" />
			</xsl:if>

			<!-- if this parameter is a template typedef -->
			<xsl:if test="($callingNativeMethod eq 'true') and
				 		  (xbig:isTemplateTypedef($resolvedType, $class, $root))">
				<xsl:value-of select="'.getInstancePointer().pointer'" />
			</xsl:if>

			<!-- if another parameter follows, write seperator -->
			<xsl:if test="position()!=last()">
				<xsl:text>,&#32;</xsl:text>
			</xsl:if>

		</xsl:for-each>


	</xsl:template>

</xsl:stylesheet>
