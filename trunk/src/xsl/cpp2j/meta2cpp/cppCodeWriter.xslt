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
	xmlns:fn="http://www.w3.org/2005/xpath-methods"
	xmlns:xdt="http://www.w3.org/2005/xpath-datatypes"
	xmlns:xd="http://www.pnp-software.com/XSLTdoc"
	xmlns:xbig="http://xbig.sourceforge.net/XBiG"
	xmlns:str="http://exslt.org/strings">

	<xsl:import href="cppMethodDeclaration.xslt" />
	<xsl:import href="../../exslt/str.split.template.xsl" />

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
		<xsl:param name="class" />

		<!-- resolve typedefs -->
		<xsl:variable name="resolvedType">
			<xsl:choose>
				<!-- c-tors don't have a type -->
				<xsl:when test="not($param/type)">
					<xsl:value-of select="'long'"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="xbig:resolveTypedef($param/type, $class, $root)"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- shortcut to type conversion configurations -->
		<xsl:variable name="type_info">
			<xsl:call-template name="metaExactTypeInfo">
				<xsl:with-param name="root"
					select="$config/config/cpp/jni/types" />
				<xsl:with-param name="param" select="$param" />
				<xsl:with-param name="typeName" select="$resolvedType" />
			</xsl:call-template>
		</xsl:variable>

		<!-- ensure valid signature -->
		<xsl:if test="count($type_info) != 1">
			<xsl:message terminate="yes">
				ERROR: no exact type info for meta type '
				<xsl:value-of select="$param/type" />
				' found.
			</xsl:message>
		</xsl:if>

		<xsl:variable name="const"
			select="if($param/type/@const eq 'true') then 'const ' else ''" />

		<!-- add '*' for pointer pointer -->
		<xsl:variable name="pointerPointer">
			<xsl:choose>
				<xsl:when test="$param/type/@pointerPointer = 'true'">
					<xsl:value-of select="'*'"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="''"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- if explicit conversion given -->
		<xsl:if test="$type_info/type/@cpp">
			<xsl:choose>
				<!-- references need different conversion and return types -->
				<xsl:when test="$type_info/type/@pass='reference' and $param/definition">
					<!-- if const -->
					<xsl:choose>
					<xsl:when test="$param/type/@const eq 'true'">
						<xsl:value-of select="concat('const ', $type_info/type/@returntype)" />
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="$type_info/type/@returntype" />
					</xsl:otherwise>
					</xsl:choose>
				</xsl:when>
				<xsl:otherwise>
					<!-- if const -->
					<!-- TODO check for const pointers (int* const) -->
					<xsl:value-of select="concat($const, $type_info/type/@cpp, $pointerPointer)"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:if>

		<!-- no explicit conversion given, compose from parameter information -->
		<xsl:if test="not($type_info/type/@cpp)">

			<xsl:variable name="type">
				<xsl:choose>
					<xsl:when test="not($param/type)">
						<xsl:value-of select="'void'"/>
					</xsl:when>
					<xsl:when test="contains($resolvedType, '&lt;')">
						<xsl:value-of select="concat(xbig:getFullTemplateName($resolvedType, $class, $root)
												, '*')"/>
					</xsl:when>
					<xsl:when test="xbig:isTemplateTypedef($resolvedType, $class, $root)">
						<xsl:value-of select="concat(xbig:getFullTypeName($resolvedType, $class, $root)
												, '*')"/>
					</xsl:when>
					<xsl:when test="xbig:isClassOrStruct($resolvedType, $class, $root)">
						<xsl:value-of select="concat(xbig:getFullTypeName($resolvedType, $class, $root)
												, '*')"/>
					</xsl:when>
					<xsl:when test="xbig:isEnum($param/type, $class, $root)">
						<xsl:value-of select="xbig:getFullTypeName($resolvedType, $class, $root)"/>
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="$resolvedType"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:variable>

			<xsl:variable name="pass">
				<xsl:choose>
					<xsl:when test="$param/@passedBy eq 'pointer' and $type_info/type/@cpp">
						<xsl:text>*</xsl:text>
					</xsl:when>
					<xsl:when test="$param/@passedBy eq 'reference' and $type_info/type/@cpp">
						<xsl:text>&amp;</xsl:text>
					</xsl:when>
					<xsl:when test="$param/type/@array">
						<xsl:value-of select="$param/type/@array" />
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="''" />
					</xsl:otherwise>
				</xsl:choose>
			</xsl:variable>

			<xsl:value-of select="concat($const, $type, $pass, $pointerPointer)"/>
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

		<!-- resolve typedefs -->
		<xsl:variable name="resolvedType" select="xbig:resolveTypedef($param/type, $class, $root)"/>

		<!-- shortcut to type conversion configurations -->
		<xsl:variable name="type_info">
			<xsl:call-template name="metaExactTypeInfo">
				<xsl:with-param name="root"
					select="$config/config/cpp/jni/types" />
				<xsl:with-param name="param" select="$param" />
				<xsl:with-param name="typeName" select="$resolvedType" />
			</xsl:call-template>
		</xsl:variable>

		<!-- shortcut for parameter name -->
		<xsl:variable name="param_name" select="$param/name" />

		<!-- find out if we have a pointer pointer pointer -->
		<xsl:variable name="pointerPointerAddOn">
			<xsl:choose>
				<xsl:when test="$param/type/@pointerPointer = 'true'">
					<xsl:value-of select="'*'"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="''"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- no conversion function available -->
		<xsl:if test="not($type_info/type/jni2cpp)">
			<xsl:choose>

				<!-- if this type is a parametrized template -->
				<xsl:when test="contains($resolvedType, '&lt;')">
					<xsl:variable name="part1" select="'reinterpret_cast&lt; '"/>
					<xsl:variable name="part2" select="xbig:getFullTemplateName(
														$resolvedType, $class, $root)"/>
					<xsl:variable name="part3" select="$pointerPointerAddOn"/>
					<xsl:variable name="part4" select="'* &gt;('"/>
					<xsl:variable name="part5" select="$param_name"/>
					<xsl:variable name="part6" select="')'"/>
					<xsl:value-of select="concat($part1, $part2, $part3, $part4, $part5, $part6)"/>
				</xsl:when>

				<!-- if this is a typedef for a template -->
				<xsl:when test="xbig:isTemplateTypedef($resolvedType, $class, $root)">
					<xsl:variable name="part1" select="'reinterpret_cast&lt; '"/>
					<xsl:variable name="part2" select="xbig:getFullTypeName($resolvedType, $class, $root)"/>
					<xsl:variable name="part3" select="$pointerPointerAddOn"/>
					<xsl:variable name="part4" select="'* &gt;('"/>
					<xsl:variable name="part5" select="$param_name"/>
					<xsl:variable name="part6" select="')'"/>
					<xsl:value-of select="concat($part1, $part2, $part3, $part4, $part5, $part6)"/>
				</xsl:when>

				<!-- test for enums -->
				<xsl:when test="xbig:isEnum($resolvedType, $class, $root)">
					<xsl:value-of select="
						concat('(', xbig:getFullTypeName($resolvedType, $class, $root), ')', $param_name)"/>
				</xsl:when>

				<!-- if this type is a class or struct -->
				<xsl:when test="xbig:isClassOrStruct($resolvedType, $class, $root)">
					<xsl:variable name="part1" select="'reinterpret_cast&lt; '"/>
					<xsl:variable name="part2" select="xbig:getFullTypeName($resolvedType, $class, $root)"/>
					<xsl:variable name="part3" select="$pointerPointerAddOn"/>
					<xsl:variable name="part4" select="'* &gt;('"/>
					<xsl:variable name="part5" select="$param_name"/>
					<xsl:variable name="part6" select="')'"/>
					<xsl:value-of select="concat($part1, $part2, $part3, $part4, $part5, $part6)"/>
				</xsl:when>

				<xsl:otherwise>
					<xsl:value-of select="$param_name" />
				</xsl:otherwise>
			</xsl:choose>
		</xsl:if>

		<!-- if conversion function available -->
		<xsl:if test="$type_info/type/jni2cpp">
			<!-- perform general code transformations -->
			<xsl:variable name="code1"
				select="xbig:code($config, $type_info/type/jni2cpp, $class, $method)"/>

			<!-- add the pointer pointer '*' -->
			<xsl:variable name="code2" select="replace($code1, '[\*]', concat('*', $pointerPointerAddOn))"/>

			<!-- replace parameter name in code fragment -->
			<xsl:variable name="code3"
				select="replace($code2,'#jni_var#', $param_name)"/>

			<!-- write conversion code -->
			<xsl:value-of select="$code3"/>
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

		<!-- resolve typedefs -->
		<xsl:variable name="resolvedType" select="xbig:resolveTypedef($param/type, $class, $root)"/>

		<!-- shortcut to type conversion configurations -->
		<xsl:variable name="type_info">
			<xsl:call-template name="metaExactTypeInfo">
				<xsl:with-param name="root"
					select="$config/config/cpp/jni/types" />
				<xsl:with-param name="param" select="$param" />
				<xsl:with-param name="typeName" select="$resolvedType" />
			</xsl:call-template>
		</xsl:variable>

		<!-- shortcut for parameter name -->
		<xsl:variable name="param_name"
			select="if($name and not(empty($name))) then $name else $param/name" />

		<!-- no conversion function available -->
		<xsl:if test="not($type_info/type/cpp2jni)">

			<!-- resolve typedefs for return type -->
			<xsl:variable name="resolvedReturnType"
					select="xbig:resolveTypedef($method/type, $class, $root)"/>

			<xsl:choose>
				<!-- if this type is a parametrized template -->
				<xsl:when test="contains($resolvedType, '&lt;')">
					<xsl:variable name="returnCast">
						<!-- produces warning: address of local variable ‘_cpp_result’ returned -->
						<xsl:value-of select="'reinterpret_cast&lt;jlong&gt;('"/>
						<xsl:value-of select="$param_name"/>
						<xsl:value-of select="')'"/>
					</xsl:variable>
					<xsl:value-of select="$returnCast"/>
				</xsl:when>

				<!-- if this is a typedef for a template -->
				<xsl:when test="xbig:isTemplateTypedef($resolvedType, $class, $root)">
					<xsl:variable name="returnCast">
						<!-- produces warning: address of local variable ‘_cpp_result’ returned -->
						<xsl:value-of select="'reinterpret_cast&lt;jlong&gt;('"/>
						<xsl:value-of select="$param_name"/>
						<xsl:value-of select="')'"/>
					</xsl:variable>
					<xsl:value-of select="$returnCast"/>
				</xsl:when>

				<!-- if this method returns an object -->
				<xsl:when test="xbig:isClassOrStruct($resolvedReturnType, $class, $root)">
					<xsl:variable name="returnCast">
						<!-- produces warning: address of local variable ‘_cpp_result’ returned -->
						<xsl:value-of select="'reinterpret_cast&lt;jlong&gt;('"/>
						<xsl:value-of select="$param_name"/>
						<xsl:value-of select="')'"/>
					</xsl:variable>
					<xsl:value-of select="$returnCast"/>
				</xsl:when>

				<xsl:otherwise>
					<xsl:value-of select="$param_name" />
				</xsl:otherwise>
			</xsl:choose>
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
		<xsl:variable name="line0">
			<!-- if const overloading is used, we have to find out the original name -->
			<xsl:choose>
				<xsl:when test="$method/@const = 'true' and not($class/function
						[name = $method/name][@const = 'true'])">
					<xsl:variable name="methodNameWithoutPrefix" select="substring-after(
						$method/name, $config/config/java/constoverloading/prefix)"/>
					<xsl:variable name="methodName" select="substring-before(
						$methodNameWithoutPrefix, $config/config/java/constoverloading/suffix)"/>
					<xsl:value-of select="xbig:cpp-replace($org_line, '#cpp_method#', $methodName)" />
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="xbig:cpp-replace($org_line, '#cpp_method#', $method/name)" />
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- replace class name -->
		<xsl:variable name="line1">
			<xsl:choose>
				<!-- if we call a const method -->
				<xsl:when test="$method/@const = 'true'">
					<xsl:value-of  select="xbig:cpp-replace($line0, '#cpp_class#', concat(
								'const ', $class/@fullName))"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of  select="xbig:cpp-replace($line0, '#cpp_class#', $class/@fullName)"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

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
					  select="xbig:cpp-replace($line4, '#jni_pointer#', $var_config/jni/pointer/@name)"/>

		<!-- replace library pointer variable -->
		<xsl:variable name="line6"
			select="xbig:cpp-replace($line5, '#cpp_this#', $var_config/cpp/object/@name)">
		</xsl:variable>

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
							<xsl:if test="@passedBy='reference' or ((
										  xbig:isClassOrStruct(xbig:resolveTypedef(./type, $class, $root)
										  		, $class, $root) or
										  xbig:isTemplateTypedef(xbig:resolveTypedef(./type, $class, $root)
										  		, $class, $root) or
										  contains(type, '&lt;')
										  ) and @passedBy != 'pointer')">
								<xsl:value-of select="'*'" />
							</xsl:if>
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
			select="if(matches($line8, '#cpp_return#')) then xbig:cpp-replace(
				$line8, '#cpp_return#', xbig:cpp-to-jni(
				$config, $class, $method, $method, '#cpp_return_var#')) else $line8" />

		<!-- replace return type -->
		<xsl:variable name="line10"
			select="xbig:cpp-replace($line9, '#cpp_return_type#', xbig:cpp-type($config, $method, $class))"/>

		<!-- replace class name -->
		<xsl:variable name="line11"
			select="xbig:cpp-replace($line10, '#cpp_return_var#', $var_config/cpp/result/@name)" />

		<!-- replace public attribute -->
		<xsl:variable name="line12">
			<xsl:choose>
				<xsl:when test="$method/attribute_name">
					<xsl:value-of select="xbig:cpp-replace(
										  $line11, '#cpp_attribute#', $method/attribute_name)"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="$line11"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- replace name of class the method was inherited from -->
		<xsl:variable name="classThisMethodWasInheritedFrom">
			<xsl:choose>
				<!-- if this is a typedef for a template -->
				<xsl:when test="$class/typeparameters">
					<xsl:value-of select="$class/@fullName"/>
				</xsl:when>

				<!-- a normal class -->
				<xsl:otherwise>
					<xsl:variable name="methodClassWithPreStuffTokens">
						<xsl:call-template name="str:split">
							<xsl:with-param name="string" select="$method/definition" />
							<xsl:with-param name="pattern" select="' '" />
						</xsl:call-template>
					</xsl:variable>
					<xsl:variable name="methodClassTokens">
						<xsl:call-template name="str:split">
							<xsl:with-param name="string"
								select="$methodClassWithPreStuffTokens/*[last()]" />
							<xsl:with-param name="pattern" select="'::'" />
						</xsl:call-template>
					</xsl:variable>
					<xsl:variable name="methodClassFullName">
						<xsl:for-each select="$methodClassTokens/*">
							<xsl:if test="position() != last()">
								<xsl:value-of select="." />
							</xsl:if>
							<xsl:if test="(position() != last()) and (position() != last()-1)">
								<xsl:value-of select="'::'" />
							</xsl:if>
						</xsl:for-each>
					</xsl:variable>
					<xsl:value-of select="$methodClassFullName"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>
		
		<xsl:variable name="line13"
			select="xbig:cpp-replace($line12, '#cpp_inherited_method_class#', 
										$classThisMethodWasInheritedFrom)" />

		<!-- if an object is returned, we need it's address -->
		<xsl:variable name="line14">
			<xsl:variable name="searchFor" select="'#optional_return_conversion#'"/>

			<xsl:variable name="replaceWith">
				<xsl:choose>
					<xsl:when test="not($method/type)">
						<xsl:value-of select="''" />
					</xsl:when>

					<xsl:when test="(xbig:isClassOrStruct(xbig:resolveTypedef($method/type, $class, $root)
										, $class, $root) or
									xbig:isTemplateTypedef(xbig:resolveTypedef($method/type, $class, $root)
										, $class, $root) or
									contains($method/type, '&lt;')
									) and $method/@passedBy != 'pointer'">
						<xsl:variable name="cppThis" select="$var_config/cpp/object/@name"/>
							<xsl:choose>

								<!-- we have to move local objects to the heap -->
								<xsl:when test="$method/@passedBy = 'value'">
									<xsl:value-of select="'new '"/>
									<xsl:variable name="resolvedType"
												select="xbig:resolveTypedef($method/type, $class, $root)"/>
									<xsl:choose>
										<xsl:when test="contains($resolvedType, '&lt;')">
											<xsl:value-of select="xbig:getFullTemplateName(
															$resolvedType, $class, $root)"/>
										</xsl:when>
										<xsl:otherwise>
											<xsl:value-of select="xbig:getFullTypeName(
															$resolvedType, $class, $root)"/>
										</xsl:otherwise>
						 			</xsl:choose>
									<xsl:value-of select="'('"/>
								</xsl:when>

								<!-- passed by reference -->
								<xsl:otherwise>
									<xsl:value-of select="'&amp; '"/>
								</xsl:otherwise>
							</xsl:choose>
					</xsl:when>

					<xsl:otherwise>
						<xsl:value-of select="''" />
					</xsl:otherwise>
				</xsl:choose>
			</xsl:variable>
			<xsl:value-of select="replace($line13, $searchFor, $replaceWith)" />
		</xsl:variable>

		<!-- create closing paranthesis -->
		<xsl:variable name="line15">
			<xsl:choose>
				<xsl:when test="not($method/type)">
					<xsl:value-of select="replace($line14, '#optional_closing_bracket#', '')" />
				</xsl:when>
				<xsl:when test="(xbig:isClassOrStruct(xbig:resolveTypedef($method/type, $class, $root)
									, $class, $root) or
								xbig:isTemplateTypedef(xbig:resolveTypedef($method/type, $class, $root)
									, $class, $root) or
								contains($method/type, '&lt;')
								) and $method/@passedBy = 'value'">
					<xsl:value-of select="replace($line14, '#optional_closing_bracket#', ')')" />
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="replace($line14, '#optional_closing_bracket#', '')" />
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>
		

		<xsl:variable name="result"
			select="xbig:cpp-replace(normalize-space($line15),'#nl#', $config/config/cpp/format/indent)" />

		<!-- real writing of code line -->
		<xsl:value-of select="$result" />
	</xsl:function>


</xsl:stylesheet>
