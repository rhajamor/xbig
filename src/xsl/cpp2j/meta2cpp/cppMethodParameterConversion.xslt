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
	xmlns:fn="http://www.w3.org/2005/xpath-methods"
	xmlns:xdt="http://www.w3.org/2005/xpath-datatypes"
	xmlns:xd="http://www.pnp-software.com/XSLTdoc"
	xmlns:xbig="http://xbig.sourceforge.net/XBiG">

	<xsl:import href="cppMethodDeclaration.xslt" />
	<xsl:import href="cppCodeWriter.xslt" />
	<xsl:import href="../../util/metaTypeInfo.xslt" />

	<xd:doc type="stylesheet">
		<xd:short></xd:short>
	</xd:doc>

	<xsl:template name="cppMethodParameterConversion">
		<xsl:param name="config"/>
		<xsl:param name="class"/>
		<xsl:param name="method"/>

		<!-- iterate through all parameters for conversion -->
		<xsl:for-each select="$method/parameters/parameter">
			<xsl:variable name="parameterPosition" select="position()"/>

			<!-- resolve typedefs -->
			<xsl:variable name="resolvedParameter" select="xbig:resolveTypedef(
				./type, $class, $root)"/>

			<!-- for performance reasons -->
			<!-- 
			<xsl:variable name="fullTypeName"
					select="xbig:getFullTypeName($resolvedParameter, $class, $root)"/>
			 -->
			<xsl:variable name="fullTypeName" select="$resolvedParameter"/>

			<!-- if there is no param name in original lib -->
			<xsl:variable name="paramName">
				<xsl:choose>
					<xsl:when test="not(./name) or ./name = ''">
						<xsl:value-of select="concat($config/config/meta/parameter/defaultName,
												$parameterPosition)"/>
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="./name"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:variable>

			<!-- parameter name for call native function -->
			<xsl:variable name="lib_var"
				select="xbig:cpp-param($config, $paramName)" />

			<!-- write new line seperator for parameter declaration -->
			<xsl:text>#nl#</xsl:text>

			<!-- write type for transformation -->
			<!-- take cpp attribute if available, otherwise write meta -->
			<xsl:value-of select="xbig:cpp-type($config, ., $class, $fullTypeName)" />

			<!-- write seperator for variable -->
			<xsl:text>&#32;</xsl:text>

			<!-- write variable for transformed variable -->
			<xsl:value-of select="$lib_var" />

			<!-- write assignment operator -->
			<xsl:text>&#32;=&#32;</xsl:text>

			<!-- write conversion to C++ type -->
			<xsl:value-of select="xbig:jni-to-cpp(
							$config, $class, $method, ., $fullTypeName, position())" />

			<!-- finish conversion statement -->
			<xsl:text>;</xsl:text>

		</xsl:for-each>
		<!-- call library method call -->

	</xsl:template>


</xsl:stylesheet>
