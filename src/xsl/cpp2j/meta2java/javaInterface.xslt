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
	
	Author: Christoph Nenning
	
-->

<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions"
	xmlns:xdt="http://www.w3.org/2005/xpath-datatypes"
	xmlns:xd="http://www.pnp-software.com/XSLTdoc"
	xmlns:str="http://exslt.org/strings"
	xmlns:xbig="http://xbig.sourceforge.net/XBiG">

	<xsl:import href="javaAccessMethodDeclaration.xslt" />
	<xsl:import href="javaUtil.xslt" />
	<xsl:import href="../../exslt/str.split.template.xsl" />
	<xsl:import href="../../util/metaMethodName.xslt" />
	<xsl:import href="../../util/createFunctionsForPublicAttribute.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>
			Generate an interface for a single original class or struct,
			to handle multiple inheritance
		</xd:short>
	</xd:doc>

	<xsl:template name="javaInterface">
		<xsl:param name="config" />
		<xsl:param name="class" />
		<xsl:param name="buildFile" />

		<!-- shortcut for class name -->
		<xsl:variable name="class_name" select="$class/@name" />

		<!-- find out if we create an inner class -->
		<xsl:variable name="isInnerClass" select="../name() eq 'class' or ../name() eq 'struct'"/>

		<!-- write class declaration -->
		<xsl:text>public </xsl:text>
		<xsl:if test="$isInnerClass">
			<xsl:text>static </xsl:text>
		</xsl:if>
		<xsl:text>interface&#32;</xsl:text>
		<xsl:value-of select="$config/config/java/interface/prefix" />
		<xsl:value-of select="$class/@name" />
		<xsl:value-of select="$config/config/java/interface/suffix" />

		<!-- if this class is a template -->
		<xsl:if test="$class/@template">
			<xsl:text>&#32;&lt;&#32;</xsl:text>
			<xsl:for-each select="$class/templateparameters/templateparameter
								[@templateType = 'class' or @templateType = 'typename']">
				<xsl:value-of select="@templateDeclaration"/>

				<!-- outcommented for primitive types as template parameters -->
				<!-- <xsl:text>&#32;extends&#32;INativeObject</xsl:text> -->

				<xsl:if test="position() != last()">
					<xsl:text>,&#32;</xsl:text>
				</xsl:if>
			</xsl:for-each>
			<xsl:text>&#32;&gt;</xsl:text>
		</xsl:if>

		<xsl:text>&#32;extends&#32;</xsl:text>
		<xsl:text>INativeObject&#32;</xsl:text>

		<!-- extended interfaces -->
		<xsl:if test="inherits/baseClass">
			<xsl:text>,&#32;</xsl:text>
			<xsl:for-each select="inherits/baseClass">

				<!-- configured package -->
				<xsl:value-of select="$config/config/java/namespaces/packageprefix"/>
				<xsl:text>.</xsl:text>

				<!-- all namespaces -->
				<xsl:variable name="baseClassFullNameTokens">
					<xsl:call-template name="str:split">
						<xsl:with-param name="string" select="@fullBaseClassName" />
						<xsl:with-param name="pattern" select="'::'" />
					</xsl:call-template>
				</xsl:variable>
				<xsl:for-each select="$baseClassFullNameTokens/token">
					<xsl:if test="position()!=last()">
						<xsl:value-of select="." />
						<xsl:text>.</xsl:text>
					</xsl:if>
				</xsl:for-each>

				<!-- interface name -->
				<xsl:value-of select="$config/config/java/interface/prefix" />
				<xsl:value-of select="." />
				<xsl:value-of select="$config/config/java/interface/suffix" />

				<!-- if this class is a typedef for a template -->
				<xsl:if test="$class/typeparameters">
					<xsl:value-of select="'&lt; '"/>
					<xsl:for-each select="$class/typeparameters/typepara">
						<xsl:variable name="usedType" select="@used"/>
		
						<xsl:choose>
							<!-- check for primitive types -->
							<xsl:when test="$config/config/java/types/type[@meta = $usedType]">
								<xsl:value-of select="$config/config/java/types/type
													  [@meta = $usedType]/@genericParameter"/>
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of select="xbig:getFullJavaName(@used, $class, $root, $config)"/>
							</xsl:otherwise>
						</xsl:choose>
						<xsl:if test="position()!=last()">
							<xsl:text>, </xsl:text>
						</xsl:if>
					</xsl:for-each>
					<xsl:value-of select="' &gt;'"/>
				</xsl:if>

				<!-- gen commas as seperator between base interfaces -->
				<xsl:if test="position()!=last()">
					<xsl:text>, </xsl:text>
				</xsl:if>

			</xsl:for-each>
		</xsl:if>

		<!-- start interface content -->
		<xsl:text>&#32;{&#10;&#10;</xsl:text>

		<!-- handle inner classes & structs -->
		<xsl:for-each select="class">
			<xsl:call-template name="javaInterface">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="class" select="." />
				<xsl:with-param name="buildFile" select="$buildFile" />
			</xsl:call-template>
		</xsl:for-each>
		<xsl:for-each select="struct">
			<xsl:call-template name="javaInterface">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="class" select="." />
				<xsl:with-param name="buildFile" select="$buildFile" />
			</xsl:call-template>
		</xsl:for-each>

		<!-- check if we have to generate a class for a typedef -->
		<xsl:for-each select="typedef">
			<xsl:if test="contains(./@basetype, '&lt;')">
				<xsl:variable name="templateBaseName"
						select="normalize-space(substring-before(./@basetype, '&lt;'))"/>
				<xsl:variable name="fullTemplateBaseName"
						select="xbig:getFullTypeName($templateBaseName, ., $root)"/>
				<xsl:variable name="templateNode" select="$root//*[@fullName = $fullTemplateBaseName]"/>
				<xsl:variable name="generatedClass">
					<xsl:call-template name="createClassFromTemplateTypedef">
						<xsl:with-param name="template" select="$templateNode"/>
						<xsl:with-param name="typedef" select="."/>
						<xsl:with-param name="isInnerClass" select="true()"/>
					</xsl:call-template>
				</xsl:variable>

				<!-- generate the class -->
				<xsl:for-each select="$generatedClass/*">
					<xsl:call-template name="javaInterface">
						<xsl:with-param name="config" select="$config" />
						<xsl:with-param name="class" select="." />
						<xsl:with-param name="buildFile" select="$buildFile" />
					</xsl:call-template>
				</xsl:for-each>
			</xsl:if>
		</xsl:for-each>

		<xsl:variable name="methodsForJava">
			<xsl:call-template name="getValidMethodList">
				<xsl:with-param name="functionNodeList" select="."/>
			</xsl:call-template>
		</xsl:variable>
		
		<!-- handling of member functions -->
		<xsl:for-each select="$methodsForJava/function">

			<!-- change method name if const overloading is used -->
			<xsl:variable name="methodContainer">
				<xsl:choose>
					<xsl:when test="(count($methodsForJava/function[name = current()/name]) > 1) and @const='true'">
						<xsl:call-template name="createElementForConstOverloadedMethod">
							<xsl:with-param name="config" select="$config" />
							<xsl:with-param name="method" select="." />
						</xsl:call-template>
					</xsl:when>
					<xsl:otherwise>
						<xsl:copy-of select="." />
					</xsl:otherwise>
				</xsl:choose>
			</xsl:variable>

			<!-- interfaces cannot have consructors or static methods -->
			<xsl:if test="name!=$class/@name and @static!='true'">
				<xsl:call-template name="javaAccessMethodDeclaration">
					<xsl:with-param name="config" select="$config" />
					<xsl:with-param name="class" select="$class" />
					<xsl:with-param name="method" select="$methodContainer/function" />
				</xsl:call-template>

				<!-- finish declaration -->
				<xsl:text>;&#10;&#10;</xsl:text>
			</xsl:if>
		</xsl:for-each>

		<!-- handling of public attributes -->
		<xsl:for-each select="variable">
			<xsl:if test="@static != 'true'">
				<xsl:variable name="publicAttributeGettersAndSetters">
					<xsl:call-template name="createFunctionsForPublicAttribute">
						<xsl:with-param name="variable" select="."/>
					</xsl:call-template>
				</xsl:variable>

				<xsl:for-each select="$publicAttributeGettersAndSetters/function">
					<xsl:call-template name="javaAccessMethodDeclaration">
						<xsl:with-param name="config" select="$config" />
						<xsl:with-param name="class" select="$class" />
						<xsl:with-param name="method" select="." />
					</xsl:call-template>

					<!-- finish declaration -->
					<xsl:text>;&#10;&#10;</xsl:text>
				</xsl:for-each>
			</xsl:if>
		</xsl:for-each>


		<!-- close class declaration  -->
		<xsl:text>};&#10;</xsl:text>

	</xsl:template>

</xsl:stylesheet>
