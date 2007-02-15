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

		<!-- create interface name -->
		<xsl:variable name="interfaceName">
			<xsl:value-of select="$config/config/java/interface/prefix"/>
			<xsl:value-of select="$class/@name"/>
			<xsl:value-of select="$config/config/java/interface/suffix"/>
		</xsl:variable>

		<!-- write class declaration -->
		<xsl:text>public </xsl:text>
		<xsl:if test="$isInnerClass">
			<xsl:text>static </xsl:text>
		</xsl:if>
		<xsl:text>interface&#32;</xsl:text>
		<xsl:value-of select="$interfaceName"/>

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

		<!-- all generated interfaces must be INativeObjects -->
		<xsl:text>&#32;extends&#32;</xsl:text>
		<xsl:text>INativeObject</xsl:text>

		<!-- extended interfaces -->
		<xsl:if test="inherits/baseClass">
			<xsl:text>,&#32;</xsl:text>
			<xsl:for-each select="inherits/baseClass">

				<!-- find and print java name of baseclass -->
				<!-- TODO we need something like getFullJavaNameForTemplate() -->
				<!-- TODO handle pointers as template parameters -->
				<!-- TODO check what happens if there is a typedef for a template which inherits something -->
				<xsl:variable name="baseClassJavaName">
					<xsl:choose>
						<xsl:when test="contains(./@fullBaseClassName, '&lt;')">
							<!-- generate a meta parameter element for type parameter -->
							<xsl:variable name="generatedParam">
								<xsl:element name="param">
									<xsl:attribute name="passedBy" select="'value'"/>
									<xsl:element name="type">
										<xsl:value-of select="./@fullBaseClassName"/>
									</xsl:element>
								</xsl:element>
							</xsl:variable>
							
							<xsl:call-template name="javaType">
								<xsl:with-param name="config" select="$config"/>
								<xsl:with-param name="param" select="$generatedParam/*"/>
								<xsl:with-param name="class" select="$class"/>
								<xsl:with-param name="typeName" select="./@fullBaseClassName"/>
							</xsl:call-template>
						</xsl:when>
						<xsl:otherwise>
							<xsl:value-of select="xbig:getFullJavaName(
													./@fullBaseClassName, $class, $root, $config)"/>
						</xsl:otherwise>
					</xsl:choose>
				</xsl:variable>
				<xsl:value-of select="$baseClassJavaName"/>

				<!-- if this class is a typedef for a template, we have to use type parameters -->
				<xsl:if test="$class/typeparameters">
					<xsl:value-of select="'&lt; '"/>
					<xsl:for-each select="$class/typeparameters/typepara">

						<!-- find out which type is used as parameter in typedef -->
						<xsl:variable name="typeWithoutPass">
							<xsl:choose>
								<xsl:when test="contains(@used, '*')">
									<xsl:value-of select="normalize-space(substring-before(@used, '*'))"/>
								</xsl:when>
								<xsl:when test="contains(@used, '&amp;')">
									<xsl:value-of select="substring-before(@used, '&amp;')"/>
								</xsl:when>
								<xsl:otherwise>
									<xsl:value-of select="@used"/>
								</xsl:otherwise>
							</xsl:choose>
						</xsl:variable>

						<!-- remove global namespace prefix -->
						<xsl:variable name="typeWithoutNSprefix">
							<xsl:choose>
								<xsl:when test="starts-with($typeWithoutPass, '::')">
									<xsl:value-of select="substring-after($typeWithoutPass, '::')"/>
								</xsl:when>
								<xsl:otherwise>
									<xsl:value-of select="$typeWithoutPass"/>
								</xsl:otherwise>
							</xsl:choose>
						</xsl:variable>

						<!-- resolve typedefs -->
						<xsl:variable name="resolvedType" select="xbig:resolveTypedef(
												$typeWithoutNSprefix, $class, $root)"/>

						<!-- for performance reasons -->
						<xsl:variable name="usedType"
									select="xbig:getFullTypeName($resolvedType, $class, $root)"/>

						<!-- find out how a parameter is passed in typedef -->
						<xsl:variable name="usedPassedBy">
							<xsl:choose>
								<xsl:when test="contains(@used, '*')">
									<xsl:value-of select="'pointer'"/>
								</xsl:when>
								<xsl:when test="contains(@used, '&amp;')">
									<xsl:value-of select="'reference'"/>
								</xsl:when>
								<xsl:otherwise>
									<xsl:value-of select="'value'"/>
								</xsl:otherwise>
							</xsl:choose>
						</xsl:variable>

						<!-- generate a meta parameter element for type parameter -->
						<xsl:variable name="generatedParam">
							<xsl:element name="param">
								<xsl:attribute name="passedBy" select="$usedPassedBy"/>
								<xsl:element name="type">
									<xsl:value-of select="$usedType"/>
								</xsl:element>
							</xsl:element>
						</xsl:variable>

						<!-- write java type to result document -->
						<xsl:choose>
							<!-- check for primitive types -->
							<xsl:when test="$config/config/java/types/type[@meta = $usedType]">
								<xsl:choose>
									<xsl:when test="$usedPassedBy = 'value'">
										<xsl:value-of select="$config/config/java/types/type
													  [@meta = $usedType]/@genericParameter"/>
									</xsl:when>
									<xsl:otherwise>
										<xsl:call-template name="javaPointerClass">
											<xsl:with-param name="config" select="$class"/>
											<xsl:with-param name="param" select="$generatedParam/*"/>
											<xsl:with-param name="typeName" select="$usedType"/>
										</xsl:call-template>
									</xsl:otherwise>
								</xsl:choose>
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of select="xbig:getFullJavaName(
														$usedType, $class, $root, $config)"/>
							</xsl:otherwise>
						</xsl:choose>

						<!-- comma for more than one type parameter -->
						<xsl:if test="position()!=last()">
							<xsl:text>, </xsl:text>
						</xsl:if>
					</xsl:for-each>
					<xsl:value-of select="' &gt;'"/>
				</xsl:if> <!-- type parameters for typedefs for templates -->

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

		<!-- As there are problems with interfaces for templates, they don't get any methods -->
		<xsl:if test="not($class/@template)">

			<!-- handling of member functions -->
			<xsl:for-each select="$methodsForJava/function">
				<xsl:variable name="currentMethod" select="."/>
	 			<xsl:variable name="currentMethodPos" select="position()"/>

				<!-- change method name if const overloading is used -->
				<xsl:variable name="methodContainer">
					<xsl:choose>
						<xsl:when test="(count(../function[name = $currentMethod/name]) > 1)">
							<!-- check for each method with the same name if it is equal -->
							<xsl:variable name="equalSiblings">
								<xsl:for-each select="../function[name = $currentMethod/name]">
									<!-- here I use the trick with count() and the union operator (|) to test a node's identity -->
									<xsl:if test="count(. | $currentMethod) != 1">
										<xsl:element name="check">
											<xsl:choose>
												<xsl:when test="xbig:areTheseMethodsEqualExceptConst($currentMethod, .,false())">
													<xsl:value-of select="true()" />
												</xsl:when>
												<xsl:otherwise>
													<xsl:value-of select="false()" />
												</xsl:otherwise>
											</xsl:choose>
										</xsl:element>
									</xsl:if>
								</xsl:for-each>
							</xsl:variable>

							<!-- check constness of methods with same name -->
							<xsl:choose>
								<xsl:when test="$equalSiblings/* = true()">
									<xsl:choose>
										<!-- change the name of the const version -->
										<xsl:when test="./@const = 'true'">
											<xsl:call-template name="createElementForConstOverloadedMethod">
												<xsl:with-param name="config" select="$config" />
												<xsl:with-param name="method" select="." />
											</xsl:call-template>
										</xsl:when>
		
										<!-- copy the not const version -->
										<xsl:otherwise>
											<xsl:copy-of select="." />
										</xsl:otherwise>
									</xsl:choose>
								</xsl:when>

								<!-- other method with same name but other parameters -->
								<xsl:otherwise>
									<xsl:copy-of select="." />
								</xsl:otherwise>
							</xsl:choose>
						</xsl:when>

						<!-- no const overloading for this method -->
						<xsl:otherwise>
							<xsl:copy-of select="." />
						</xsl:otherwise>
					</xsl:choose>
				</xsl:variable>

				<!-- interfaces cannot have consructors or static methods
					 we also don't want operators -->
				<xsl:if test="name!=$class/@name and @static!='true' and not(starts-with(name, 'operator'))">
					<xsl:call-template name="javaAccessMethodDeclaration">
						<xsl:with-param name="config" select="$config"/>
						<xsl:with-param name="class" select="$class"/>
						<xsl:with-param name="method" select="$methodContainer/function"/>
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
		</xsl:if>

		<!-- generate comment for templates -->
		<xsl:if test="$class/@template">
			<xsl:text>// interfaces for templates do not get any methods&#10;</xsl:text>
		</xsl:if>

		<!-- close class declaration  -->
		<xsl:text>};&#10;</xsl:text>

	</xsl:template>

</xsl:stylesheet>
