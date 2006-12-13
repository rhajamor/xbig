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
	xmlns:fn="http://www.w3.org/2005/xpath-methods"
	xmlns:xdt="http://www.w3.org/2005/xpath-datatypes"
	xmlns:xd="http://www.pnp-software.com/XSLTdoc"
	xmlns:xbig="http://xbig.sourceforge.net/XBiG">

	<xsl:import href="cppMethodDeclaration.xslt" />

	<xd:doc type="stylesheet">
		<xd:short></xd:short>
	</xd:doc>

	<!-- ************************************************************ -->
	<!-- xbig:cpp-param(config, param) -->
	<!-- ************************************************************ -->

	<xsl:function name="xbig:cpp-param" as="xs:string">
		<xsl:param name="config" />
		<xsl:param name="param" as="xs:string" />

		<!-- shortcut for variable names configuration -->
		<xsl:variable name="cfg"
			select="$config/config/cpp/variables/cpp" />

		<xsl:value-of
			select="concat($cfg/prefix/@name, $param, $cfg/suffix/@name)" />

	</xsl:function>

	<!-- ************************************************************ -->
	<!-- xbig:cpp-type(config, param) -->
	<!-- ************************************************************ -->

	<xsl:function name="xbig:cpp-type" as="xs:string">
		<xsl:param name="config" />
		<xsl:param name="param" />

		<!-- shortcut to type conversion configurations -->
		<xsl:variable name="type_info">
			<xsl:call-template name="metaFirstTypeInfo">
				<xsl:with-param name="root"
					select="$config/config/cpp/jni/types" />
				<xsl:with-param name="param" select="$param" />
			</xsl:call-template>
		</xsl:variable>

		<!-- if explicit conversion given -->
		<xsl:if test="$type_info/type/@cpp">
			<xsl:value-of select="$type_info/type/@cpp" />
		</xsl:if>

		<!-- no explicit conversion given, compose from parameter information -->
		<xsl:if test="not($type_info/type/@cpp)">

			<xsl:variable name="type"
				select="if($param/type) then $param/type else 'void'" />

			<xsl:variable name="const"
				select="if($param/type/@const eq 'true') then 'const ' else ''" />

			<xsl:variable name="pass">
				<xsl:choose>
					<xsl:when test="$param/@passedBy eq 'pointer'">
						<xsl:text>*</xsl:text>
					</xsl:when>
					<xsl:when test="$param/@passedBy eq 'reference'">
						<xsl:text>&amp;</xsl:text>
					</xsl:when>
					<xsl:when test="$param/type/@array">
						<xsl:value-of select="$param/type/@array" />
					</xsl:when>
				</xsl:choose>
			</xsl:variable>

			<xsl:value-of select="concat($const,$type,$pass)" />
		</xsl:if>

	</xsl:function>

	<!-- ************************************************************ -->
	<!-- xbig:jni-to-cpp(config, class, method, param) -->
	<!-- ************************************************************ -->

	<xsl:function name="xbig:jni-to-cpp" as="xs:string">
		<xsl:param name="config" />
		<xsl:param name="class" />
		<xsl:param name="method" />
		<xsl:param name="param" />

		<!-- shortcut to type conversion configurations -->
		<xsl:variable name="type_info">
			<xsl:call-template name="metaFirstTypeInfo">
				<xsl:with-param name="root"
					select="$config/config/cpp/jni/types" />
				<xsl:with-param name="param" select="$param" />
			</xsl:call-template>
		</xsl:variable>

		<!-- shortcut for parameter name -->
		<xsl:variable name="param_name" select="$param/name" />

		<!-- no conversion function available -->
		<xsl:if test="not($type_info/type/jni2cpp)">
			<xsl:value-of select="$param_name" />
		</xsl:if>

		<!-- if conversion function available -->
		<xsl:if test="$type_info/type/jni2cpp">
			<!-- perform general code transformations -->
			<xsl:variable name="code1"
				select="xbig:code($config, $type_info/type/jni2cpp, $class, $method)" />

			<!-- replace parameter name in code fragment -->
			<xsl:variable name="code2"
				select="replace($code1,'#jni_var#', $param_name)" />

			<!-- write conversion code -->
			<xsl:value-of select="$code2" />
		</xsl:if>

	</xsl:function>

	<!-- ************************************************************ -->
	<!-- xbig:cpp-to-jni(config, class, method, param) -->
	<!-- ************************************************************ -->

	<xsl:function name="xbig:cpp-to-jni" as="xs:string">
		<xsl:param name="config" />
		<xsl:param name="class" />
		<xsl:param name="method" />
		<xsl:param name="param" />
		<xsl:param name="name" />

		<!-- shortcut to type conversion configurations -->
		<xsl:variable name="type_info">
			<xsl:call-template name="metaFirstTypeInfo">
				<xsl:with-param name="root"
					select="$config/config/cpp/jni/types" />
				<xsl:with-param name="param" select="$param" />
			</xsl:call-template>
		</xsl:variable>

		<!-- shortcut for parameter name -->
		<xsl:variable name="param_name"
			select="if($name and not(empty($name))) then $name else $param/name" />

		<!-- no conversion function available -->
		<xsl:if test="not($type_info/type/cpp2jni)">
			<xsl:value-of select="$param_name" />
		</xsl:if>

		<!-- if conversion function available -->
		<xsl:if test="$type_info/type/cpp2jni">
			<!-- perform general code transformations -->
			<xsl:variable name="code1"
				select="xbig:code($config, $type_info/type/cpp2jni, $class, $method)" />

			<!-- replace parameter name in code fragment -->
			<xsl:variable name="code2"
				select="replace($code1,'#cpp_var#', $param_name)" />

			<!-- write conversion code -->
			<xsl:value-of select="$code2" />
		</xsl:if>

	</xsl:function>

	<!-- ************************************************************ -->
	<!-- xbig:cpp-replace(var, from, to) -->
	<!-- ************************************************************ -->

	<xsl:function name="xbig:cpp-replace" as="xs:string">
		<xsl:param name="var" as="xs:string" />
		<xsl:param name="from" as="xs:string" />
		<xsl:param name="to" as="xs:string" />

		<!-- prevent infinite recursion -->
		<xsl:choose>

			<xsl:when test="not(matches($to, $from)) and matches($var, $from)">
				<xsl:value-of select="replace($var, $from, $to)" />
			</xsl:when>

			<xsl:otherwise>
				<!-- return original value -->
				<xsl:value-of select="$var" />
			</xsl:otherwise>
		</xsl:choose>

	</xsl:function>

	<!-- ************************************************************ -->
	<!-- xbig:cpp-code(config, line, class, method) -->
	<!-- ************************************************************ -->

	<xsl:function name="xbig:code" as="xs:string">
		<xsl:param name="config" />
		<xsl:param name="line" />
		<xsl:param name="class" />
		<xsl:param name="method" />

		<!-- shortcut for full class name -->
		<xsl:variable name="full_class_name" select="$class/@fullName" />

		<!-- shortcut for variable names configuration -->
		<xsl:variable name="var_config"
			select="$config/config/cpp/variables" />

		<!-- original code line -->
		<xsl:variable name="org_line" select="normalize-space($line)" />

		<!-- replace method name -->
		<xsl:variable name="line0"
			select="xbig:cpp-replace($org_line, '#cpp_method#', $method/name)" />

		<!-- replace class name -->
		<xsl:variable name="line1"
			select="xbig:cpp-replace($line0, '#cpp_class#', $class/@fullName)" />

		<!-- replace JNI environment variable -->
		<xsl:variable name="line2"
			select="xbig:cpp-replace($line1, '#jni_env#', $var_config/jni/environment/@name)" />

		<!-- replace JNI class variable -->
		<xsl:variable name="line3"
			select="xbig:cpp-replace($line2, '#jni_class#', $var_config/jni/class/@name)" />

		<!-- replace JNI object variable -->
		<xsl:variable name="line4"
			select="xbig:cpp-replace($line3, '#jni_object#', $var_config/jni/object/@name)" />

		<!-- replace JNI pointer variable -->
		<xsl:variable name="line5"
			select="xbig:cpp-replace($line4, '#jni_pointer#', $var_config/jni/pointer/@name)" />

		<!-- replace library pointer variable -->
		<xsl:variable name="line6"
			select="xbig:cpp-replace($line5, '#cpp_this#', $var_config/cpp/object/@name)" />

		<!-- replace parameter conversions -->
		<xsl:variable name="line7">
			<xsl:choose>

				<xsl:when test="matches($line6, '#cpp_conversions#')">
					<!-- write code for parameter conversion -->
					<xsl:variable name="param_conversions">
						<xsl:call-template
							name="cppMethodParameterConversion">
							<xsl:with-param name="config"
								select="$config" />
							<xsl:with-param name="class"
								select="$class" />
							<xsl:with-param name="method"
								select="$method" />
						</xsl:call-template>
					</xsl:variable>
					<xsl:value-of
						select="xbig:cpp-replace($line6, '#cpp_conversions#', $param_conversions)" />
				</xsl:when>

				<xsl:otherwise>
					<xsl:value-of select="$line6" />
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- replace parameter list -->
		<xsl:variable name="line8">
			<xsl:choose>

				<xsl:when test="matches($line7, '#cpp_params#')">
					<!-- write code for parameter conversion -->
					<xsl:variable name="params">
						<!-- iterate through all parameters for calling -->
						<xsl:for-each
							select="$method/parameters/parameter">

							<!-- write parameter name -->
							<xsl:value-of
								select="xbig:cpp-param($config, name)" />

							<!-- write seperator if neccessary -->
							<xsl:if test="position() != last()">
								<xsl:text>,&#32;</xsl:text>
							</xsl:if>

						</xsl:for-each>
					</xsl:variable>
					<xsl:value-of
						select="xbig:cpp-replace($line7, '#cpp_params#', $params)" />
				</xsl:when>

				<xsl:otherwise>
					<xsl:value-of select="$line7" />
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- replace return statement -->
		<xsl:variable name="line9"
			select="if(matches($line8, '#cpp_return#')) then xbig:cpp-replace($line8, '#cpp_return#', xbig:cpp-to-jni($config, $class, $method, $method, '#cpp_return_var#')) else $line8" />

		<!-- replace return type -->
		<xsl:variable name="line10"
			select="xbig:cpp-replace($line9, '#cpp_return_type#', xbig:cpp-type($config, $method))" />

		<!-- replace class name -->
		<xsl:variable name="line11"
			select="xbig:cpp-replace($line10, '#cpp_return_var#', $var_config/cpp/result/@name)" />

		<!-- replace public attribute -->
		<!-- ARGH: WTF is this not working ????? -->
		<!-- <xsl:variable name="line12"
			select="xbig:cpp-replace($line11, '#cpp_attribute#', $method/attribute_name)" /> -->
		<xsl:variable name="line12"
			select="xbig:cpp-replace($line11, '#cpp_attribute#', substring($method/name, string-length($config/config/meta/publicattribute/get)+3))" />

		<xsl:variable name="result"
			select="xbig:cpp-replace(normalize-space($line12),'#nl#', $config/config/cpp/format/indent)" />

		<!-- real writing of code line -->
		<xsl:value-of select="$result" />
	</xsl:function>


</xsl:stylesheet>
