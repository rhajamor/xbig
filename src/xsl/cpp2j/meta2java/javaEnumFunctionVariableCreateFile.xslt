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
	xmlns:xd="http://www.pnp-software.com/XSLTdoc"
	xmlns:xbig="http://xbig.sourceforge.net/XBiG">

	<xsl:import href="javaEnum.xslt" />
	<xsl:import href="../../util/path.xslt"/>

	<xd:doc type="stylesheet">
		<xd:short>Generation of a file for global or in-namespace enums, functions and variables</xd:short>
	</xd:doc>

	<xsl:template name="javaEnumFunctionVariableCreateFile">
		<xsl:param name="meta_ns_name" />
		<xsl:param name="outdir" />
		<xsl:param name="config" />
		<xsl:param name="buildFile" />

		<!-- check if this is necessary -->
		<xsl:if test="enumeration or function or variable or
					  root()//namespace/enumeration or
					  root()//namespace/function or
					  root()//namespace/variable ">

			<!-- transform Java namespace to directory name -->
			<xsl:variable name="java_ns_dir"
						  select="replace($meta_ns_name,'\.', '/')" />
	
			<!-- get class name from config -->
			<xsl:variable name="filenameStub" select="$config/config/java/class/enumwrapper"/>
	
			<!-- compose filename -->
			<xsl:variable name="filename"
				select="concat($outdir, '/', $java_ns_dir, '/', $filenameStub, '.java')" />
	
			<!-- open Java file -->
			<xsl:result-document href="{xbig:toFileURL($filename)}"
				format="textOutput">
	
				<!-- write package -->
				<xsl:text>package&#32;</xsl:text>
				<xsl:value-of select="$meta_ns_name" />
				<xsl:text>;&#10;&#10;</xsl:text>

				<!-- create wrapper class -->
				<xsl:text>public class </xsl:text>
				<xsl:value-of select="$filenameStub"/>
				<xsl:text>{&#10;</xsl:text>

				<!-- creating static initializer -->
				<xsl:text>static { System.loadLibrary("</xsl:text>
				<xsl:value-of select="$buildFile/project/property[@name='lib.name']/@value"/>
				<xsl:text>-xbig");}&#10;</xsl:text>

				<xsl:if test="enumeration or root()//namespace/enumeration">
					<xsl:text>public static final int[] ENUM_VALUES = _getEnumValues();&#10;</xsl:text>
					<xsl:text>private static native int[] _getEnumValues();&#10;</xsl:text>
					<xsl:text>&#10;</xsl:text>
	
					<!-- create enums -->
					<xsl:for-each select="enumeration and root()//namespace/enumeration">
						<xsl:call-template name="javaEnum"/>
					</xsl:for-each>
				</xsl:if>

				<!-- close wrapper class -->
				<xsl:text>};&#10;</xsl:text>
			</xsl:result-document>

		</xsl:if>

	</xsl:template>
</xsl:stylesheet>
