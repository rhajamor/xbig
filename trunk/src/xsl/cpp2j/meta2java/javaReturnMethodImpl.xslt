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
	xmlns:xbig="http://xbig.sourceforge.net/XBiG">

	<xd:doc type="stylesheet">
		<xd:short>Generates body of a public java method with return type.</xd:short>
	</xd:doc>

	<xd:doc type="template">
		<xd:short>Generates return type conversions, like instantiation of new NativeObjects.
				Creates native method name and passes parameters with conversions, 
				like access of InstancePointer.
		</xd:short>
		<xd:param name="config">config file.</xd:param>
		<xd:param name="class">class which contains current method.</xd:param>
		<xd:param name="method">method to be implemented.</xd:param>
	</xd:doc>
	<xsl:template name="javaReturnMethodImpl">
		<xsl:param name="config" />
		<xsl:param name="class" />
		<xsl:param name="method" />

		<!-- resolve typedefs -->
		<xsl:variable name="resolvedType" select="xbig:resolveTypedef($method/type, $class, $root)"/>

		<xsl:variable name="fullTypeName" select="$resolvedType"/>

		<!-- extract jni type depending on meta type, const/non-const, pass type
			 needed for some ifs -->
		<xsl:variable name="type_info">
			<xsl:call-template name="metaFirstTypeInfo">
				<xsl:with-param name="root" 
					select="$config/config/java/types" />
				<xsl:with-param name="param" select="." />
				<xsl:with-param name="typeName" select="$resolvedType" />
			</xsl:call-template>
		</xsl:variable>

		<!-- shortcut for static attribute -->
		<xsl:variable name="static" select="$method/@static" />

		<!-- class used for pointer pointer -->
		<xsl:variable name="pointerPointerClass" select="'NativeObjectPointer'"/>

		<!-- remember if an object is returned by value -->
		<xsl:variable name="objectReturnedByValue" select="if($method/@passedBy = 'value' and
      						count($config/config/java/types/type[@meta = $resolvedType]) = 0
      						and $config/config/java/passObjectsReturnedByValueAsParameters = 'yes'
      						and not(xbig:isEnum($resolvedType, $class, $root)))
      						then true() else false()"/>

		<!-- if an object is returned by value or a parametrized template is returned -->
		<xsl:choose>
			<xsl:when test="$objectReturnedByValue = true() or contains($method/type, '&lt;')">
				<xsl:text>&#32;&#32;</xsl:text>
				<xsl:value-of select="$config/config/java/returnValueAsParameterName"/>
				<xsl:text>.</xsl:text>
				<xsl:text>delete</xsl:text>
				<xsl:text>();&#10;</xsl:text>
				<xsl:text>&#32;&#32;</xsl:text>
				<xsl:value-of select="$config/config/java/returnValueAsParameterName"/>
				<xsl:text>.setInstancePointer</xsl:text>
			</xsl:when>

			<xsl:otherwise>
				<!-- write return statement -->
				<xsl:text>&#32;return&#32;</xsl:text>
			</xsl:otherwise>
		</xsl:choose>

		<!-- create Pointer object when necessary -->
		<xsl:if test="(($method/@passedBy='pointer' and not($resolvedType='char')) or
						($method/@passedBy='reference' and not(xbig:isTypeConst($method))))
					  and ($type_info/type/@java or $resolvedType = 'void')">
			<xsl:text>new&#32;</xsl:text>
			<xsl:variable name="fullTypeNameWithPointer">
				<xsl:call-template name="javaPointerClass">
					<xsl:with-param name="config" select="$config" />
					<xsl:with-param name="param" select="$method" />
					<xsl:with-param name="typeName" select="$resolvedType" />
				</xsl:call-template>
			</xsl:variable>
			<xsl:choose>
				<xsl:when test="$method/type/@pointerPointer = 'true'">
					<xsl:value-of select="concat(
									$pointerPointerClass, '&lt;')"/>
					<xsl:value-of select="$fullTypeNameWithPointer"/>
					<xsl:value-of select="'&gt;'"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="$fullTypeNameWithPointer"/>
				</xsl:otherwise>
			</xsl:choose>
			<xsl:text>(new&#32;InstancePointer(</xsl:text>
		</xsl:if>

		<xsl:choose>
			<!-- if this is a template without type parameters,
				 e.g. Ogre::SharedPtr::operator=(SharedPtr) -->
			<xsl:when test="xbig:isTemplate($fullTypeName, $root) and not(contains($method/type, '&lt;'))">
				<xsl:choose>
					<!-- pointer pointer -->
					<xsl:when test="$method/type/@pointerPointer = 'true'">
						<xsl:text>new&#32;</xsl:text>
						<xsl:value-of select="concat(
										$pointerPointerClass, '&lt;')"/>
						<xsl:value-of select="xbig:getFullJavaName(
												$fullTypeName, $class, $root, $config)"/>
						<xsl:value-of select="'&gt;'"/>
					</xsl:when>

					<!-- object returned by value -->
					<xsl:when test="$objectReturnedByValue = true() or contains($method/type, '&lt;')">
					</xsl:when>

					<xsl:otherwise>
						<xsl:text>new&#32;</xsl:text>
						<xsl:value-of select="if($class/@originalTypedefFullName)
											then
												xbig:getFullJavaClassAndNotInterfaceName(
												$class/@originalTypedefFullName, $class, $root, $config)
											else
												xbig:getFullJavaClassAndNotInterfaceName(
												$class/@fullName, $class, $root, $config)"/>
					</xsl:otherwise>
				</xsl:choose>
				<xsl:text>(new&#32;InstancePointer(</xsl:text>
			</xsl:when>

			<!-- if this is a class, struct or template typedef -->
			<xsl:when test="xbig:isTemplateTypedef($fullTypeName, $class, $root) or
							xbig:isClassOrStruct($fullTypeName, $class, $root) or
							contains($method/type, '&lt;')">
				<xsl:choose>
					<!-- pointer pointer -->
					<xsl:when test="$method/type/@pointerPointer = 'true'">
						<xsl:text>new&#32;</xsl:text>
						<xsl:value-of select="concat(
										$pointerPointerClass, '&lt;')"/>
						<xsl:value-of select="xbig:getFullJavaName(
												$fullTypeName, $class, $root, $config)"/>
						<xsl:value-of select="'&gt;'"/>
					</xsl:when>

					<!-- object returned by value -->
					<xsl:when test="$objectReturnedByValue = true() or contains($method/type, '&lt;')">
					</xsl:when>

					<xsl:otherwise>
						<xsl:text>new&#32;</xsl:text>
						<xsl:value-of select="xbig:getFullJavaClassAndNotInterfaceName(
												$fullTypeName, $class, $root, $config)"/>
					</xsl:otherwise>
				</xsl:choose>
				<xsl:text>(new&#32;InstancePointer(</xsl:text>
			</xsl:when>
		</xsl:choose>

		<!-- get enum when necessary -->
		<xsl:if test="xbig:isEnum($fullTypeName, $class, $root)">
			<xsl:value-of select="xbig:getFullJavaClassAndNotInterfaceName(
									$fullTypeName, $class, $root, $config)"/>
			<xsl:text>.toEnum(</xsl:text>
		</xsl:if>

		<!-- create a ULongLong object for "unsigned long long" -->
		<xsl:if test="$resolvedType = 'unsigned long long'">
			<xsl:text>new&#32;</xsl:text>
			<xsl:value-of select="$type_info/type/@genericParameter"/>
			<xsl:text>(</xsl:text>
		</xsl:if>

		<!-- write native method name -->
		<xsl:call-template name="metaMethodName">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="method" select="$method" />
		</xsl:call-template>

		<!-- open parameter list -->
		<xsl:text>(</xsl:text>

		<!-- write object pointer as first argument if not static -->
		<xsl:if test="$static ne 'true'">

			<!-- write object pointer as first argument -->
			<xsl:text>this.object.pointer</xsl:text>

			<!-- write seperator if more parameters available -->
			<xsl:if test="count($method/parameters/parameter) > 0">
				<xsl:text>,</xsl:text>
			</xsl:if>
			
		</xsl:if>

		<!-- write paremeters -->
		<xsl:call-template name="javaMethodParameterList">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="class" select="$class" />
			<xsl:with-param name="method" select="$method" />
			<xsl:with-param name="writingNativeMethod" select="false()" />
			<xsl:with-param name="callingNativeMethod" select="true()" />
		</xsl:call-template>

		<!-- create a ULongLong object for "unsigned long long" -->
		<xsl:if test="$resolvedType = 'unsigned long long'">
			<xsl:text>)</xsl:text>
		</xsl:if>

		<!-- close Pointer and InstancePointer c-tor calls -->
		<xsl:if test="(($method/@passedBy='pointer' and not($resolvedType='char')) or ($method/@passedBy='reference' and not(xbig:isTypeConst($method))))					  
					  and $type_info/type/@java">
			<xsl:text>))</xsl:text>
		</xsl:if>
		<xsl:if test="contains($resolvedType, '&lt;')"><!-- for returned parametrized templates -->
			<xsl:text>))</xsl:text>
			<!-- we have copied the returned object to the heap -->
			<xsl:if test="$method/@passedBy = 'value'">
				<xsl:text>, false</xsl:text>
			</xsl:if>
			<!-- not copied to heap, but parametrized templates as return values are always passed -->
			<xsl:if test="$method/@passedBy != 'value'">
				<xsl:text>, true</xsl:text>
			</xsl:if>
		</xsl:if>
		<xsl:if test="xbig:isTemplateTypedef($fullTypeName, $class, $root)">
			<xsl:text>))</xsl:text>
			<!-- we have copied the returned object to the heap -->
			<xsl:if test="$method/@passedBy = 'value'">
				<xsl:text>, false</xsl:text>
			</xsl:if>
		</xsl:if>
		<xsl:if test="xbig:isClassOrStruct($fullTypeName, $class, $root)">
			<xsl:text>))</xsl:text>
			<!-- we have copied the returned object to the heap -->
			<xsl:if test="$method/@passedBy = 'value'">
				<xsl:text>, false</xsl:text>
			</xsl:if>
		</xsl:if>
		<xsl:if test="xbig:isEnum($fullTypeName, $class, $root)">
			<xsl:text>)</xsl:text>
		</xsl:if>

		<!-- close parameter list -->
		<xsl:text>);</xsl:text>

	</xsl:template>

</xsl:stylesheet>
