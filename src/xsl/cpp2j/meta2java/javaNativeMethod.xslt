<?xml version="1.0" encoding="UTF-8"?>

<!--
	
	This source file is part of cpp2j
	(The JNI bindings for C++)
	For the latest info, see http://www.cpp2j.org/
	
	Copyright (c) 2006 OneStepAhead AG, Stuttgart
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
	<xsl:import href="javaMethodParameterList.xslt" />
	<xsl:import href="../../util/metaMethodName.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single original class</xd:short>
	</xd:doc>

	<xsl:template name="javaNativeMethod">
		<xsl:param name="config" />
		<xsl:param name="class" />
		<xsl:param name="method" />

		<!-- shortcut of function name -->
		<xsl:variable name="method_name" select="$method/name" />

		<!-- shortcut for return type, take long for constructors -->
		<xsl:variable name="return_type"
			select="if($method/type) then $method/type else 'long'" />

		<!-- shortcut for static property -->
		<xsl:variable name="static" select="$method/@static" />

		<!-- shortcut for virtuality property -->
		<xsl:variable name="virtuality" select="$method/@virt" />

		<!-- write visibility modifier -->
		<xsl:text>&#32;private</xsl:text>

		<!-- write native method modifier -->
		<xsl:text>&#32;native</xsl:text>

		<!-- write static method modifier (static attribute or constructor -->
		<xsl:if test="$static eq'true' or not($method/type)">
			<xsl:text>&#32;static</xsl:text>
		</xsl:if>

		<!-- handle virtual modifiers -->
		<xsl:choose>
			<xsl:when test="$virtuality = 'non-virtual'">
				<xsl:text>&#32;final</xsl:text>
			</xsl:when>
			<xsl:when test="$virtuality = 'pure-virtual'">
				<xsl:text>&#32;abstract</xsl:text>
			</xsl:when>
			<xsl:when test="$virtuality = 'virtual'" />
			<xsl:otherwise>
				<xsl:message terminate="no">
					ERROR: virtual type '
					<xsl:value-of select="$virtuality" />
					' not allowed.
				</xsl:message>
			</xsl:otherwise>
		</xsl:choose>

		<!-- write seperator for return type -->
		<xsl:text>&#32;</xsl:text>

		<!-- write return type -->
		<xsl:call-template name="javaType">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="param" select="$method" />
		</xsl:call-template>

		<!-- write method name -->
		<xsl:text>&#32;</xsl:text>
		<xsl:call-template name="metaMethodName">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="method" select="$method" />
		</xsl:call-template>

		<!-- begin parameter declaration -->
		<xsl:text>(</xsl:text>

		<!-- write instance pointer if no static function and no constructor -->
		<xsl:if test="$static ne 'true' and $method/type">

			<xsl:text>long _pointer_</xsl:text>

			<!-- if more parameters available -->
			<xsl:if test="count($method/parameters/parameter) > 0">
				<!-- write seperator for following parameters -->
				<xsl:text>,</xsl:text>
			</xsl:if>
		</xsl:if>

		<!-- write real parameter list including types -->
		<xsl:call-template name="javaMethodParameterList">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="class" select="$class" />
			<xsl:with-param name="method" select="$method" />
			<xsl:with-param name="with_types" select="'true'" />
		</xsl:call-template>

		<!-- end parameter declaration -->
		<xsl:text>);</xsl:text>

	</xsl:template>

</xsl:stylesheet>
