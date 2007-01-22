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
	xmlns:xbig="http://xbig.sourceforge.net/XBiG">

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single original class or struct</xd:short>
	</xd:doc>

	<xsl:template name="javaPublicAttribute">
		<xsl:param name="config" />

		<!-- resolve typedefs -->
		<xsl:variable name="resolvedType" select="xbig:resolveTypedef(./type, .., $root)"/>

		<!-- getter -->
		<xsl:variable name="getterName">
			<xsl:value-of select="$config/config/meta/publicattribute/get/text()"/>
			<xsl:value-of select="name"/>
		</xsl:variable>

		<!-- native method name -->
		<xsl:variable name="nativeGetterName" select="concat('__', $getterName)" />

		<xsl:call-template name="javaPublicAttributeGetterDeclaration">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="typeName" select="$resolvedType" />
		</xsl:call-template>

		<xsl:text> { return </xsl:text>

		<!-- create Pointer object when necessary -->
		<xsl:if test="./@passedBy='pointer' or ./@passedBy='reference'">
			<xsl:text>new&#32;</xsl:text>
			<xsl:call-template name="javaPointerClass">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="param" select="." />
				<xsl:with-param name="typeName" select="$resolvedType" />
			</xsl:call-template>
			<xsl:text>(new&#32;InstancePointer(</xsl:text>
		</xsl:if>

		<xsl:value-of select="$nativeGetterName" />
		<xsl:text>(</xsl:text>
		<xsl:if test="not(@static)">
			<xsl:text>object.pointer</xsl:text>
		</xsl:if>

		<!-- close Pointer and InstancePointer c-tor calls -->
		<xsl:if test="./@passedBy='pointer' or ./@passedBy='reference'">
			<xsl:text>))</xsl:text>
		</xsl:if>

		<xsl:text>);</xsl:text>
		<xsl:text>}&#10;</xsl:text>

		<!-- native -->
		<xsl:if test="@static">
			<xsl:text>static </xsl:text>
		</xsl:if>
		<xsl:text>private final native </xsl:text>

		<!-- return type -->
		<xsl:choose>
			<xsl:when test="./@passedBy='pointer' or ./@passedBy='reference'">
				<xsl:text>long</xsl:text>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="type"/>
			</xsl:otherwise>
		</xsl:choose>

		<xsl:text> </xsl:text>
		<xsl:value-of select="$nativeGetterName" />
		<xsl:text>(</xsl:text>
		<xsl:if test="not(@static)">
			<xsl:text>long _pointer_</xsl:text>
		</xsl:if>
		<xsl:text>);&#10;&#10;</xsl:text>


		<!-- setter -->
		<xsl:if test="not(@const)">
			<xsl:variable name="setterName">
				<xsl:value-of select="$config/config/meta/publicattribute/set/text()"/>
				<xsl:value-of select="name"/>
			</xsl:variable>

			<!-- native method name -->
			<xsl:variable name="nativeSetterName" select="concat('__', $setterName)" />
	
			<xsl:call-template name="javaPublicAttributeSetterDeclaration">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="typeName" select="$resolvedType" />
			</xsl:call-template>

			<xsl:text> { </xsl:text>
			<xsl:value-of select="$nativeSetterName" />
			<xsl:text>(</xsl:text>
			<xsl:if test="not(@static)">
				<xsl:text>object.pointer, </xsl:text>
			</xsl:if>
			<xsl:text>value</xsl:text>

			<!-- pass instance pointer if necessary -->
			<xsl:if test="./@passedBy='pointer' or ./@passedBy='reference'">
				<xsl:text>.object.pointer</xsl:text>
			</xsl:if>

			<xsl:text>);</xsl:text>
			<xsl:text>}&#10;</xsl:text>
	
			<!-- native -->
			<xsl:if test="@static">
				<xsl:text>static </xsl:text>
			</xsl:if>
			<xsl:text>private final native void </xsl:text>
			<xsl:value-of select="$nativeSetterName" />
			<xsl:text>(</xsl:text>
			<xsl:if test="not(@static)">
				<xsl:text>long _pointer_, </xsl:text>
			</xsl:if>

			<!-- para type -->
			<xsl:choose>
				<xsl:when test="./@passedBy='pointer' or ./@passedBy='reference'">
					<xsl:text>long</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="$resolvedType"/>
				</xsl:otherwise>
			</xsl:choose>

			<xsl:text> value);&#10;&#10;</xsl:text>
		</xsl:if>

	</xsl:template>


<xsl:template name="javaPublicAttributeGetterDeclaration">
		<xsl:param name="config" />
		<xsl:param name="typeName" />

		<xsl:variable name="getterName">
			<xsl:value-of select="$config/config/meta/publicattribute/get/text()"/>
			<xsl:value-of select="name"/>
		</xsl:variable>

		<!-- impl -->
		<xsl:text>&#10;&#10;</xsl:text>
		<xsl:text>// getter for public attribute </xsl:text><xsl:value-of select="name"/>
		<xsl:text>&#10;public </xsl:text>
		<xsl:if test="@static">
			<xsl:text>static </xsl:text>
		</xsl:if>

		<!-- return type -->
		<xsl:choose>

			<!-- write pointer class -->
			<xsl:when test="(./@passedBy='pointer' or ./@passedBy='reference')">
				<xsl:call-template name="javaPointerClass">
					<xsl:with-param name="config" select="$config" />
					<xsl:with-param name="param" select="." />
					<xsl:with-param name="typeName" select="$typeName" />
				</xsl:call-template>
			</xsl:when>

			<xsl:otherwise>
				<xsl:value-of select="$typeName" />
			</xsl:otherwise>
		</xsl:choose>

		<xsl:text> </xsl:text>
		<xsl:value-of select="$getterName" />
		<xsl:text>()</xsl:text>
	</xsl:template>

	<xsl:template name="javaPublicAttributeSetterDeclaration">
		<xsl:param name="config" />
		<xsl:param name="typeName" />

		<!-- method name -->
		<xsl:variable name="setterName">
			<xsl:value-of select="$config/config/meta/publicattribute/set/text()"/>
			<xsl:value-of select="name"/>
		</xsl:variable>

		<!-- impl -->
		<xsl:text>&#10;&#10;</xsl:text>
		<xsl:text>// setter for public attribute </xsl:text><xsl:value-of select="name"/>
		<xsl:text>&#10;</xsl:text>
		<xsl:if test="@static">
			<xsl:text>static </xsl:text>
		</xsl:if>
		<xsl:text>public void </xsl:text>
		<xsl:value-of select="$setterName" />
		<xsl:text>(</xsl:text>

		<!-- param type -->
		<xsl:choose>
			<xsl:when test="(./@passedBy='pointer' or ./@passedBy='reference')">
				<xsl:call-template name="javaPointerClass">
					<xsl:with-param name="config" select="$config" />
					<xsl:with-param name="param" select="." />
					<xsl:with-param name="typeName" select="$typeName" />
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$typeName" />
			</xsl:otherwise>
		</xsl:choose>

		<xsl:text> value)</xsl:text>
	</xsl:template>


</xsl:stylesheet>
