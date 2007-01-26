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

	<xsl:import href="../../util/metaTypeInfo.xslt" />
	<xsl:import href="../../util/firstLetterToUpperCase.xslt" />
	<xsl:import href="../../exslt/str.split.template.xsl" />

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single type</xd:short>
	</xd:doc>

	<xsl:template name="javaType">
		<xsl:param name="config" />
		<xsl:param name="param" />
		<xsl:param name="class" />
		<xsl:param name="writingNativeMethod" />
		<xsl:param name="typeName" />

		<!-- if this type is a parametrized template -->
		<xsl:variable name="typeIsTemplate">
			<xsl:choose>
				<xsl:when test="contains($typeName, '&lt;')">
					<xsl:value-of select="true()"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="false()"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>
		<xsl:variable name="templateBaseType">
			<xsl:choose>
				<xsl:when test="$typeIsTemplate = true()">
					<xsl:value-of select="substring-before($typeName, '&lt;')"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="$typeName"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>
		<xsl:variable name="templateBracket">
			<xsl:choose>
				<xsl:when test="$typeIsTemplate = true()">
					<!-- resolve types of template parameters -->
					<xsl:variable name="bracket" select="substring-after($typeName, '&lt;')"/>
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
							<xsl:call-template name="javaType">
								<xsl:with-param name="config" select="$config" />
								<xsl:with-param name="param" select="$param" />
								<xsl:with-param name="class" select="$class" />
								<xsl:with-param name="typeName" select="normalize-space(.)"/>
							</xsl:call-template>
							<xsl:if test="position() != last()">
								<xsl:value-of select="', '"/>
							</xsl:if>
						</xsl:for-each>
					</xsl:variable>
					<xsl:value-of select="concat('&lt; ', $insideBracketResolved, ' &gt;')"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="''"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- resolve typedefs -->
		<xsl:variable name="resolvedType" select="xbig:resolveTypedef($templateBaseType, $class, $root)"/>

		<!-- extract jni type depending on meta type, const/non-const, pass type -->
		<xsl:variable name="type_info">
			<xsl:call-template name="metaFirstTypeInfo">
				<xsl:with-param name="root" 
					select="$config/config/java/types" />
				<xsl:with-param name="param" select="$param" />
				<xsl:with-param name="typeName" select="$resolvedType" />
			</xsl:call-template>
		</xsl:variable>

		<!-- print first type found in result list -->
		<xsl:choose>

			<!-- write pointer class -->
			<xsl:when test="($param/@passedBy='pointer' or $param/@passedBy='reference')
							and ($writingNativeMethod ne 'true')
							and $type_info/type/@java">
				<xsl:call-template name="javaPointerClass">
					<xsl:with-param name="config" select="$config" />
					<xsl:with-param name="param" select="$param" />
					<xsl:with-param name="typeName" select="$resolvedType" />
				</xsl:call-template>
			</xsl:when>

			<!-- if no type info is found -> we are dealing with a class / enum / ... -->
			<xsl:when test="not($type_info/type/@java)">
				<xsl:choose>

					<!-- template parameter used as method parameter or return type -->
					<xsl:when test="$class/templateparameters/templateparameter
									[@templateType='class' or @templateType='typename']
									[@templateDeclaration = $resolvedType]">
						<xsl:choose>
							<xsl:when test="$writingNativeMethod eq 'true'">
								<xsl:value-of select="'long'"/>
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of select="$resolvedType"/>
							</xsl:otherwise>
						</xsl:choose>
					</xsl:when>

					<!-- if this type is a template typedef -->
					<xsl:when test="xbig:isTemplateTypedef($resolvedType, $class, $root)">
						<xsl:choose>
							<xsl:when test="$writingNativeMethod eq 'true'">
								<xsl:value-of select="'long'"/>
							</xsl:when>
							<xsl:otherwise>
								<!-- add the template angle bracket -->
								<xsl:value-of select="concat(xbig:getFullJavaName($resolvedType, $class, $root, $config), $templateBracket)"/>
							</xsl:otherwise>
						</xsl:choose>
					</xsl:when>

					<!-- if this type is an enum -->
					<xsl:when test="xbig:isEnum($resolvedType, $class, $root)">
						<xsl:choose>
							<xsl:when test="$writingNativeMethod eq 'true'">
								<xsl:value-of select="'int'"/>
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of select="xbig:getFullJavaName($resolvedType, $class, $root, $config)"/>
							</xsl:otherwise>
						</xsl:choose>
					</xsl:when>

					<!-- if this type is a class or struct -->
					<xsl:when test="xbig:isClassOrStruct($resolvedType, $class, $root)">
						<xsl:choose>
							<xsl:when test="$writingNativeMethod eq 'true'">
								<xsl:value-of select="'long'"/>
							</xsl:when>
							<xsl:otherwise>
								<!-- add the template angle bracket -->
								<xsl:value-of select="concat(xbig:getFullJavaName($resolvedType, $class, $root, $config), $templateBracket)"/>
							</xsl:otherwise>
						</xsl:choose>
					</xsl:when>

					<xsl:otherwise>
						<xsl:value-of select="xbig:getFullJavaName($resolvedType, $class, $root, $config)"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>

			<!-- types in config (usually primitive types) -->
			<xsl:otherwise>
				<xsl:value-of select="$type_info/type/@java" />
			</xsl:otherwise>
		</xsl:choose>

	</xsl:template>


	<xsl:template name="javaPointerClass">
		<xsl:param name="config" />
		<xsl:param name="param" />
		<xsl:param name="typeName" />

		<!-- extract jni type depending on meta type, const/non-const, pass type -->
		<xsl:variable name="type_info">
			<xsl:call-template name="metaFirstTypeInfo">
				<xsl:with-param name="root" 
					select="$config/config/java/types" />
				<xsl:with-param name="param" select="$param" />
				<xsl:with-param name="typeName" select="$typeName" />
			</xsl:call-template>
		</xsl:variable>

		<xsl:choose>
			<xsl:when test="$typeName ne 'int'">
				<xsl:value-of>
					<xsl:call-template name="firstLetterToUpperCase">
						<xsl:with-param name="name">
							<xsl:choose>
								<xsl:when test="contains($type_info/type/@java, ' ')">
									<xsl:value-of select="substring-after($type_info/type/@java, ' ')" />
								</xsl:when>
								<xsl:otherwise>
									<xsl:value-of select="$type_info/type/@java" />
								</xsl:otherwise>
							</xsl:choose>
						</xsl:with-param>
					</xsl:call-template>
					<xsl:value-of select="'Pointer'" />
				</xsl:value-of>
			</xsl:when>

			<!-- IntegerPointer is a special name -->
			<xsl:when test="$typeName eq 'int'">
				<xsl:value-of select="'IntegerPointer'" />
			</xsl:when>
		</xsl:choose>

	</xsl:template>



	<xd:doc type="function">
		<xd:short>resolve the full java name of a type, including the package</xd:short>
	</xd:doc>
	<xsl:function name="xbig:getFullJavaName" as="xs:string">
		<xsl:param name="type" as="xs:string"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>
		<xsl:param name="config"/>

		<!-- get full meta / c++ name -->
		<xsl:variable name="fullNameAsReturned" select="xbig:getFullTypeName($type, $currentNode, $inputTreeRoot)"/>

		<!-- add java specific stuff to class name -->
		<xsl:variable name="fullName">
			<xsl:variable name="fullNameTokens">
				<xsl:call-template name="str:split">
					<xsl:with-param name="string" select="$fullNameAsReturned" />
					<xsl:with-param name="pattern" select="'::'" />
				</xsl:call-template>
			</xsl:variable>

			<xsl:choose>
				<!-- Use generated Interface for classes and structs,
					 for template typedefs as well -->
				<xsl:when test="xbig:isClassOrStruct($fullNameAsReturned, $currentNode, $inputTreeRoot) or
								xbig:isTemplateTypedef($fullNameAsReturned, $currentNode, $inputTreeRoot)">
					<xsl:for-each select="$fullNameTokens/token">
						<xsl:if test="position() = last()">
							<xsl:value-of select="$config/config/java/interface/prefix" />
						</xsl:if>
						<xsl:value-of select="." />
						<xsl:choose>
							<xsl:when test="position() = last()">
								<xsl:value-of select="$config/config/java/interface/suffix" />
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of select="'::'" />
							</xsl:otherwise>
						</xsl:choose>
					</xsl:for-each>
				</xsl:when>

				<xsl:otherwise>
					<xsl:value-of select="$fullNameAsReturned"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<xsl:variable name="nsPrefix" select="$config/config/java/namespaces/packageprefix"/>
		<xsl:variable name="fullNameWithDots" select="replace($fullName, '::', '.')"/>
		<xsl:value-of select="concat($nsPrefix, '.', $fullNameWithDots)"/>

	</xsl:function>


	<xd:doc type="function">
		<xd:short>resolve the full java name of a type, including the package but not of it's interface</xd:short>
	</xd:doc>
	<xsl:function name="xbig:getFullJavaClassAndNotInterfaceName" as="xs:string">
		<xsl:param name="type" as="xs:string"/>
		<xsl:param name="currentNode"/> <!-- must be a class, struct or namespace element -->
		<xsl:param name="inputTreeRoot"/>
		<xsl:param name="config"/>

		<!-- get full meta / c++ name -->
		<xsl:variable name="fullName" select="xbig:getFullTypeName($type, $currentNode, $inputTreeRoot)"/>

		<xsl:variable name="nsPrefix" select="$config/config/java/namespaces/packageprefix"/>
		<xsl:variable name="fullNameWithDots" select="replace($fullName, '::', '.')"/>
		<xsl:value-of select="concat($nsPrefix, '.', $fullNameWithDots)"/>

	</xsl:function>



</xsl:stylesheet>
