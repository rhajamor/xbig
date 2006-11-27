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
	xmlns:xd="http://www.pnp-software.com/XSLTdoc">

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single original class or struct</xd:short>
	</xd:doc>

	<xsl:template name="javaPublicAttribute">
		<xsl:param name="config" />


		<!-- getter -->
		<!-- method name -->
		<xsl:variable name="getterName">
			<xsl:value-of select="$config/config/meta/publicattribute/get/text()"/>
			<xsl:value-of select="name"/>
		</xsl:variable>

		<!-- native method name -->
		<xsl:variable name="nativeGetterName" select="concat('__', $getterName)" />

		<!-- impl -->
		<xsl:text>&#10;&#10;</xsl:text>
		<xsl:text>// getter for public attribute </xsl:text><xsl:value-of select="name"/>
		<xsl:text>&#10;public </xsl:text>
		<xsl:if test="@static">
			<xsl:text>static </xsl:text>
		</xsl:if>
		<xsl:value-of select="type"/>
		<xsl:text> </xsl:text>
		<xsl:value-of select="$getterName" />
		<xsl:text>() { return </xsl:text>
		<xsl:value-of select="$nativeGetterName" />
		<xsl:text>(</xsl:text>
		<xsl:if test="not(@static)">
			<xsl:text>object.pointer</xsl:text>
		</xsl:if>
		<xsl:text>);</xsl:text>
		<xsl:text>}&#10;</xsl:text>

		<!-- native -->
		<xsl:if test="@static">
			<xsl:text>static </xsl:text>
		</xsl:if>
		<xsl:text>private final native </xsl:text>
		<xsl:value-of select="type"/>
		<xsl:text> </xsl:text>
		<xsl:value-of select="$nativeGetterName" />
		<xsl:text>(</xsl:text>
		<xsl:if test="not(@static)">
			<xsl:text>long _pointer_</xsl:text>
		</xsl:if>
		<xsl:text>);&#10;&#10;</xsl:text>


		<!-- setter -->
		<xsl:if test="not(@const)">
			<!-- method name -->
			<xsl:variable name="setterName">
				<xsl:value-of select="$config/config/meta/publicattribute/set/text()"/>
				<xsl:value-of select="name"/>
			</xsl:variable>
	
			<!-- native method name -->
			<xsl:variable name="nativeSetterName" select="concat('__', $setterName)" />
	
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
			<xsl:value-of select="type"/>
			<xsl:text> value) { </xsl:text>
			<xsl:value-of select="$nativeSetterName" />
			<xsl:text>(</xsl:text>
			<xsl:if test="not(@static)">
				<xsl:text>object.pointer, </xsl:text>
			</xsl:if>
			<xsl:text>value);</xsl:text>
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
			<xsl:value-of select="type"/>
			<xsl:text> value);&#10;&#10;</xsl:text>
		</xsl:if>


	</xsl:template>
</xsl:stylesheet>
