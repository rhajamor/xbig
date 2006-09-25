<?xml version="1.0" encoding="UTF-8"?>

<!--
	
	This source file is part of cpp2j
	(The JNI bindings for C++)
	For the latest info, see http://www.cpp2j.org/
	
	Copyright (c) 2006 OneStepAhead AG, Stuttgart
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
	xmlns:fn="http://www.w3.org/2005/xpath-methods"
	xmlns:xdt="http://www.w3.org/2005/xpath-datatypes"
	xmlns:xd="http://www.pnp-software.com/XSLTdoc">

	<xsl:import href="jniMethodSignature.xslt" />
	<xsl:import href="../../util/metaMethodName.xslt" />
	<xsl:import href="jniType.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generation of types inside a namespace</xd:short>
	</xd:doc>

	<xsl:template name="cppMethodDeclaration">
		<xsl:param name="config" />
		<xsl:param name="class_prefix" />
		<xsl:param name="method" />

		<!-- write method comment -->
		<xsl:call-template name="cppMethodDeclarationComment">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="class_prefix" select="$class_prefix" />
			<xsl:with-param name="method" select="$method" />
		</xsl:call-template>

		<!-- write real method real declaration -->
		<xsl:call-template name="cppRealMethodDeclaration">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="class_prefix" select="$class_prefix" />
			<xsl:with-param name="method" select="$method" />
		</xsl:call-template>



	</xsl:template>



	<xd:doc type="stylesheet">
		<xd:short>
			Generate method comments prior method declarations
		</xd:short>
	</xd:doc>
	<xsl:template name="cppMethodDeclarationComment">
		<xsl:param name="config" />
		<xsl:param name="class_prefix" />
		<xsl:param name="method" />

		<!-- shortcut for method name -->
		<xsl:variable name="method_name"
			select="normalize-space($method/name)" />

		<!-- shortcut for method definition -->
		<xsl:variable name="method_def"
			select="normalize-space($method/definition)" />

		<!-- shortcut for class name -->
		<xsl:variable name="class_name"
			select="replace($class_prefix, '_', '.')" />

		<!-- open comment in a single line -->
		<xsl:text>&#10;&#10;/*</xsl:text>

		<!-- write current class name -->
		<xsl:text>&#10;&#32;*&#32;Class:</xsl:text>
		<xsl:text>&#32;&#32;&#32;&#32;&#32;&#32;</xsl:text>
		<xsl:value-of select="$class_name" />

		<!-- write current method name -->
		<xsl:text>&#10;&#32;*&#32;Method:</xsl:text>
		<xsl:text>&#32;&#32;&#32;&#32;&#32;</xsl:text>
		<xsl:value-of select="$method_name" />
		<xsl:text>()</xsl:text>

		<!-- write current method type -->
		<xsl:text>&#10;&#32;*&#32;Type:</xsl:text>
		<xsl:text>&#32;&#32;&#32;&#32;&#32;&#32;&#32;</xsl:text>
		<xsl:choose>
			<xsl:when test="not($method/type)">
				<xsl:text>constructor</xsl:text>
			</xsl:when>
			<xsl:when test="$method/@destructor eq 'true'">
				<xsl:text>destructor</xsl:text>
			</xsl:when>
			<xsl:when test="$method/@static eq 'true'">
				<xsl:text>static method</xsl:text>
			</xsl:when>
			<xsl:when test="$method/@virt eq 'virtual'">
				<xsl:text>virtual method</xsl:text>
			</xsl:when>
			<xsl:when test="$method/@virt eq 'pure-virtual'">
				<xsl:text>pure virtual method</xsl:text>
			</xsl:when>
			<xsl:otherwise>
				<xsl:text>non-virtual method</xsl:text>
			</xsl:otherwise>
		</xsl:choose>

		<!-- write current method definition -->
		<xsl:text>&#10;&#32;*&#32;Definition:</xsl:text>
		<xsl:text>&#32;</xsl:text>
		<xsl:value-of select="$method_def" />
		<xsl:text>()</xsl:text>

		<!-- write signature of this method -->
		<xsl:text>&#10;&#32;*&#32;Signature:</xsl:text>
		<xsl:text>&#32;&#32;</xsl:text>
		<xsl:call-template name="jniMethodSignature">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="method" select="$method" />
		</xsl:call-template>

		<!-- finish comment in a single line -->
		<xsl:text>&#10; */&#10;</xsl:text>

	</xsl:template>


	<xd:doc type="stylesheet">
		<xd:short>
			Generate method comments prior method declarations
		</xd:short>
	</xd:doc>
	<xsl:template name="cppRealMethodDeclaration">
		<xsl:param name="config" />
		<xsl:param name="class_prefix" />
		<xsl:param name="method" />

		<!-- shortcut for method name -->
		<xsl:variable name="method_name"
			select="normalize-space($method/name)" />

		<!-- shortcut for return type, take long for constructors -->
		<xsl:variable name="return_type"
			select="if($method/type) then normalize-space($method/type) else 'long'" />

		<!-- shortcut for static property -->
		<xsl:variable name="static"
			select="normalize-space($method/@static)" />

		<!-- write export keyword -->
		<xsl:text>&#10;JNIEXPORT</xsl:text>

		<!-- write return type -->
		<xsl:text>&#32;</xsl:text>
		<xsl:call-template name="jniType">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="param" select="$method" />
		</xsl:call-template>

		<!-- write call method keyword -->
		<xsl:text>&#32;JNICALL</xsl:text>

		<!-- write class name (including JNI header and namespace) -->
		<xsl:text>&#32;Java_</xsl:text>
		<xsl:value-of select="$class_prefix" />
		<xsl:text>_</xsl:text>

		<!-- write parameter meta signature -->
		<xsl:call-template name="metaMethodName">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="method" select="$method" />
			<xsl:with-param name="escape" select="'true'" />
		</xsl:call-template>

		<!-- begin of parameter declaration -->
		<xsl:text>&#32;(</xsl:text>

		<!-- write environment parameter -->
		<xsl:text>&#10;&#32;&#32;</xsl:text>
		<xsl:text>JNIEnv*&#32;</xsl:text>
		<xsl:value-of
			select="$config/config/cpp/variables/jni/environment/@name" />
		<xsl:text>, /* interface pointer */</xsl:text>

		<!-- write object parameter -->
		<xsl:choose>

			<!-- in case of a static method or constructor write class object access -->
			<xsl:when test="($static = 'true') or not($method/type)">
				<!-- write class access parameter -->
				<xsl:text>&#10;&#32;&#32;</xsl:text>
				<xsl:text>jclass&#32;</xsl:text>
				<xsl:value-of
					select="$config/config/cpp/variables/jni/class/@name" />
				<xsl:if test="count(parameters/parameter) &gt; 0">
					<xsl:text>,</xsl:text>
				</xsl:if>
				<xsl:text>&#32;&#32;/* class pointer */</xsl:text>
			</xsl:when>

			<!-- in case of a normal method write object access -->
			<xsl:otherwise>
				<!-- write class access parameter -->
				<xsl:text>&#10;&#32;&#32;</xsl:text>
				<xsl:text>jobject&#32;</xsl:text>
				<xsl:value-of
					select="$config/config/cpp/variables/jni/object/@name" />
				<xsl:text>, /* Java object */</xsl:text>
				<xsl:text>&#10;&#32;&#32;</xsl:text>
				<xsl:text>jlong&#32;</xsl:text>
				<xsl:value-of
					select="$config/config/cpp/variables/jni/pointer/@name" />
				<xsl:if test="count(parameters/parameter) &gt; 0">
					<xsl:text>,</xsl:text>
				</xsl:if>
				<xsl:text>&#32;/* C++ pointer */</xsl:text>
			</xsl:otherwise>

		</xsl:choose>

		<!-- iterator through all parameters -->
		<xsl:for-each select="$method/parameters/parameter">

			<!-- write indent -->
			<xsl:text>&#10;&#32;&#32;</xsl:text>

			<!-- write parameter type -->
			<xsl:call-template name="jniType">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="param" select="." />
			</xsl:call-template>

			<!-- seperator type and name -->
			<xsl:text>&#32;</xsl:text>

			<!-- write parameter name -->
			<xsl:value-of select="name" />

			<!-- if another parameter follows, write seperator -->
			<xsl:if test="position()!=last()">
				<xsl:text>,&#32;</xsl:text>
			</xsl:if>

		</xsl:for-each>


		<!-- end of parameter declaration -->
		<xsl:text>&#10;)</xsl:text>

	</xsl:template>

</xsl:stylesheet>
