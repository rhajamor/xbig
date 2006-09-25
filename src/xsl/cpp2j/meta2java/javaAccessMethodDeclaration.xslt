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

	<xsl:import href="javaType.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single original class</xd:short>
	</xd:doc>

	<xsl:template name="javaAccessMethodDeclaration">
		<xsl:param name="config" />
		<xsl:param name="class" />
		<xsl:param name="method" />

		<!-- shortcut of function name -->
		<xsl:variable name="method_name" select="$method/name" />

		<!-- shortcut for return type, take long for constructors -->
		<xsl:variable name="return_type" select="$method/type" />

		<!-- shortcut for visibility -->
		<xsl:variable name="visibility" select="$method/@visibility" />

		<!-- shortcut for static property -->
		<xsl:variable name="static" select="$method/@static" />

		<!-- shortcut for virtuality property -->
		<xsl:variable name="virtuality" select="$method/@virt" />


		<!-- write method documentation -->

		<xsl:text>/**&#32;</xsl:text>
		<xsl:for-each select="$method/detaileddescription/para">
			<xsl:text>&#10;</xsl:text>
			<xsl:value-of select="normalize-space(text())" />
		</xsl:for-each>
		<xsl:text>&#32;**/</xsl:text>

		<!-- write method modifiers -->

		<!-- write method visibility -->
		<xsl:if test="$visibility">
			<xsl:text>&#32;</xsl:text>
			<xsl:value-of select="$visibility" />
		</xsl:if>

		<!-- write static method modifier -->
		<xsl:if test="$static eq'true'">
			<xsl:text>&#32;static</xsl:text>
		</xsl:if>

		<!-- handle virtual modifiers -->
		<xsl:choose>

			<!-- no virtual function -->
			<xsl:when test="$virtuality eq 'non-virtual'">
				<xsl:if test="not(empty($return_type))">
					<xsl:text>&#32;final</xsl:text>
				</xsl:if>
			</xsl:when>

			<!-- abstract function -->
			<xsl:when test="$virtuality = 'pure-virtual'">
				<xsl:text>&#32;abstract</xsl:text>
			</xsl:when>

			<!-- virtual function -->
			<xsl:when test="$virtuality = 'virtual'" />

			<!-- error, not handled type of virtuality -->
			<xsl:otherwise>
				<xsl:message terminate="no">
					ERROR: virtual type '
					<xsl:value-of select="$virtuality" />
					' not allowed.
				</xsl:message>
			</xsl:otherwise>
		</xsl:choose>

		<!-- write return type if available-->
		<xsl:if test="$return_type">
			<xsl:text>&#32;</xsl:text>
			<xsl:call-template name="javaType">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="param" select="$method" />
			</xsl:call-template>
		</xsl:if>

		<!-- write method name -->
		<xsl:text>&#32;</xsl:text>
		<xsl:value-of select="$method_name" />

		<!-- begin parameter declaration -->
		<xsl:text>(</xsl:text>

		<!-- iterator through all parameters -->
		<xsl:for-each select="$method/parameters/parameter">

			<!-- write parameter type -->
			<xsl:call-template name="javaType">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="param" select="." />
			</xsl:call-template>

			<!-- seperator type and name -->
			<xsl:text>&#32;</xsl:text>

			<!-- write parameter name -->
			<xsl:value-of select="name" />

			<!-- if another parameter follows, write seperator -->
			<xsl:if test="position()!=last()">
				<xsl:text>,&#32;</xsl:text>
			</xsl:if>

		</xsl:for-each>

		<!-- end parameter declaration -->
		<xsl:text>)</xsl:text>

	</xsl:template>

</xsl:stylesheet>
