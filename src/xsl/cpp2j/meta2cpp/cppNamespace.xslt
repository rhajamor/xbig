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
	xmlns:fn="http://www.w3.org/2005/xpath-functions"
	xmlns:xdt="http://www.w3.org/2005/xpath-datatypes"
	xmlns:xd="http://www.pnp-software.com/XSLTdoc">

	<xsl:import href="cppClassFileHeader.xslt" />
	<xsl:import href="cppClassFileImpl.xslt" />
	<xsl:import href="../../util/utilXmlPrint.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generation of types inside a namespace</xd:short>
	</xd:doc>

	<xsl:template name="cppNamespace">
		<xsl:param name="meta_ns_name" />
		<xsl:param name="include_dir" />
		<xsl:param name="lib_dir" />
		<xsl:param name="config" />

		<!-- shortcut for java configuration -->
		<xsl:variable name="java_config" select="$config/config/java" />

		<!-- extract Java namespace from configuration -->
		<xsl:variable name="java_ns_name"
			select="$java_config/namespaces/namespace[@name=$meta_ns_name]" />

		<!-- if no mapping in Java configuration vailable -->
		<xsl:if test="empty($java_ns_name)">
			<xsl:message terminate="yes">
				ERROR: no package name for
				<xsl:value-of select="$meta_ns_name" />
			</xsl:message>
		</xsl:if>

		<!-- transform Java namespace to unique prefix -->
		<xsl:variable name="ns_prefix"
			select="replace($java_ns_name,'\.', '_')" />

		<!-- iteration over all classes inside current namespace -->
		<xsl:for-each select="class">

			<!-- compose filename of current class without suffix -->
			<xsl:variable name="class_prefix"
				select="concat($ns_prefix, '_',@name)" />

			<!-- compose filename of current class without suffix -->
			<xsl:variable name="main_filename"
				select="concat('class_', $class_prefix)" />

			<!-- compose basic header filename of current class -->
			<xsl:variable name="basic_header_filename"
				select="concat($main_filename,'.h')" />

			<!-- compose full header filename of current class -->
			<xsl:variable name="header_filename"
				select="concat($include_dir, '/', $basic_header_filename)" />

			<!-- compose implementation filename of current class -->
			<xsl:variable name="impl_filename"
				select="concat($lib_dir, '/', $main_filename,'.cpp')" />

			<!-- compose destructor name -->
			<xsl:variable name="destructor_name"
				select="$config/config/meta/destructor/name/text()" />

			<!-- generate description for helper methods -->
			<xsl:variable name="helper_methods">
				<xsl:element name="function">
					<xsl:attribute name="destructor">
						<xsl:text>true</xsl:text>
					</xsl:attribute>
					<xsl:attribute name="virt">
						<xsl:text>virtual</xsl:text>
					</xsl:attribute>
					<xsl:attribute name="visibility">
						<xsl:text>public</xsl:text>
					</xsl:attribute>
					<xsl:attribute name="static">
						<xsl:text>false</xsl:text>
					</xsl:attribute>
					<xsl:attribute name="const">
						<xsl:text>false</xsl:text>
					</xsl:attribute>
					<xsl:attribute name="passedBy">
						<xsl:text>value</xsl:text>
					</xsl:attribute>
					<xsl:element name="type">
						<xsl:text>void</xsl:text>
					</xsl:element>
					<xsl:element name="name">
						<xsl:value-of select="$destructor_name" />
					</xsl:element>
					<xsl:element name="definition">
						<xsl:value-of
							select="concat(@fullName, '::', $destructor_name)" />
					</xsl:element>
				</xsl:element>
			</xsl:variable>

			<!-- open header file -->
			<xsl:result-document href="{$header_filename}"
				format="textOutput">

				<!-- write header file -->
				<xsl:call-template name="cppClassFileHeader">
					<xsl:with-param name="config" select="$config" />
					<xsl:with-param name="class" select="." />
					<xsl:with-param name="class_prefix"
						select="$class_prefix" />
					<xsl:with-param name="helper_methods"
						select="$helper_methods" />
				</xsl:call-template>

			</xsl:result-document>



			<!-- open implementation file -->
			<xsl:result-document href="{$impl_filename}"
				format="textOutput">

				<!-- write file header with copyright information -->
				<xsl:call-template name="cppClassFileImpl">
					<xsl:with-param name="config" select="$config" />
					<xsl:with-param name="class" select="." />
					<xsl:with-param name="class_prefix"
						select="$class_prefix" />
					<xsl:with-param name="header_filename"
						select="$basic_header_filename" />
					<xsl:with-param name="helper_methods"
						select="$helper_methods" />
				</xsl:call-template>

			</xsl:result-document>

		</xsl:for-each>

	</xsl:template>



</xsl:stylesheet>


