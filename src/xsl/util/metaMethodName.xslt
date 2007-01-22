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

	<xsl:import href="metaParameterListSignature.xslt" />

	<xd:doc type="stylesheet">
		<xd:short></xd:short>
	</xd:doc>

	<!-- method name prefix -->

	<xsl:template name="metaMethodName">
		<xsl:param name="config" />
		<xsl:param name="method" />
		<xsl:param name="escape" />

		<!-- shortcut to meta configuration -->
		<xsl:variable name="meta_config" select="$config/config/meta" />

		<!-- shortcut to method name configuration depending on constructor 
			or normal method -->
		<!-- <xsl:variable name="mcfg"
			select="if($method/type) then $meta_config/method/name else $meta_config/constructor/name" /> -->
		<xsl:variable name="mcfg">
			<xsl:choose>
				<xsl:when test="not($method/type)">
					<xsl:value-of select="$meta_config/constructor/name" />
				</xsl:when>
				<!-- destructor -->
				<xsl:when test="$method/name() = $meta_config/destructor/name">
					<xsl:value-of select="''" />
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="$meta_config/method/name"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- shortcut of given function name -->
		<xsl:variable name="org_method_name">
				<xsl:value-of select="$method/name"/>
		</xsl:variable>

		<!-- expand to fuel method name -->
		<xsl:variable name="method_name"
			select="concat($mcfg/prefix, $org_method_name, $mcfg/suffix)" />

		<!-- write meta signature if parameters available -->
		<xsl:variable name="method_params">
			<xsl:if test="count($method/parameters/parameter) > 0 and
						  (not($method/@public_attribute_setter) or 
						  $method/@public_attribute_setter ne 'true')">

				<!-- write parameter seperation -->
				<xsl:text>__</xsl:text>

				<!-- generate parameter signature list  -->
				<xsl:call-template name="metaParameterListSignature">
					<xsl:with-param name="config" select="$config" />
					<xsl:with-param name="method" select="$method" />
				</xsl:call-template>
			</xsl:if>
		</xsl:variable>

		<!-- create const suffix if special attribute available -->
		<xsl:variable name="const_suffix">
			<xsl:if test="$method/@const eq 'true'">
				<xsl:text>_const</xsl:text>
			</xsl:if>
		</xsl:variable>

		<!-- compose full method name -->
		<xsl:variable name="full_method_name"
			select="concat($method_name, $method_params, $const_suffix)" />

		<xsl:choose>
			<xsl:when test="$escape eq 'true'">
				<xsl:value-of
					select="replace($full_method_name, '_', '_1')" />
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$full_method_name" />
			</xsl:otherwise>
		</xsl:choose>

	</xsl:template>



	<xsl:template name="createElementForConstOverloadedMethod">
		<xsl:param name="config" />
		<xsl:param name="method" />

		<xsl:element name="function">
			<xsl:attribute name="virt">
				<xsl:value-of select="$method/@virt" />
			</xsl:attribute>
			<xsl:attribute name="visibility">
				<xsl:value-of select="$method/@visibility" />
			</xsl:attribute>
			<xsl:attribute name="static">
				<xsl:value-of select="$method/@static" />
			</xsl:attribute>
			<xsl:attribute name="const">
				<xsl:value-of select="$method/@const" />
			</xsl:attribute>
			<xsl:attribute name="passedBy">
				<xsl:value-of select="$method/@passedBy" />
			</xsl:attribute>

			<xsl:element name="type">
				<xsl:attribute name="const">
					<xsl:value-of select="$method/type/@const" />
				</xsl:attribute>
				<xsl:attribute name="constPointer">
					<xsl:value-of select="$method/type/@constPointer" />
				</xsl:attribute>
				<xsl:value-of select="$method/type" />
			</xsl:element>
			<xsl:element name="definition">
				<xsl:value-of select="$method/definition" />
			</xsl:element>
			<xsl:element name="name">
				<xsl:value-of select="$config/config/java/constoverloading/prefix" />
				<xsl:value-of select="$method/name" />
				<xsl:value-of select="$config/config/java/constoverloading/suffix" />
			</xsl:element>

			<xsl:element name="parameters">
				<xsl:copy-of select="$method/parameters/*" />
			</xsl:element>

		</xsl:element>

	</xsl:template>

</xsl:stylesheet>
