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
	xmlns:xbig="http://xbig.sourceforge.net/XBiG"
	xmlns:str="http://exslt.org/strings">


	<xsl:import href="../util/createMetaParameterElement.xslt" />
	<xsl:import href="../exslt/str.split.template.xsl" />


	<xd:doc type="stylesheet">
		<xd:short>Templates to handle C++ Templates.</xd:short>
	</xd:doc>

	<xd:doc type="template">
		<xd:short>
			Generates a meta class. As long as we do not know type
			parameters of a C++ template We can only generate java
			interfaces. But when there is a typedef we know the types
			and are able to generate a java class. Therefore we need a
			meta class first.
		</xd:short>
		<xd:param name="template">template which is used.</xd:param>
		<xd:param name="typedef">
			typedef which uses a template.
		</xd:param>
		<xd:param name="isInnerClass">
			Whether the generated class is an inner class or not.
		</xd:param>
	</xd:doc>
	<xsl:template name="createClassFromTemplateTypedef">
		<xsl:param name="template" />
		<xsl:param name="typedef" />
		<xsl:param name="isInnerClass" as="xs:boolean" />

		<!-- build list of type parameters -->
		<xsl:variable name="resolvedTypeParas">
			<xsl:call-template name="buildListOfTypeParameters">
				<xsl:with-param name="template" select="$template" />
				<xsl:with-param name="typedef" select="$typedef" />
			</xsl:call-template>
		</xsl:variable>

		<!-- generate the class element -->
		<xsl:element name="class">
			<xsl:attribute name="name" select="$typedef/@name" />
			<xsl:attribute name="fullName" select="$typedef/@fullName" />
			<xsl:if test="$isInnerClass = true()">
				<xsl:attribute name="isInnerClass" select="'true'" />
			</xsl:if>

			<!-- store additional attributes to identify this class later -->
			<xsl:attribute name="originalTypedefFullName"
				select="$typedef/@fullName" />
			<xsl:attribute name="originalTemplateFullName"
				select="$template/@fullName" />

			<!-- store access modifier of typedef -->
			<xsl:attribute name="protection" select="$typedef/@protection"/>

			<!-- store the used type parameters -->
			<!-- this element can be used to identify a class generated by this xsl:template -->
			<xsl:element name="typeparameters">
				<xsl:for-each
					select="$template/templateparameters/templateparameter
								[@templateType = 'class' or @templateType = 'typename']">
					<xsl:variable name="pos" select="position()" />
					<xsl:element name="typepara">
						<xsl:attribute name="original"
							select="@templateDeclaration" />
						<xsl:attribute name="used"
							select="$resolvedTypeParas/para[$pos]/type" />
					</xsl:element>
				</xsl:for-each>
			</xsl:element>

			<!-- base classes -->
			<xsl:element name="inherits">
				<!-- this class musst implement the Interface for this template -->
				<!-- causes problems with primitive types as type parameters
					thogether with things like 'T* foo();' -->
				<!-- reenabled -->
				<!-- must be the first base class for javaType -->
				<xsl:element name="baseClass">
					<xsl:attribute name="fullBaseClassName"
						select="$template/@fullName" />
					<!-- very important for javaInterface -->
					<xsl:attribute name="originalTypedefBasetype"
						select="$typedef/@basetype" />

					<xsl:value-of select="$template/@name" />
				</xsl:element>

				<!-- copy base classes of template -->
				<xsl:for-each select="$template/inherits/baseClass">
					<xsl:copy-of select="." />
				</xsl:for-each>
			</xsl:element>

			<!-- copy include files -->
			<xsl:for-each select="$template/includes">
				<xsl:copy-of select="." />
			</xsl:for-each>
			<xsl:for-each select="$typedef/includes">
				<xsl:copy-of select="." />
			</xsl:for-each>

			<!-- copy inner classes -->
			<xsl:for-each select="$template/class">
				<!-- <xsl:copy-of select="."/> -->
				<xsl:variable name="genTypedefForInnerClass">
					<xsl:element name="typedef">
						<xsl:attribute name="name" select="./@name" />
						<xsl:attribute name="fullName"
							select="concat($typedef/@fullName, '::', ./@name)" />
						<xsl:attribute name="protection"
							select="./visibility" />
						<xsl:attribute name="basetype"
							select="$typedef/@basetype" />

						<xsl:for-each select="$typedef/includes">
							<xsl:copy-of select="." />
						</xsl:for-each>
					</xsl:element>
				</xsl:variable>
				<xsl:call-template
					name="createClassFromTemplateTypedef">
					<xsl:with-param name="template" select="." />
					<xsl:with-param name="typedef"
						select="$genTypedefForInnerClass/*" />
					<xsl:with-param name="isInnerClass" select="true()" />
				</xsl:call-template>
			</xsl:for-each>

			<!-- copy inner structs -->
			<xsl:for-each select="$template/struct">
				<!-- <xsl:copy-of select="."/> -->
				<xsl:variable name="genTypedefForInnerClass">
					<xsl:element name="typedef">
						<xsl:attribute name="name" select="./@name" />
						<xsl:attribute name="fullName"
							select="concat($typedef/@fullName, '::', ./@name)" />
						<xsl:attribute name="protection"
							select="./visibility" />
						<xsl:attribute name="basetype"
							select="$typedef/@basetype" />

						<xsl:for-each select="$typedef/includes">
							<xsl:copy-of select="." />
						</xsl:for-each>
					</xsl:element>
				</xsl:variable>
				<xsl:call-template
					name="createClassFromTemplateTypedef">
					<xsl:with-param name="template" select="." />
					<xsl:with-param name="typedef"
						select="$genTypedefForInnerClass/*" />
					<xsl:with-param name="isInnerClass" select="true()" />
				</xsl:call-template>
			</xsl:for-each>

			<!-- copy inner typedefs -->
			<xsl:for-each select="$template/typedef">
				<xsl:copy-of select="." />
			</xsl:for-each>

			<!-- copy inner enums -->
			<xsl:for-each select="$template/enum">
				<xsl:copy-of select="." />
			</xsl:for-each>

			<!-- copy public attributes -->
			<xsl:for-each select="$template/variable">
				<xsl:call-template name="createVariableElement">
					<xsl:with-param name="variable" select="." />
					<xsl:with-param name="typedef" select="$typedef" />
					<xsl:with-param name="template" select="$template" />
					<xsl:with-param name="resolvedTypeParas"
						select="$resolvedTypeParas" />
				</xsl:call-template>
			</xsl:for-each>

			<!-- copy methods -->
			<xsl:for-each select="$template/function">
				<xsl:call-template name="createFunctionElement">
					<xsl:with-param name="function" select="." />
					<xsl:with-param name="typedef" select="$typedef" />
					<xsl:with-param name="template" select="$template" />
					<xsl:with-param name="resolvedTypeParas"
						select="$resolvedTypeParas" />
				</xsl:call-template>
			</xsl:for-each>

		</xsl:element>

	</xsl:template>


	<xd:doc type="template">
		<xd:short>
			Uses typeparameters of typedef to generate types of methods
			and attributes. As passedBy can be changed by type
			parameters, those elements are also created here.
		</xd:short>
		<xd:param name="type">
			Type as in meta. Maybe something like 'T' or a real type like 'int'.
			Whole type element not just a string.
			@const and ../@passedBy are needed.
		</xd:param>
		<xd:param name="template">template which is used.</xd:param>
		<xd:param name="typedef">
			Typedef which uses a template.
		</xd:param>
		<xd:param name="resolvedTypeParas">
			List of used type parameters. Must be fully qualified.
		</xd:param>
	</xd:doc>
	<xsl:template name="createTypeElementAndPassedByAttribute">
		<xsl:param name="type" />
		<xsl:param name="template" />
		<xsl:param name="typedef" />
		<xsl:param name="resolvedTypeParas" />


		<!-- if this type is a template, get a list of it's typeparameters -->
		<!-- e.g. Ogre::ConstMapIterator<T>::operator=(Ogre::MapIterator<T>) -->
		<xsl:variable name="tokens">
			<xsl:if test="contains($type, '&lt;')">
				<xsl:call-template name="xbig:getListOfTypeParameters">
					<xsl:with-param name="type" select="$type" />
				</xsl:call-template>
			</xsl:if>
		</xsl:variable>
		<xsl:variable name="checkTokens">
			<xsl:for-each select="$tokens/*">
				<xsl:element name="check">
					<xsl:choose>
						<xsl:when test="$template/templateparameters/templateparameter
										[@templateType = 'class' or @templateType = 'typename']
										[@templateDeclaration = current()]">
							<xsl:value-of select="true()"/>
						</xsl:when>
						<xsl:otherwise>
							<xsl:value-of select="false()"/>
						</xsl:otherwise>
					</xsl:choose>
				</xsl:element>
			</xsl:for-each>
		</xsl:variable>
		<xsl:variable name="typeUsesTypeParameters" as="xs:boolean">
			<xsl:choose>
				<xsl:when test="$checkTokens/* = true()">
					<xsl:value-of select="true()"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="false()"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- DEBUG OUTPUT -->
		<!-- 
		<xsl:message>createTypeElementAndPassedByAttribute</xsl:message>
		<xsl:message>  $type: <xsl:value-of select="$type" /></xsl:message>
		<xsl:message>  $template/@name: <xsl:value-of select="$template/@name" /></xsl:message>
		<xsl:message>  $template/../@name: <xsl:value-of select="$template/../@name" /></xsl:message>
		<xsl:message>  $typedef/@name: <xsl:value-of select="$typedef/@name" /></xsl:message>
		<xsl:message>  $typedef/../@name: <xsl:value-of select="$typedef/../@name" /></xsl:message>
		<xsl:for-each select="$resolvedTypeParas/*">
			<xsl:message>    type para <xsl:value-of select="position()" />: <xsl:value-of select="." /></xsl:message>
		</xsl:for-each>
		<xsl:message>  $typeUsesTypeParameters: <xsl:value-of select="$typeUsesTypeParameters" /></xsl:message>
		 -->


		<!-- find out values -->
		<xsl:variable name="typeAndPassedBy">
			<xsl:choose>

				<!-- exchange type parameter name with actual used type parameter -->
				<xsl:when
					test="$template/templateparameters/templateparameter
								[@templateType = 'class' or @templateType = 'typename']
								[@templateDeclaration = $type]">
					<xsl:variable name="pos">
						<xsl:for-each
							select="$template/templateparameters/templateparameter
											[@templateType = 'class' or @templateType = 'typename']">
							<xsl:if
								test="@templateDeclaration = $type">
								<xsl:value-of select="position()" />
							</xsl:if>
						</xsl:for-each>
					</xsl:variable>

					<!-- TODO pointer pointer stuff -->

					<!-- handle pointers as type parameters -->
					<xsl:variable name="selectedTypePara"
						select="$resolvedTypeParas/para[number($pos)]" />
						
					<!-- return -->
					<xsl:element name="type">
						<xsl:attribute name="const" select="if ($selectedTypePara/type/@const = 'true')
												then $selectedTypePara/type/@const else $type/@const"/>
						<xsl:attribute name="constInTemplate" select="if ($type/@const = 'true')
																		then 'true' else 'false'"/>
						<xsl:choose>
							<xsl:when
								test="starts-with($selectedTypePara/type, '::')">
								<xsl:value-of
									select="substring-after($selectedTypePara/type, '::')" />
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of
									select="$selectedTypePara/type" />
							</xsl:otherwise>
						</xsl:choose>
					</xsl:element>
					<xsl:element name="passedBy">
						<xsl:choose>
							<!-- implicit pointer pointer: T* foo() with T: A* -> A** foo() -->
							<xsl:when
								test="($selectedTypePara/@passedBy = 'pointer')
										and ($type/../@passedBy = 'pointer')">
								<xsl:attribute name="pointerPointer" select="'true'"/>
								<xsl:value-of
									select="'pointer'" />
							</xsl:when>

							<!-- when type para is by value -> keep passedBy of orignial template -->
							<xsl:when test="$selectedTypePara/@passedBy = 'value'">
								<xsl:value-of
									select="$type/../@passedBy" />
							</xsl:when>

							<!-- no implicit pointer pointer -->
							<xsl:otherwise>
								<xsl:value-of
									select="$selectedTypePara/@passedBy" />
							</xsl:otherwise>
						</xsl:choose>
					</xsl:element>
				</xsl:when>

				<!-- resolve typename stuff used in OGRE IteratorWrappers -->
				<xsl:when
					test="$template/templateparameters/templateparameter
								[@templateType = 'class' or @templateType = 'typename']
								[@templateDeclaration = substring-before($type, '::')]">

					<xsl:variable name="baseTypedef">
						<xsl:call-template name="findTypedefOrigin">
							<xsl:with-param name="template"
								select="$template" />
							<xsl:with-param name="typedef"
								select="$typedef" />
						</xsl:call-template>
					</xsl:variable>

					<xsl:variable name="originNodeName" select="
						if (starts-with($baseTypedef/*/@basetype, '::'))
						then substring-after($baseTypedef/*/@basetype, '::')
						else $baseTypedef/*/@basetype"/>

					<xsl:variable name="originNode"
						select="$root//*
						[@fullName = normalize-space(substring-before($originNodeName, '&lt;'))]" />

					<!-- TODO inner classes stuff -->
					<xsl:variable name="infoNode"
						select="$originNode/additionalInfo/info
												[@name = normalize-space(substring-after($type, '::'))]" />

					<!-- build list of type parameters -->
					<xsl:variable name="resolvedTypeParas">
						<xsl:call-template
							name="buildListOfTypeParameters">
							<xsl:with-param name="template"
								select="$originNode" />
							<!-- This way, the typedef's parent is not found
							<xsl:with-param name="typedef"
								select="$baseTypedef/*" />
							 -->
							<xsl:with-param name="typedef"
								select="//typedef[@fullName = $baseTypedef/*[1]/@fullName]" />
						</xsl:call-template>
					</xsl:variable>


					<!-- DEBUG OUTPUT -->
					<!-- 
					<xsl:message>  resolve typename stuff used in OGRE IteratorWrappers</xsl:message>
					<xsl:message>    $type: <xsl:value-of select="$type" /></xsl:message>
					<xsl:message>    baseTypedef: <xsl:value-of select="$baseTypedef/*/@name" /></xsl:message>
					<xsl:message>    infoNode/@name: <xsl:value-of select="$infoNode/@name" /></xsl:message>
					<xsl:message>    infoNode/@typeParaPos: <xsl:value-of select="$infoNode/@typeParaPos" /></xsl:message>
					<xsl:for-each select="$resolvedTypeParas/*">
						<xsl:message>      type para <xsl:value-of select="position()" />: <xsl:value-of select="." /></xsl:message>
					</xsl:for-each>
					 -->


					<!-- return used type parameter -->
					<xsl:element name="type">
						<xsl:attribute name="const" select="if($infoNode/@addConst) then 'true'
								else if($type/@const = 'true') then 'true' else 
								$resolvedTypeParas/*[position() = $infoNode/@typeParaPos]/type/@const"/>
						<xsl:attribute name="constInTemplate" select="if ($type/@const = 'true')
																		then 'true' else 'false'"/>
						<xsl:value-of
							select="$resolvedTypeParas/*[position() = $infoNode/@typeParaPos]/type" />
					</xsl:element>

					<!-- return changed passed by -->
					<xsl:element name="passedBy">
						<xsl:choose>
							<!-- passedBy changed through template member only, method uses value -->
							<xsl:when
								test="($infoNode/@changePassedBy and $infoNode/@changePassedBy = 'true') and 
									($resolvedTypeParas/*[position() = $infoNode/@typeParaPos]/@passedBy = 'value') and
									($type/../@passedBy = 'value')">
								<xsl:value-of
									select="$infoNode/@newPassedBy" />
							</xsl:when>

							<!-- passedBy changed through type parameter only, method uses value -->
							<xsl:when
								test="(not($infoNode/@changePassedBy) or $infoNode/@changePassedBy = 'false') and 
									(not($resolvedTypeParas/*[position() = $infoNode/@typeParaPos]/@passedBy = 'value')) and
									($type/../@passedBy = 'value')">
								<xsl:value-of
									select="$resolvedTypeParas/*[position() = $infoNode/@typeParaPos]/@passedBy" />
							</xsl:when>

							<!-- passedBy changed through template member and type parameter, method uses value -->
							<xsl:when
								test="($infoNode/@changePassedBy and $infoNode/@changePassedBy = 'true') and 
									(not($resolvedTypeParas/*[position() = $infoNode/@typeParaPos]/@passedBy = 'value')) and
									($type/../@passedBy = 'value')">
								<xsl:attribute name="pointerPointer" select="'true'"/>
								<xsl:value-of
									select="'pointer'" />
							</xsl:when>

							<!-- passedBy changed through template member only, method uses pointer -->
							<xsl:when
								test="($infoNode/@changePassedBy and $infoNode/@changePassedBy = 'true') and 
									($resolvedTypeParas/*[position() = $infoNode/@typeParaPos]/@passedBy = 'value') and
									($type/../@passedBy = 'pointer')">
								<!-- we assume that new passedBy is always pointer -->
								<xsl:attribute name="pointerPointer" select="'true'"/>
								<xsl:value-of
									select="'pointer'" />
							</xsl:when>

							<!-- passedBy changed through type parameter only, method uses pointer -->
							<xsl:when
								test="(not($infoNode/@changePassedBy) or $infoNode/@changePassedBy = 'false') and 
									(not($resolvedTypeParas/*[position() = $infoNode/@typeParaPos]/@passedBy = 'value')) and
									($type/../@passedBy = 'pointer')">
								<!-- we assume that new passedBy is always pointer -->
								<xsl:attribute name="pointerPointer" select="'true'"/>
								<xsl:value-of
									select="'pointer'" />
							</xsl:when>

							<!-- passedBy not changed -->
							<xsl:otherwise>
								<xsl:value-of
									select="$type/../@passedBy" />
							</xsl:otherwise>
						</xsl:choose>
					</xsl:element>

				</xsl:when><!-- end special OGRE IteratorWrapper stuff -->

				<!-- template as method parameter which 
					 uses type parameter of template which contains method
					 e.g. Ogre::ConstMapIterator<T>::operator=(Ogre::MapIterator<T>) -->
				<xsl:when test="$typeUsesTypeParameters = true()">
					<xsl:element name="type">
						<!-- return const -->
						<xsl:attribute name="const" select="$type/@const"/>

						<!-- return type -->
						<!-- find out some values -->
						<xsl:variable name="isTypeThisTemplate" as="xs:boolean">
							<xsl:variable name="typeBeforeBracket" select="normalize-space(
										substring-before($type, '&lt;'))"/>
							<xsl:variable name="typeNameWithoutNamespace" select="
										if(contains($typeBeforeBracket, '::'))
										then tokenize($typeBeforeBracket, '::')[last()]
										else $typeBeforeBracket"/>
							<xsl:variable name="templateWithoutNamespace" select="if(contains(
										$template/@fullName, '::')) then 
										tokenize($template/@fullName, '::')[last()] 
										else $template/@fullName"/>
							<xsl:sequence select="
										if ($typeNameWithoutNamespace 
											= $templateWithoutNamespace)
										then true() else false()"/>
						</xsl:variable>

						<xsl:variable name="checkTokensAndTypeparameters">
							<xsl:for-each select="$template/templateparameters/templateparameter
									[@templateType = 'class' or @templateType = 'typename']">
								<xsl:element name="check">
									<xsl:choose>
										<xsl:when test="@templateDeclaration = $tokens/*[current()/position()]">
											<xsl:sequence select="true()"/>
										</xsl:when>
										<xsl:otherwise>
											<xsl:sequence select="false()"/>
										</xsl:otherwise>
									</xsl:choose>
								</xsl:element>
							</xsl:for-each>
						</xsl:variable>

						<xsl:variable name="areTypeParasEqual" select="
								if($checkTokensAndTypeparameters/* = false())
								then false() else true()"
								as="xs:boolean">
						</xsl:variable>

						<xsl:choose>
							<!-- use typedef -->
							<xsl:when test="$isTypeThisTemplate = true()
											and $areTypeParasEqual = true()">
								<xsl:value-of select="concat('::', $typedef/@fullName)"/>
							</xsl:when>

							<!-- use type with replaced type parameters -->
							<xsl:otherwise>
								<xsl:variable name="templateNameWithOpeningBracket"
									select="concat('::', xbig:getFullTypeName(normalize-space(substring-before(
											$type, '&lt;')), $template, $root), '&lt;')" />

								<xsl:value-of select="concat(
									xbig:extendMethodParameterTemplateWithTypeparasOfMethodContainingTemplate(
									$templateNameWithOpeningBracket, 1, $resolvedTypeParas, $tokens, $template)
									, '&gt;')"/>
							</xsl:otherwise>
						</xsl:choose>
						
					</xsl:element>

					<!-- return passedBy -->
					<xsl:element name="passedBy">
						<xsl:value-of
							select="$type/../@passedBy" />
					</xsl:element>

				</xsl:when><!-- end template with generic type parameter -->

				<!-- use type used in template -->
				<xsl:otherwise>

					<xsl:variable name="fullTypeName"
						select="xbig:resolveTypedef($type, $template, $root)" />

					<xsl:choose>
						<xsl:when
							test="xbig:isClassOrStruct($fullTypeName, $template, $root)">
							<xsl:element name="type">
								<xsl:attribute name="const" select="$type/@const"/>
								<xsl:value-of
									select="concat('::', xbig:getFullTypeName(
													$type, $template, $root))" />
							</xsl:element>
							<xsl:element name="passedBy">
								<xsl:value-of
									select="$type/../@passedBy" />
							</xsl:element>
						</xsl:when>
						<xsl:when
							test="xbig:isEnum($fullTypeName, $template, $root)">
							<xsl:element name="type">
								<xsl:attribute name="const" select="$type/@const"/>
								<xsl:value-of
									select="concat('::', xbig:getFullTypeName(
													$type, $template, $root))" />
							</xsl:element>
							<xsl:element name="passedBy">
								<xsl:value-of
									select="$type/../@passedBy" />
							</xsl:element>
						</xsl:when>
						<xsl:when
							test="xbig:isTypedef($fullTypeName, $template, $root)">
							<xsl:element name="type">
								<xsl:attribute name="const" select="$type/@const"/>
								<xsl:value-of
									select="concat('::', xbig:getFullTypeName(
													xbig:resolveTypedef($type, $template, $root)
													, $template, $root))" />
							</xsl:element>
							<xsl:element name="passedBy">
								<xsl:value-of
									select="$type/../@passedBy" />
							</xsl:element>
						</xsl:when>
						<xsl:otherwise>
							<xsl:element name="type">
								<xsl:attribute name="const" select="$type/@const"/>
								<xsl:value-of select="$type" />
							</xsl:element>
							<xsl:element name="passedBy">
								<xsl:value-of
									select="$type/../@passedBy" />
							</xsl:element>
						</xsl:otherwise>
					</xsl:choose>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- create passed by attribute -->
		<xsl:attribute name="passedBy"
			select="$typeAndPassedBy/passedBy" />
						
		<!-- create type element -->
		<xsl:element name="type">
			<!-- for primitive types as template parameters, needed in javaAccessMethodDeclaration.xslt -->
			<xsl:attribute name="originalType" select="$type" />

			<!-- if we have implicit pointer pointer -->
			<xsl:if test="$typeAndPassedBy/passedBy/@pointerPointer and
							$typeAndPassedBy/passedBy/@pointerPointer = 'true'">
				<xsl:attribute name="pointerPointer" select="'true'" />
			</xsl:if>
			<!-- copy all attributes -->
			<xsl:for-each select="$typeAndPassedBy/type/@*">
				<xsl:copy-of select="." />
			</xsl:for-each>

			<!-- copy type value -->
			<xsl:value-of select="$typeAndPassedBy/type" />
		</xsl:element>
	</xsl:template>


	<xd:doc type="function">
		<xd:short>
			Internal recursive helper function. Used for parameters of methods which are templates
			and use a type parameter of the template the method is declared in.
			E.g. Ogre::ConstMapIterator&lt;T&gt;::operator=(Ogre::MapIterator&lt;T&gt;)
		</xd:short>
		<xd:param name="baseString">
			String to add next type parameter to. For first call e.g. 'Ogre::MapIterator&lt;'.
		</xd:param>
		<xd:param name="currentPosition">
			Number of type parameter to process.
		</xd:param>
		<xd:param name="resolvedTypeParas">
			Resolved type parameters of template which contains method and a typedef.
		</xd:param>
		<xd:param name="tokens">
			Original type parameters of template used as method parameter. E.g. T.
		</xd:param>
		<xd:param name="template">
			Meta node of template which contains method. Needed for type parameter declarations. E.g. T.
		</xd:param>
	</xd:doc>
	<xsl:function name="xbig:extendMethodParameterTemplateWithTypeparasOfMethodContainingTemplate"
			as="xs:string">
		<xsl:param name="baseString" as="xs:string"/>
		<xsl:param name="currentPosition" as="xs:integer"/>
		<xsl:param name="resolvedTypeParas"/>
		<xsl:param name="tokens"/>
		<xsl:param name="template"/>

		<xsl:variable name="extendedString">
			<xsl:choose>
				<!-- replace type parameter -->
				<xsl:when test="$template/templateparameters/templateparameter
								[@templateType = 'class' or @templateType = 'typename']
								[@templateDeclaration = $tokens/*[$currentPosition]]">
					<xsl:sequence select="concat($baseString, $resolvedTypeParas/*[$currentPosition])"/>
				</xsl:when>

				<!-- keep type parameter -->
				<xsl:otherwise>
					<xsl:sequence select="concat($baseString, $tokens/*[$currentPosition])"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<xsl:choose>
			<!-- next recursion -->
			<xsl:when test="count($tokens/*) lt $currentPosition - 1">
				<xsl:sequence select="
						xbig:extendMethodParameterTemplateWithTypeparasOfMethodContainingTemplate(
						concat($extendedString, ','),
						$currentPosition + 1, $resolvedTypeParas, $tokens, $template)"/>
			</xsl:when>

			<!-- last recursion step -->
			<xsl:when test="count($tokens/*) lt $currentPosition">
				<xsl:sequence select="
						xbig:extendMethodParameterTemplateWithTypeparasOfMethodContainingTemplate(
						$extendedString, $currentPosition + 1, $resolvedTypeParas, $tokens, $template)"/>
			</xsl:when>

			<!-- recursion end -->
			<xsl:otherwise>
				<xsl:sequence select="$extendedString"/>
			</xsl:otherwise>
		</xsl:choose>

	</xsl:function>


	<xd:doc type="template">
		<xd:short>
			Parses type parameters used in typedef and puts them in a
			list. Fully qualifies them.
		</xd:short>
		<xd:param name="template">template which is used.</xd:param>
		<xd:param name="typedef">
			typedef which uses a template.
		</xd:param>
	</xd:doc>
	<xsl:template name="buildListOfTypeParameters">
		<xsl:param name="template" />
		<xsl:param name="typedef" />

		<!-- build list of type parameters -->
		<xsl:variable name="tokens">
			<xsl:call-template name="xbig:getListOfTypeParameters">
				<xsl:with-param name="type" select="$typedef/@basetype" />
			</xsl:call-template>
		</xsl:variable>

		<!-- start list -->
		<xsl:for-each select="$tokens/*">

			<!-- get meta parameter element -->
			<xsl:variable name="metaParaElement">
				<xsl:call-template name="createMetaParameterElement">
					<xsl:with-param name="type" select="."/>
				</xsl:call-template>
			</xsl:variable>

			<!-- create own parameter element for caller -->
			<xsl:element name="para">
				<!-- set passedBy attribute -->
				<xsl:attribute name="passedBy" select="$metaParaElement/*[1]/@passedBy" />

				<!-- add type child element -->
				<xsl:element name="type">
					<!-- set const attribute -->
					<xsl:attribute name="const" select="$metaParaElement/*[1]/type/@const" />

					<!-- remove all modifiers and spaces -->
					<xsl:variable name="normalizedToken" select="$metaParaElement/*[1]/type" />

					<!-- resolve typedef -->
					<xsl:variable name="resolvedType"
						select="xbig:resolveTypedef($normalizedToken, $typedef/.., $root)" />

					<xsl:choose>
						<!-- templates as type parameters -->
						<xsl:when
							test="contains($normalizedToken, '&lt;')">
							<xsl:value-of
								select="concat('::', xbig:getFullTemplateName(
									$normalizedToken, $typedef, $root))" />
						</xsl:when>

						<!-- primitive types -->
						<xsl:when
							test="$config/config/meta/signatures/type[@meta = $resolvedType]">
							<xsl:value-of select="$resolvedType" />
						</xsl:when>

						<xsl:otherwise>
							<xsl:choose>
								<!-- classes, ... -->
								<xsl:when
									test="xbig:isClassOrStruct($resolvedType, $template, $root)">
									<xsl:value-of
										select="concat('::', $resolvedType)" />
								</xsl:when>
								<xsl:when
									test="xbig:isEnum($resolvedType, $template, $root)">
									<xsl:value-of
										select="concat('::', $resolvedType)" />
								</xsl:when>
								<xsl:when
									test="xbig:isTypedef($resolvedType, $template, $root)">
									<xsl:value-of
										select="concat('::', $resolvedType)" />
								</xsl:when>

								<!-- unresolved type -->
								<xsl:otherwise>
									<xsl:value-of select="$normalizedToken" />
								</xsl:otherwise>
							</xsl:choose>
						</xsl:otherwise>
					</xsl:choose>
				</xsl:element>
			</xsl:element>
		</xsl:for-each>
	</xsl:template>


	<xd:doc type="template">
		<xd:short>
			When we are dealing with a typedef for a typedef for a
			typedef ... this templates finds the first one.
		</xd:short>
		<xd:param name="template">template which is used.</xd:param>
		<xd:param name="typedef">
			typedef which uses a template.
		</xd:param>
	</xd:doc>
	<xsl:template name="findTypedefOrigin">
		<xsl:param name="typedef" />
		<xsl:param name="template" />

		<!-- build list of type parameters -->
		<xsl:variable name="resolvedTypeParas">
			<xsl:call-template name="buildListOfTypeParameters">
				<xsl:with-param name="template" select="$template" />
				<xsl:with-param name="typedef" select="$typedef" />
			</xsl:call-template>
		</xsl:variable>

		<xsl:variable name="typePara">
			<xsl:choose>
				<xsl:when
					test="starts-with($resolvedTypeParas/para[1]/type, '::')">
					<xsl:value-of
						select="substring-after($resolvedTypeParas/para[1]/type, '::')" />
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="$resolvedTypeParas/para[1]/type" />
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<xsl:choose>
			<xsl:when test="$root//typedef[@fullName = $typePara]">
				<xsl:call-template name="findTypedefOrigin">
					<xsl:with-param name="template"
						select="$root//*
							[@fullName = normalize-space(substring-before($typedef/@basetype, '&lt;'))]" />
					<xsl:with-param name="typedef"
						select="$root//*[@fullName = $typePara]" />
				</xsl:call-template>
			</xsl:when>

			<!-- return node, usually a typedef for an external template -->
			<xsl:otherwise>
				<xsl:copy-of select="$typedef" />
			</xsl:otherwise>
		</xsl:choose>

	</xsl:template>



	<xd:doc type="template">
		<xd:short>
			Generates a meta variable element for the class generated in
			above templates. Makes use of some above templates.
		</xd:short>
		<xd:param name="variable">
			variable of template which shall be generated for class.
		</xd:param>
		<xd:param name="typedef">
			typedef which uses a template.
		</xd:param>
		<xd:param name="template">template which is used.</xd:param>
		<xd:param name="resolvedTypeParas">
			list of used type parameters. Must be fully qualified.
		</xd:param>
	</xd:doc>
	<xsl:template name="createVariableElement">
		<xsl:param name="variable" />
		<xsl:param name="typedef" />
		<xsl:param name="template" />
		<xsl:param name="resolvedTypeParas" />

		<xsl:element name="variable">

			<xsl:attribute name="visibility"
				select="$variable/@visibility" />
			<xsl:attribute name="static" select="$variable/@static" />
			<xsl:attribute name="const" select="$variable/@const" />

			<xsl:call-template
				name="createTypeElementAndPassedByAttribute">
				<xsl:with-param name="type" select="$variable/type" />
				<xsl:with-param name="template" select="$template" />
				<xsl:with-param name="typedef" select="$typedef" />
				<xsl:with-param name="resolvedTypeParas"
					select="$resolvedTypeParas" />
			</xsl:call-template>

			<xsl:element name="name">
				<xsl:value-of select="$variable/name" />
			</xsl:element>
			<xsl:element name="definition">
				<xsl:value-of select="$variable/definition" />
			</xsl:element>

		</xsl:element>

	</xsl:template>


	<xd:doc type="template">
		<xd:short>
			Generates a meta function element for the class generated in
			above templates. Makes use of some above templates.
		</xd:short>
		<xd:param name="function">
			method of template which shall be generated for class.
		</xd:param>
		<xd:param name="typedef">
			typedef which uses a template.
		</xd:param>
		<xd:param name="template">template which is used.</xd:param>
		<xd:param name="resolvedTypeParas">
			list of used type parameters. Must be fully qualified.
		</xd:param>
	</xd:doc>
	<xsl:template name="createFunctionElement">
		<xsl:param name="function" />
		<xsl:param name="typedef" />
		<xsl:param name="template" />
		<xsl:param name="resolvedTypeParas" />

		<xsl:element name="function">
			<xsl:attribute name="virt" select="$function/@virt" />
			<xsl:attribute name="visibility"
				select="$function/@visibility" />
			<xsl:attribute name="static" select="$function/@static" />
			<xsl:attribute name="const" select="$function/@const" />

			<!-- special attribute to recognize this function as a generated one
				needed for jni implementation of methods inherited from templates -->
			<xsl:attribute name="isGeneratedForTemplate"
				select="'true'" />

			<xsl:if test="type">
				<xsl:call-template
					name="createTypeElementAndPassedByAttribute">
					<xsl:with-param name="type" select="$function/type" />
					<xsl:with-param name="template" select="$template" />
					<xsl:with-param name="typedef" select="$typedef" />
					<xsl:with-param name="resolvedTypeParas"
						select="$resolvedTypeParas" />
				</xsl:call-template>
			</xsl:if>

			<!-- rename c-tors -->
			<xsl:element name="name">
				<xsl:choose>
					<xsl:when test="$function/name = $template/@name">
						<xsl:value-of select="$typedef/@name" />
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="$function/name" />
					</xsl:otherwise>
				</xsl:choose>
			</xsl:element>

			<!-- write new class in definition, leave return type untouched -->
			<xsl:element name="definition">
				<!--
					<xsl:variable name="defPreStuff" 
					select="substring-before($function/definition, $template/@name)"/>
					<xsl:variable name="defPostStuff" 
					select="substring-after($defPreStuff, '::')"/>
					<xsl:value-of select="concat($defPreStuff, $typedef/@name, '::', $defPostStuff)"/>
				-->
				<xsl:value-of select="$function/definition" />
			</xsl:element>

			<xsl:if test="$function/parameters">
				<xsl:element name="parameters">
					<xsl:for-each
						select="$function/parameters/parameter">
						<xsl:element name="parameter">

							<xsl:call-template
								name="createTypeElementAndPassedByAttribute">
								<xsl:with-param name="type"
									select="./type" />
								<xsl:with-param name="template"
									select="$template" />
								<xsl:with-param name="typedef"
									select="$typedef" />
								<xsl:with-param name="resolvedTypeParas"
									select="$resolvedTypeParas" />
							</xsl:call-template>

							<xsl:element name="name">
								<xsl:value-of select="./name" />
							</xsl:element>

						</xsl:element>
					</xsl:for-each>
				</xsl:element>
			</xsl:if>

			<!-- copy provided jni implementation -->
			<xsl:if test="jniImplementation">
				<xsl:copy-of select="$function/jniImplementation" />
			</xsl:if>

		</xsl:element>

	</xsl:template>


</xsl:stylesheet>
