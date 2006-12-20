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
	<xsl:import href="cppMethodParameterConversion.xslt" />

	<xd:doc type="stylesheet">
		<xd:short></xd:short>
	</xd:doc>

	<xsl:template name="cppMethodImpl">
		<xsl:param name="config" />
		<xsl:param name="class_prefix" />
		<xsl:param name="class" />
		<xsl:param name="method" />

		<!-- shortcut for static attribute -->
		<xsl:variable name="static" select="$method/@static" />

		<!-- write method declaration -->
		<xsl:call-template name="cppMethodDeclaration">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="class_prefix" select="$class_prefix" />
			<xsl:with-param name="method" select="." />
		</xsl:call-template>

		<!-- start implementation -->
		<xsl:text>&#10;{</xsl:text>

		<!-- calculate name of code template depending on function type -->
		<xsl:variable name="code_template">
			<xsl:choose>
				<!-- handle constructor -->
				<xsl:when test="not($method/type)">
					<xsl:copy-of
						select="$config/config/cpp/method/constructor" />
				</xsl:when>

				<!-- handle destructor -->
				<xsl:when test="$method/@destructor eq 'true'">
					<xsl:copy-of
						select="$config/config/cpp/method/destructor" />
				</xsl:when>

				<!-- handle public attribute getter -->
				<xsl:when test="$method/@public_attribute_getter eq 'true'">
					<xsl:choose>
						<xsl:when test="@static!='true'">
							<xsl:copy-of select="$config/config/cpp/method/publicattribute/get/nonstatic" />
						</xsl:when>
						<xsl:when test="@static='true'">
							<xsl:copy-of select="$config/config/cpp/method/publicattribute/get/static" />
						</xsl:when>
					</xsl:choose>
				</xsl:when>

				<!-- handle public attribute setter -->
				<xsl:when test="$method/@public_attribute_setter eq 'true'">
					<xsl:choose>
						<xsl:when test="@static!='true'">
							<xsl:copy-of select="$config/config/cpp/method/publicattribute/set/nonstatic" />
						</xsl:when>
						<xsl:when test="@static='true'">
							<xsl:copy-of select="$config/config/cpp/method/publicattribute/set/static" />
						</xsl:when>
					</xsl:choose>
				</xsl:when>

				<!-- handle static method without return parameter -->
				<xsl:when
					test="($method/type eq 'void') and ($static eq 'true') ">
					<xsl:copy-of
						select="$config/config/cpp/method/static/void" />
				</xsl:when>

				<!-- handle static method with return parameter -->
				<xsl:when
					test="$static eq 'true'">
					<xsl:copy-of
						select="$config/config/cpp/method/static/return" />
				</xsl:when>

				<!-- handle normal method without return parameter-->
				<xsl:when test="($method/type eq 'void')">
					<xsl:copy-of
						select="$config/config/cpp/method/normal/void" />
				</xsl:when>

				<!-- handle normal method with return parameter-->
				<xsl:when test="($method/type ne 'void')">
					<xsl:copy-of
						select="$config/config/cpp/method/normal/return" />
				</xsl:when>
				
				<!-- handle constructor -->
				<xsl:otherwise>
					<xsl:message terminate="yes">
						unhandled method:
						<xsl:value-of select="$method/definition" />
					</xsl:message>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- real writing of method implementation -->
		<xsl:value-of
			select="xbig:code($config, $code_template, $class, $method)" />


		<!-- end implementation -->
		<xsl:text>&#10;} /*&#32;</xsl:text>
		<xsl:value-of select="definition" />
		<xsl:text>&#32;*/&#10;</xsl:text>

	</xsl:template>


</xsl:stylesheet>
