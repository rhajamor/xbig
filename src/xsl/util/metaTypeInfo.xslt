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
	xmlns:xbig="http://xbig.sourceforge.net/XBiG"
	xmlns:str="http://exslt.org/strings">

	<xsl:import href="../exslt/str.split.template.xsl" />

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single type</xd:short>
	</xd:doc>

	<xsl:template name="metaTypeInfo">
		<xsl:param name="root" />
		<xsl:param name="param" />
		<xsl:param name="typeName" />

		<!-- shortcut for meta type -->
		<xsl:variable name="meta_type"
			select="if($typeName) then $typeName else 'long'" />

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
		<xsl:param name="typeName" />

		<!-- calculate all suitable type informations -->
		<xsl:variable name="type_infos">
			<xsl:call-template name="metaTypeInfo">
				<xsl:with-param name="root" select="$root" />
				<xsl:with-param name="param" select="$param" />
				<xsl:with-param name="typeName" select="$typeName" />
			</xsl:call-template>
		</xsl:variable>

		<!-- ensure valid signature -->
		<xsl:if test="count($type_infos) = 0">
			<xsl:message terminate="yes">
				ERROR: no type info for meta type '
				<xsl:value-of select="$typeName" />
				' found.
			</xsl:message>
		</xsl:if>

		<!-- take first type info-->
		<xsl:copy-of select="$type_infos/types/type[1]" />

	</xsl:template>

	<xsl:template name="metaExactTypeInfo">
		<xsl:param name="root" />
		<xsl:param name="param" />
		<xsl:param name="typeName" />

		<!-- calculate all suitable type informations -->
		<xsl:variable name="type_infos">
			<xsl:call-template name="metaTypeInfo">
				<xsl:with-param name="root" select="$root" />
				<xsl:with-param name="param" select="$param" />
				<xsl:with-param name="typeName" select="$typeName" />
			</xsl:call-template>
		</xsl:variable>

		<!-- ensure valid signature -->
		<xsl:if test="count($type_infos) = 0">
			<xsl:message terminate="yes">
				ERROR: no type info for meta type '
				<xsl:value-of select="$typeName" />
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



	<xd:doc type="function">
		<xd:short>check if a type is an enum</xd:short>
	</xd:doc>
	<xsl:function name="xbig:isEnum" as="xs:boolean">
		<xsl:param name="type"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>

		<!-- for performance reasons -->
		<!-- 
		<xsl:variable name="fullName" select="xbig:getFullTypeName($type, $currentNode, $inputTreeRoot)"/>
		 -->
		<xsl:variable name="fullName" select="$type"/>

		<xsl:choose>
			<xsl:when test="boolean($inputTreeRoot//enumeration[@fullName = $fullName])">
				<xsl:value-of select="true()" />
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="false()" />
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>


	<xd:doc type="function">
		<xd:short>check if a type is a typedef</xd:short>
	</xd:doc>
	<xsl:function name="xbig:isTypedef" as="xs:boolean">
		<xsl:param name="type"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>

		<!-- for performance reasons -->
		<!-- 
		<xsl:variable name="fullName" select="xbig:getFullTypeName($type, $currentNode, $inputTreeRoot)"/>
		 -->
		<xsl:variable name="fullName" select="$type"/>

		<xsl:choose>
			<xsl:when test="boolean($inputTreeRoot//typedef[@fullName = $fullName])">
				<xsl:value-of select="true()" />
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="false()" />
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>


	<xd:doc type="function">
		<xd:short>check if a type is a class</xd:short>
	</xd:doc>
	<xsl:function name="xbig:isClass" as="xs:boolean">
		<xsl:param name="type"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>

		<!-- for performance reasons -->
		<!-- 
		<xsl:variable name="fullName" select="xbig:getFullTypeName($type, $currentNode, $inputTreeRoot)"/>
		 -->
		<xsl:variable name="fullName" select="$type"/>

		<xsl:choose>
			<xsl:when test="boolean($inputTreeRoot//class[@fullName = $fullName])">
				<xsl:value-of select="true()" />
			</xsl:when>

			<!-- typedef for template with inner class -->
			<xsl:when test="boolean($currentNode/typeparameters)">
				<!-- TODO make this general, to handle multiple levels of inner inner classes -->
				<xsl:variable name="originalTemplateNode">
					<xsl:copy-of select="$inputTreeRoot//*
												[@fullName = $currentNode/@originalTemplateFullName]"/>
				</xsl:variable>
				<xsl:choose>
					<xsl:when test="boolean($originalTemplateNode/*/@name = substring-after($type, '::'))">
						<xsl:value-of select="true()" />
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="false()" />
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>

			<xsl:otherwise>
				<xsl:value-of select="false()" />
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>


	<xd:doc type="function">
		<xd:short>check if a type is a struct</xd:short>
	</xd:doc>
	<xsl:function name="xbig:isStruct" as="xs:boolean">
		<xsl:param name="type"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>

		<!-- for performance reasons -->
		<!-- 
		<xsl:variable name="fullName" select="xbig:getFullTypeName($type, $currentNode, $inputTreeRoot)"/>
		 -->
		<xsl:variable name="fullName" select="$type"/>

		<xsl:choose>
			<xsl:when test="boolean($inputTreeRoot//struct[@fullName = $fullName])">
				<xsl:value-of select="true()" />
			</xsl:when>

			<!-- typedef for template with inner class -->
			<xsl:when test="boolean($currentNode/typeparameters)">
				<!-- TODO make this general, to handle multiple levels of inner inner classes -->
				<xsl:variable name="originalTemplateNode">
					<xsl:copy-of select="$inputTreeRoot//*
												[@fullName = $currentNode/@originalTemplateFullName]"/>
				</xsl:variable>
				<xsl:choose>
					<xsl:when test="boolean($originalTemplateNode/*/@name = substring-after($type, '::'))">
						<xsl:value-of select="true()" />
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="false()" />
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>

			<xsl:otherwise>
				<xsl:value-of select="false()" />
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>


	<xd:doc type="function">
		<xd:short>check if a type is a class or a struct</xd:short>
	</xd:doc>
	<xsl:function name="xbig:isClassOrStruct" as="xs:boolean">
		<xsl:param name="type"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>

		<!-- for performance reasons -->
		<!-- 
		<xsl:variable name="fullName" select="xbig:getFullTypeName($type, $currentNode, $inputTreeRoot)"/>
		 -->
		<xsl:variable name="fullName" select="$type"/>

		<xsl:choose>
			<xsl:when test="boolean($inputTreeRoot//class[@fullName = $fullName])">
				<xsl:value-of select="true()" />
			</xsl:when>
			<xsl:when test="boolean($inputTreeRoot//struct[@fullName = $fullName])">
				<xsl:value-of select="true()" />
			</xsl:when>

			<!-- typedef for template with inner class -->
			<xsl:when test="boolean($currentNode/typeparameters)">
				<!-- TODO make this general, to handle multiple levels of inner inner classes -->
				<xsl:variable name="originalTemplateNode">
					<xsl:copy-of select="$inputTreeRoot//*
												[@fullName = $currentNode/@originalTemplateFullName]"/>
				</xsl:variable>
				<xsl:choose>
					<xsl:when test="boolean($originalTemplateNode/*/@name = substring-after($type, '::'))">
						<xsl:value-of select="true()" />
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="false()" />
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>

			<xsl:otherwise>
				<xsl:value-of select="false()" />
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>


	<xd:doc type="function">
		<xd:short>check if a type is a typedef for a template</xd:short>
	</xd:doc>
	<xsl:function name="xbig:isTemplateTypedef" as="xs:boolean">
		<xsl:param name="type"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>

		<!-- for performance reasons -->
		<!-- 
		<xsl:variable name="fullName" select="xbig:getFullTypeName($type, $currentNode, $inputTreeRoot)"/>
		 -->
		<xsl:variable name="fullName" select="$type"/>
		<xsl:variable name="typedefNode" select="$inputTreeRoot//typedef[@fullName = $fullName]"/>

		<xsl:choose>
			<xsl:when test="contains($typedefNode/@basetype, '&lt;')">
				<xsl:value-of select="true()" />
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="false()" />
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>


	<xd:doc type="function">
		<xd:short>resolve the full c++ name of a type, including the namespace</xd:short>
	</xd:doc>
	<xsl:function name="xbig:getFullTypeName" as="xs:string">
		<xsl:param name="type" as="xs:string"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>

		<xsl:choose>

			<!-- if the type contains a namespace -->
			<xsl:when test="contains($type, '::')">
				<xsl:choose>

					<!-- if we have an absolute namespace path -->
					<xsl:when test="starts-with($type, '::')">
						<xsl:value-of select="substring-after($type, '::')"/>
					</xsl:when>

					<!-- namespace path could be absolute or relative -->
					<xsl:otherwise>
						<xsl:variable name="relPathFirstPart" select="substring-before($type, '::')"/>
						<xsl:variable name="typeContainingNodeName" 
									  select="xbig:getNodeNameWhichContainsType
									  ($relPathFirstPart, $currentNode, $inputTreeRoot)"/>
						<xsl:variable name="typeContainingNodeDots">
							<xsl:choose>
								<xsl:when test="$typeContainingNodeName != ''">
									<xsl:value-of select="concat($typeContainingNodeName, '::')"/>
								</xsl:when>
								<xsl:otherwise>
									<xsl:value-of select="$typeContainingNodeName"/>
								</xsl:otherwise>
							</xsl:choose>
						</xsl:variable>
						<xsl:value-of select="concat($typeContainingNodeDots, $type)"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>

			<!-- type does not contain a namespace -->
			<xsl:otherwise>
				<xsl:variable name="typeContainingNodeName" 
							  select="xbig:getNodeNameWhichContainsType
							  ($type, $currentNode, $inputTreeRoot)" />
				<xsl:choose>
					<xsl:when test="$typeContainingNodeName = ''">
						<xsl:value-of select="$type"/>
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="concat($typeContainingNodeName, '::', $type)"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>


	<xd:doc type="function">
		<xd:short>find the namespace / class / struct in which a type is declared</xd:short>
	</xd:doc>
	<xsl:function name="xbig:getNodeNameWhichContainsType" as="xs:string">
		<xsl:param name="type" as="xs:string"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>

		<xsl:choose>

			<!-- to avoid a live lock -->
			<xsl:when test="not($currentNode/..)">
				<xsl:value-of select="''" />
			</xsl:when>

			<!-- if found, return node -->
			<xsl:when test="$currentNode/*[@name = $type]">
				<xsl:value-of select="$currentNode/@fullName" />
			</xsl:when>

			<!-- special case: a typedef for a template -> generated meta class -> not in input tree -->
			<xsl:when test="$currentNode/typeparameters">
				<!-- TODO check if this could be made more general -->
				<xsl:variable name="originalTypedefNode" select="$inputTreeRoot//*
												[@fullName = $currentNode/@originalTypedefFullName]"/>
				<xsl:choose>
					<!-- if found, return node -->
					<xsl:when test="$originalTypedefNode/*[@name = $type]">
						<xsl:value-of select="$originalTypedefNode/@fullName" />
					</xsl:when>
					<!-- else check the parent node -->
					<xsl:otherwise>
						<xsl:value-of select="xbig:getNodeNameWhichContainsType
											  ($type, $originalTypedefNode/.., $inputTreeRoot)" />
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>

			<!-- else if the current node is the root return an empty string -->
			<xsl:when test="$inputTreeRoot is $currentNode">
				<xsl:sequence select="''" />
			</xsl:when>

			<!-- else check the parent node -->
			<xsl:otherwise>
				<xsl:value-of select="xbig:getNodeNameWhichContainsType
									  ($type, $currentNode/.., $inputTreeRoot)" />
			</xsl:otherwise>
		</xsl:choose>

	</xsl:function>


	<xd:doc type="function">
		<xd:short>Resolves a typedef.
		It finds out full name of passed type and returns full name of resolved type</xd:short>
	</xd:doc>
	<xsl:function name="xbig:resolveTypedef" as="xs:string">
		<xsl:param name="type" as="xs:string"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>

		<xsl:variable name="fullName" select="xbig:getFullTypeName($type, $currentNode, $inputTreeRoot)"/>
		<!-- 
		<xsl:variable name="fullName" select="$type"/>
		 -->

		<xsl:choose>
			<xsl:when test="xbig:isTypedef($fullName, $currentNode, $inputTreeRoot)">
				<xsl:variable name="typedefNode" select="$inputTreeRoot//typedef[@fullName = $fullName]"/>
				<xsl:choose>

					<!-- if this is a typedef for a template, there is a class -->
					<xsl:when test="contains($typedefNode/@basetype, '&lt;')">
						<!-- <xsl:value-of select="xbig:getFullTypeName(
										$typedefNode/@basetype, $typedefNode/.., $inputTreeRoot)"/> -->
						<xsl:value-of select="$fullName"/>
					</xsl:when>

					<xsl:otherwise>
						<xsl:value-of select="xbig:resolveTypedef(
										$typedefNode/@basetype, $typedefNode/.., $inputTreeRoot)"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>
			<xsl:otherwise>
				<!-- 
				<xsl:value-of select="$type"/>
				 -->
				<xsl:value-of select="$fullName"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>


	<xd:doc type="function">
		<xd:short>find full name of a template and for all of it's parameters</xd:short>
	</xd:doc>
	<xsl:function name="xbig:getFullTemplateName" as="xs:string">
		<xsl:param name="type" as="xs:string"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>

		<!-- get fullname of the template itself (the A in A<B>) -->
		<xsl:variable name="templateBaseType">
			<xsl:value-of select="xbig:getFullTypeName(normalize-space(substring-before($type, '&lt;'))
									, $currentNode, $inputTreeRoot)"/>
		</xsl:variable>

		<!-- handle the type parameters -->
		<xsl:variable name="templateBracket">
			<xsl:variable name="bracket" select="substring-after($type, '&lt;')"/>
			<xsl:variable name="insideBracket"
				select="normalize-space(substring($bracket, 0, string-length($bracket)-1))"/>

			<xsl:variable name="insideBracketResolved">
				<xsl:variable name="tokens">
					<xsl:call-template name="str:split">
						<xsl:with-param name="string" select="$insideBracket" />
						<xsl:with-param name="pattern" select="','" />
					</xsl:call-template>
				</xsl:variable>
				<xsl:for-each select="$tokens/*">
					<xsl:variable name="normalizedToken" select="normalize-space(.)"/>
					<xsl:choose>
						<xsl:when test="contains(., '&lt;')">
							<xsl:value-of select="xbig:getFullTemplateName(
										$normalizedToken, $currentNode, $inputTreeRoot)"/>
						</xsl:when>
						<xsl:otherwise>
							<xsl:value-of select="xbig:getFullTypeName(xbig:resolveTypedef(
										$normalizedToken, $currentNode, $inputTreeRoot)
										, $currentNode, $inputTreeRoot)"/>
						</xsl:otherwise>
					</xsl:choose>

					<xsl:if test="position() != last()">
						<xsl:value-of select="', '"/>
					</xsl:if>
				</xsl:for-each>
			</xsl:variable>
			<xsl:value-of select="concat('&lt; ', $insideBracketResolved, ' &gt;')"/>
		</xsl:variable>

		<!-- return -->
		<xsl:value-of select="concat($templateBaseType, $templateBracket)"/>
	</xsl:function>


</xsl:stylesheet>
