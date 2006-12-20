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

	<xsl:import href="javaClass.xslt" />
	<xsl:import href="../../util/path.xslt"/>

	<xd:doc type="stylesheet">
		<xd:short>Generation of the first few lines of a .java file</xd:short>
	</xd:doc>

	<xsl:template name="javaClassFileStub">
		<xsl:param name="java_ns_dir" />
		<xsl:param name="java_ns_name" />
		<xsl:param name="outdir" />
		<xsl:param name="config" />
		<xsl:param name="buildFile" />

		<!-- compose filename of current class -->
		<xsl:variable name="filename"
			select="concat($outdir, '/', $java_ns_dir, '/',@name,'.java')" />

		<!-- open Java file -->
		<xsl:result-document href="{xbig:toFileURL($filename)}"
			format="textOutput">

			<!-- write package -->
			<xsl:text>package&#32;</xsl:text>
			<xsl:value-of select="$java_ns_name" />
			<xsl:text>;&#10;&#10;</xsl:text>

			<!-- write import -->
			<xsl:text>&#32;</xsl:text>
			<xsl:text>import org.xbig.base.*;&#32;</xsl:text>
			<xsl:text>import std.*;&#32;</xsl:text>
			<xsl:text>&#32;</xsl:text>


			<!-- write class implementation -->
			<xsl:call-template name="javaClass">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="class" select="." />
				<xsl:with-param name="buildFile" select="$buildFile" />
			</xsl:call-template>

		</xsl:result-document>
	</xsl:template>
</xsl:stylesheet>
