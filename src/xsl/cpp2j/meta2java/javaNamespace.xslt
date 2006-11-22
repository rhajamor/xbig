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

	<xsl:import href="javaClass.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generation of types inside a namespace</xd:short>
	</xd:doc>

	<xsl:template name="javaNamespace">
		<xsl:param name="meta_ns_name" />
		<xsl:param name="outdir" />
		<xsl:param name="config" />

		<!-- iterate over child namespaces -->
		<xsl:for-each select="namespace">
			<xsl:call-template name="javaNamespace">
				<xsl:with-param name="meta_ns_name" select="@name" />
				<xsl:with-param name="outdir" select="$outdir" />
				<xsl:with-param name="config" select="$config" />
			</xsl:call-template>
		</xsl:for-each>

		<!-- extract Java namespace from configuration -->
		<!-- <xsl:variable name="java_ns_name"
			select="$config/config/java/namespaces/namespace[@name=$meta_ns_name]" /> -->
		<!-- TODO: put org.xbig into config -->
		<xsl:variable name="java_ns_name"
			select="concat('org.xbig.', replace($meta_ns_name,'::', '.'))" />

		<!-- if no mapping in Java configuration vailable -->
		<xsl:if test="empty($java_ns_name)">
			<xsl:message terminate="yes">
				ERROR: no package name for
				<xsl:value-of select="$meta_ns_name" />
			</xsl:message>
		</xsl:if>

		<!-- transform Java namespace to directory name -->
		<xsl:variable name="java_ns_dir"
			select="replace($java_ns_name,'\.', '/')" />


		<!-- iteration over all classes inside current namespace -->
		<xsl:for-each select="class">

			<!-- compose filename of current class -->
			<xsl:variable name="filename"
				select="concat($outdir, '/', $java_ns_dir, '/',@name,'.java')" />

			<!-- open Java file -->
			<xsl:result-document href="{$filename}"
				format="textOutput">

				<!-- write package -->
				<xsl:text>package&#32;</xsl:text>
				<xsl:value-of select="$java_ns_name" />
				<xsl:text>;&#10;&#10;</xsl:text>


				<!-- write class implementation -->
				<xsl:call-template name="javaClass">
					<xsl:with-param name="config" select="$config" />
					<xsl:with-param name="class" select="." />
				</xsl:call-template>

			</xsl:result-document>

		</xsl:for-each>

	</xsl:template>
</xsl:stylesheet>
