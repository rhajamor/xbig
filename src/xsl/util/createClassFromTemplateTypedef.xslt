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

	<xsl:import href="../exslt/str.split.template.xsl" />

	<xd:doc type="stylesheet">
		<xd:short>Creates a meta class element from a template and a typedef. 
				  The global variable $root must be set</xd:short>
	</xd:doc>

	<xsl:template name="createClassFromTemplateTypedef">
		<xsl:param name="template" />
		<xsl:param name="typedef" />
		<xsl:param name="isInnerClass" />

		<!-- build list of type parameters -->
		<xsl:variable name="bracket" select="substring-after($typedef/@basetype, '&lt;')"/>
		<xsl:variable name="insideBracket"
			select="normalize-space(substring($bracket, 0, string-length($bracket)-1))"/>
		<xsl:variable name="tokens">
			<xsl:call-template name="str:split">
				<xsl:with-param name="string" select="$insideBracket" />
				<xsl:with-param name="pattern" select="','" />
			</xsl:call-template>
		</xsl:variable>
		<xsl:variable name="resolvedTypeParas">
			<xsl:for-each select="$tokens/*">
				<xsl:element name="para">
						<xsl:variable name="normalizedToken" select="normalize-space(.)"/>
						<xsl:choose>
							<!-- templates as type parameters -->
							<xsl:when test="contains(., '&lt;')">
								<xsl:value-of select="concat('::', xbig:getFullTemplateName(
											$normalizedToken, $typedef, $root))"/>
							</xsl:when>

							<!-- primitive types -->
							<xsl:when test="$config/config/meta/signatures/type[@meta = $normalizedToken]">
								<xsl:value-of select="$normalizedToken"/>
							</xsl:when>

							<!-- classes, ... -->
							<xsl:otherwise>
								<xsl:value-of select="concat('::', xbig:getFullTypeName(xbig:resolveTypedef(
											$normalizedToken, $typedef, $root), $typedef, $root))"/>
							</xsl:otherwise>
						</xsl:choose>
					</xsl:element>
				</xsl:for-each>
		</xsl:variable>


		<!-- generate the class element -->
		<xsl:element name="class">
			<xsl:attribute name="name" select="$typedef/@name"/>
			<xsl:attribute name="fullName" select="$typedef/@fullName"/>
			<xsl:if test="$isInnerClass = true()">
				<xsl:attribute name="isInnerClass" select="'true'"/>
			</xsl:if>

			<!-- store the used type parameters -->
			<xsl:element name="typeparameters">
				<xsl:for-each select="$template/templateparameters/templateparameter
								[@templateType = 'class' or @templateType = 'typename']">
					<xsl:element name="typepara">
						<xsl:attribute name="original" select="@templateDeclaration"/>
						<xsl:attribute name="used" select="$resolvedTypeParas/para[position()]"/>
					</xsl:element>
				</xsl:for-each>
			</xsl:element>

			<!-- this class musst implement the Interface for this template -->
			<xsl:element name="inherits">
				<xsl:element name="baseClass">
					<xsl:attribute name="fullBaseClassName" select="$template/@fullName"/>
					<xsl:value-of select="$template/@name"/>
				</xsl:element>
			</xsl:element>

			<!-- copy include files -->
			<xsl:for-each select="$template/includes">
				<xsl:copy-of select="."/>
			</xsl:for-each>
			<!-- copy inner classes -->
			<xsl:for-each select="$template/class">
				<xsl:copy-of select="."/>
			</xsl:for-each>
			<!-- copy inner structs -->
			<xsl:for-each select="$template/struct">
				<xsl:copy-of select="."/>
			</xsl:for-each>
			<!-- copy inner typedefs -->
			<xsl:for-each select="$template/typedef">
				<xsl:copy-of select="."/>
			</xsl:for-each>
			<!-- copy inner enums -->
			<xsl:for-each select="$template/enum">
				<xsl:copy-of select="."/>
			</xsl:for-each>

			<!-- copy public attributes -->
			<xsl:for-each select="$template/variable">
				<xsl:element name="variable">

					<xsl:attribute name="visibility" select="./@visibility"/>
               		<xsl:attribute name="static" select="./@static"/>
               		<xsl:attribute name="const" select="./@const"/>
               		<xsl:attribute name="passedBy" select="./@passedBy"/>

					<xsl:element name="name">
						<xsl:value-of select="./name"/>
					</xsl:element>
					<xsl:element name="definition">
						<xsl:value-of select="./definition"/>
					</xsl:element>

					<xsl:call-template name="createTypeElement">
						<xsl:with-param name="type" select="./type"/>
						<xsl:with-param name="template" select="$template"/>
						<xsl:with-param name="resolvedTypeParas" select="$resolvedTypeParas"/>
					</xsl:call-template>

				</xsl:element>
			</xsl:for-each>

			<!-- copy methods -->
			<xsl:for-each select="$template/function">
				<xsl:element name="function">
                  		<xsl:attribute name="virt" select="./@virt"/>
                  		<xsl:attribute name="visibility" select="./@visibility"/>
                  		<xsl:attribute name="static" select="./@static"/>
                  		<xsl:attribute name="const" select="./@const"/>
                  		<xsl:attribute name="passedBy" select="./@passedBy"/>

					<!-- rename c-tors -->
					<xsl:element name="name">
						<xsl:choose>
							<xsl:when test="./name = $template/@name">
								<xsl:value-of select="$typedef/@name"/>
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of select="./name"/>
							</xsl:otherwise>
						</xsl:choose>
					</xsl:element>

					<!-- write new class in definition, leave return type untouched -->
					<xsl:element name="definition">
						<!--
						<xsl:variable name="defPreStuff" 
								select="substring-before(./definition, $template/@name)"/>
						<xsl:variable name="defPostStuff" 
								select="substring-after($defPreStuff, '::')"/>
						<xsl:value-of select="concat($defPreStuff, $typedef/@name, '::', $defPostStuff)"/>
						-->
						<xsl:value-of select="./definition"/>
					</xsl:element>

					<xsl:if test="type">
						<xsl:call-template name="createTypeElement">
							<xsl:with-param name="type" select="./type"/>
							<xsl:with-param name="template" select="$template"/>
							<xsl:with-param name="resolvedTypeParas" select="$resolvedTypeParas"/>
						</xsl:call-template>
					</xsl:if>

					<xsl:if test="./parameters">
						<xsl:element name="parameters">
							<xsl:for-each select="./parameters/parameter">
								<xsl:element name="parameter">
									<xsl:attribute name="passedBy" select="./@passedBy"/>
									<xsl:element name="name">
										<xsl:value-of select="./name"/>
									</xsl:element>

									<xsl:call-template name="createTypeElement">
										<xsl:with-param name="type" select="./type"/>
										<xsl:with-param name="template" select="$template"/>
										<xsl:with-param name="resolvedTypeParas" 
											select="$resolvedTypeParas"/>
									</xsl:call-template>
								</xsl:element>
							</xsl:for-each>
						</xsl:element>
					</xsl:if>
				</xsl:element>
			</xsl:for-each>

		</xsl:element>

	</xsl:template>


	<xsl:template name="createTypeElement">
		<xsl:param name="type"/>
		<xsl:param name="template"/>
		<xsl:param name="resolvedTypeParas"/>

		<xsl:element name="type">
			<!-- for primitive types as template parameters, needed in javaAccessMethodDeclaration.xslt -->
			<xsl:attribute name="originalType" select="$type"/>

			<xsl:if test="$type/@const">
				<xsl:attribute name="const" select="'true'"/>
			</xsl:if>
			<xsl:if test="$type/@constPointer">
				<xsl:attribute name="constPointer" select="'true'"/>
			</xsl:if>
			<xsl:choose>
				<xsl:when test="$template/templateparameters/templateparameter
								[@templateType = 'class' or @templateType = 'typename']
								[@templateDeclaration = $type]">
					<xsl:variable name="pos" select="
								$template/templateparameters/templateparameter
								[@templateType = 'class' or @templateType = 'typename']
								[@templateDeclaration = $type]/position()"/>
					<xsl:value-of select="$resolvedTypeParas/para[$pos]"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:choose>
						<xsl:when test="xbig:isClassOrStruct($type, $template, $root)">
							<xsl:value-of select="concat('::', xbig:getFullTypeName(
													$type, $template, $root))"/>
						</xsl:when>
						<xsl:when test="xbig:isEnum($type, $template, $root)">
							<xsl:value-of select="concat('::', xbig:getFullTypeName(
													$type, $template, $root))"/>
						</xsl:when>
						<xsl:when test="xbig:isTypedef($type, $template, $root)">
							<xsl:value-of select="concat('::', xbig:getFullTypeName(
													xbig:resolveTypedef($type, $template, $root)
													, $template, $root))"/>
						</xsl:when>
						<xsl:otherwise>
							<xsl:value-of select="$type"/>
						</xsl:otherwise>
					</xsl:choose>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:element>
	</xsl:template>


</xsl:stylesheet>
