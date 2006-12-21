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
	xmlns:xd="http://www.pnp-software.com/XSLTdoc">

	<xsl:import href="javaNativeMethod.xslt" />
	<xsl:import href="javaAccessMethod.xslt" />
	<xsl:import href="javaPublicAttribute.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single original class or struct</xd:short>
	</xd:doc>

	<xsl:template name="javaClass">
		<xsl:param name="config" />
		<xsl:param name="class" />
		<xsl:param name="buildFile" />

		<!-- shortcut for class configuration -->
		<xsl:variable name="class_config"
			select="$config/config/java/class" />

		<!-- shortcut for class name -->
		<xsl:variable name="class_name" select="$class/@name" />

		<!-- find out if we create an inner class -->
		<xsl:variable name="isInnerClass" select="../name() eq 'class' or ../name() eq 'struct'"/>

		<!-- write class declaration -->
		<xsl:text>public </xsl:text>
		<xsl:if test="$isInnerClass">
			<xsl:text>static </xsl:text>
		</xsl:if>
		<xsl:text>class&#32;</xsl:text>
		<xsl:value-of select="$class_name" />

		<!-- base class -->
		<xsl:choose>
			<!-- native inheritance -->
			<xsl:when test="$class/inherits">
				<xsl:text>&#32;extends &#32;</xsl:text>
				<xsl:value-of select="$class/inherits/baseClass" />
			</xsl:when>

			<!-- configured inheritance -->
			<xsl:when test="$class_config/inherits">
				<xsl:text>&#32;extends&#32;</xsl:text>
				<xsl:value-of select="$class_config/inherits" />
			</xsl:when>

			<xsl:otherwise>
			</xsl:otherwise>
		</xsl:choose>

		<!-- start class content -->
		<xsl:text>&#32;{&#10;</xsl:text>

		<!-- create static initializer -->
		<xsl:if test="not($isInnerClass)">
			<xsl:text>static { System.loadLibrary("</xsl:text>
			<xsl:value-of select="$buildFile/project/property[@name='lib.name']/@value"/>
			<xsl:text>-xbig");}&#10;</xsl:text>
		</xsl:if>

		<!-- handle inner classes & structs -->
		<xsl:for-each select="class">
			<xsl:call-template name="javaClass">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="class" select="." />
				<xsl:with-param name="buildFile" select="$buildFile" />
			</xsl:call-template>
		</xsl:for-each>
		<xsl:for-each select="struct">
			<xsl:call-template name="javaClass">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="class" select="." />
				<xsl:with-param name="buildFile" select="$buildFile" />
			</xsl:call-template>
		</xsl:for-each>

		<!-- if additional class content defined in configuration -->
		<xsl:if test="$class_config/content">
			<xsl:text>&#32;</xsl:text>
			<xsl:value-of
				select="replace($class_config/content,'#classname#', $class_name)" />
		</xsl:if>

		<!-- handling of member functions -->
		<xsl:for-each select="function">

			<xsl:call-template name="javaAccessMethod">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="class" select="$class" />
				<xsl:with-param name="method" select="." />
			</xsl:call-template>

			<xsl:call-template name="javaNativeMethod">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="class" select="$class" />
				<xsl:with-param name="method" select="." />
			</xsl:call-template>

		</xsl:for-each>

		<!-- handling of public attributes -->
		<xsl:for-each select="variable">
			<xsl:call-template name="javaPublicAttribute">
				<xsl:with-param name="config" select="$config" />
			</xsl:call-template>
		</xsl:for-each>

		<!-- close class declaration  -->
		<xsl:text>};&#10;&#10;</xsl:text>

	</xsl:template>

</xsl:stylesheet>
