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
	
-->

<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions"
	xmlns:xdt="http://www.w3.org/2005/xpath-datatypes"
	xmlns:xd="http://www.pnp-software.com/XSLTdoc">

	<xsl:import href="cppFileHeader.xslt" />
	<xsl:import href="cppMethodImpl.xslt" />
	<xsl:import href="../meta2java/javaUtil.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generation of types inside a namespace</xd:short>
	</xd:doc>

	<xsl:template name="cppClassFileImpl">
		<xsl:param name="config" />
		<xsl:param name="class" />
		<xsl:param name="class_prefix" />
		<xsl:param name="header_filename" />
		<xsl:param name="helper_methods" />

		<!-- write file header with copyright information -->
		<xsl:call-template name="cppFileHeader">
			<xsl:with-param name="config" select="$config" />
		</xsl:call-template>

		<!-- include all JNI utility functions -->
		<xsl:text>&#10;&#10;</xsl:text>
		<xsl:text>// use base library for cpp2j</xsl:text>
		<xsl:text>&#10;#include "jni_base_all.h"&#10;</xsl:text>

		<!-- include current header file if available -->
		<xsl:if test="$header_filename">
			<xsl:text>&#10;</xsl:text>
			<xsl:text>// import declaration of all functions</xsl:text>
			<xsl:text>&#10;#include "</xsl:text>
			<xsl:value-of select="$header_filename" />
			<xsl:text>"&#10;</xsl:text>
		</xsl:if>

		<!-- include header files from original library -->
		<xsl:text>&#10;</xsl:text>
		<xsl:text>// import header files of original library</xsl:text>
		<xsl:text>&#10;</xsl:text>
		<xsl:for-each select="$class/includes">

			<!-- test if a file is included multiple times -->
			<xsl:variable name="currentInclude" select="."/>
			<xsl:choose>
				<!-- using id trick like in metaInheritedMethods.xslt -->
				<xsl:when test="count(../includes[text() = $currentInclude/text()]) > 1">
					<xsl:if test="count(../includes[$currentInclude][position() = 1] | $currentInclude) = 1">
						<xsl:choose>
							<xsl:when test="@local = 'no'">
								<xsl:text>#include &lt;</xsl:text>
								<xsl:value-of select="text()"/>
								<xsl:text>&gt;&#10;</xsl:text>
							</xsl:when>
							<xsl:otherwise>
								<xsl:text>#include "</xsl:text>
								<xsl:value-of select="text()"/>
								<xsl:text>"&#10;</xsl:text>
							</xsl:otherwise>
						</xsl:choose>
					</xsl:if>
				</xsl:when>

				<!-- file is included only once -->
				<xsl:otherwise>
					<xsl:choose>
						<xsl:when test="@local = 'no'">
							<xsl:text>#include &lt;</xsl:text>
							<xsl:value-of select="text()"/>
							<xsl:text>&gt;&#10;</xsl:text>
						</xsl:when>
						<xsl:otherwise>
							<xsl:text>#include "</xsl:text>
							<xsl:value-of select="text()"/>
							<xsl:text>"&#10;</xsl:text>
						</xsl:otherwise>
					</xsl:choose>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:for-each>
		<xsl:text>&#10;</xsl:text>

		<!-- iterate through all member functions -->
		<!-- <xsl:for-each select="$class/function"> -->
		<!-- get methods, with inherited -->
		<xsl:variable name="inheritedMethods">
			<xsl:call-template name="findRelevantInheritedMethods">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="class" select="$class" />
			</xsl:call-template>
		</xsl:variable>
		
		<!-- remove function that are equal to java -->		
		<xsl:variable name="inheritedMethodsForJava">
			<xsl:call-template name="getValidMethodList">
				<xsl:with-param name="functionNodeList" select="$inheritedMethods"/>
			</xsl:call-template>
		</xsl:variable>

		<!-- generate method impl -->
 		<xsl:for-each select="$inheritedMethodsForJava/function">

			<xsl:call-template name="cppMethodImpl">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="class_prefix"
					select="$class_prefix" />
				<xsl:with-param name="class" select="$class" />
				<xsl:with-param name="method" select="." />
			</xsl:call-template>

		</xsl:for-each>

		<!-- iterate through all helper functions -->
		<xsl:for-each select="$helper_methods/function">

			<xsl:call-template name="cppMethodImpl">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="class_prefix"
					select="$class_prefix" />
				<xsl:with-param name="class" select="$class" />
				<xsl:with-param name="method" select="." />
			</xsl:call-template>

		</xsl:for-each>
		
	</xsl:template>
</xsl:stylesheet>
