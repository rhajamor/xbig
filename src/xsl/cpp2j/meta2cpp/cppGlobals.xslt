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

	<xsl:import href="cppClassFileHeader.xslt" />
	<xsl:import href="cppClassFileImpl.xslt" />
	<xsl:import href="cppCreateHelperMethods.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generation of types outside a namespace</xd:short>
	</xd:doc>

	<xsl:template name="cppGlobals">
		<xsl:param name="meta_ns_name" />
		<xsl:param name="include_dir" />
		<xsl:param name="lib_dir" />
		<xsl:param name="config" />

		<!-- compute java package name -->
		<xsl:variable name="java_ns_name"
				select="replace($config/config/java/namespaces/packageprefix/text(), '\.', '_')" />

		<!-- transform Java namespace to unique prefix -->
		<xsl:variable name="ns_prefix"
			select="replace($java_ns_name,'\.', '_')" />

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

		<!-- generate description for helper methods -->
		<xsl:variable name="helper_methods">
			<xsl:call-template name="cppCreateHelperMethods">
				<xsl:with-param name="config" select="$config" />
			</xsl:call-template>
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

	</xsl:template>
</xsl:stylesheet>
