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
		<xd:short>Generate mapping of a single original class</xd:short>
	</xd:doc>

	<xsl:template name="javaReturnMethodImpl">
		<xsl:param name="config" />
		<xsl:param name="class" />
		<xsl:param name="method" />

		<!-- shortcut for static attribute -->
		<xsl:variable name="static" select="$method/@static" />

		<!-- write return statement -->
		<xsl:text>&#32;return&#32;</xsl:text>

		<!-- create Pointer object when necessary -->
		<xsl:if test="$method/@passedBy='pointer' or $method/@passedBy='reference'">
			<xsl:text>new&#32;</xsl:text>
			<xsl:call-template name="javaPointerClass">
				<xsl:with-param name="config" select="$config" />
				<xsl:with-param name="param" select="$method" />
			</xsl:call-template>
			<xsl:text>(new&#32;InstancePointer(</xsl:text>
		</xsl:if>

		<!-- create native object when necessary -->
		<xsl:if test="xbig:isClassOrStruct($method/type, $class, $root)">
			<xsl:text>new&#32;</xsl:text>
			<xsl:value-of select="xbig:getFullJavaClassAndNotInterfaceName($method/type, $class, $root, $config)"/>
			<xsl:text>(new&#32;InstancePointer(</xsl:text>
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
			<xsl:with-param name="callingNativeMethod" select="'true'" />
		</xsl:call-template>

		<!-- close Pointer and InstancePointer c-tor calls -->
		<xsl:if test="$method/@passedBy='pointer' or $method/@passedBy='reference'">
			<xsl:text>))</xsl:text>
		</xsl:if>
		<xsl:if test="xbig:isClassOrStruct($method/type, $class, $root)">
			<xsl:text>)), true</xsl:text>
		</xsl:if>

		<!-- close parameter list -->
		<xsl:text>);</xsl:text>

	</xsl:template>

</xsl:stylesheet>
