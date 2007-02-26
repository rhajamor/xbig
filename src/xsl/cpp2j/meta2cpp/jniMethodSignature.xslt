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

	<xsl:import href="jniParameterListSignature.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Javah like signature for methods</xd:short>
	</xd:doc>

	<xd:doc type="template">
		<xd:short>Iterates over parameters and calls jniParameterSignature. Calls it for return type, too.
			Used for comments.
		</xd:short>
		<xd:param name="config">config file.</xd:param>
		<xd:param name="method">meta function element to be processed.</xd:param>
		<xd:param name="class">meta class which contains method.</xd:param>
	</xd:doc>
	<xsl:template name="jniMethodSignature">
		<xsl:param name="config" />
		<xsl:param name="method" />
		<xsl:param name="class" />

		<!-- write begin of parameter list -->
		<xsl:text>(</xsl:text>

		<xsl:call-template name="jniParameterListSignature">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="method" select="$method" />
			<xsl:with-param name="class" select="$class" />
		</xsl:call-template>

		<!-- write end of parameter list -->
		<xsl:text>)</xsl:text>

		<!-- shortcut of return type -->
		<xsl:variable name="return_type"
			select="if($method/type) then $method/type else 'void'" />

		<!-- write signature of return type -->
		<xsl:call-template name="jniParameterSignature">
			<xsl:with-param name="config" select="$config" />
			<xsl:with-param name="meta_type" select="$return_type" />
			<xsl:with-param name="class" select="$class" />
		</xsl:call-template>

	</xsl:template>

</xsl:stylesheet>
