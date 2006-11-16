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

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xd="http://www.pnp-software.com/XSLTdoc"
	xmlns:exsl="http://exslt.org/common" extension-element-prefixes="exsl"
	version="2.0">

	<xsl:import href="cppNamespace.xslt" />

	<xd:doc type="stylesheet">
		<xd:author>Frank Bielig</xd:author>
		<xd:copyright>OneStepAhead AG</xd:copyright>
		<xd:short>Transforms the meta layer to C++</xd:short>
		<xd:detail>
			This Stylesheet generates the JNI functions to access the
			existing C++ library.
		</xd:detail>
	</xd:doc>

	<xsl:output method="text" name="textOutput" />

	<!-- global Parameters -->

	<xsl:param name="config" />
	<xsl:param name="include_dir" />
	<xsl:param name="lib_dir" />

	<!-- local variables -->


	<!-- main transformation process for generating C++ -->
	<xsl:template match="/*[local-name() = 'meta']">

		<xsl:result-document href="" format="textOutput">

			<!-- iteration over all available namespaces -->
			<xsl:for-each select="namespace">

				<xsl:call-template name="cppNamespace">
					<xsl:with-param name="meta_ns_name" select="@name" />
					<xsl:with-param name="include_dir"
						select="$include_dir" />
					<xsl:with-param name="lib_dir" select="$lib_dir" />
					<xsl:with-param name="config" select="$config" />
				</xsl:call-template>

			</xsl:for-each>

			<xsl:text>done</xsl:text>
		</xsl:result-document>

	</xsl:template>

</xsl:stylesheet>

