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

	<xsl:import href="../../util/metaTypeInfo.xslt" />

	<xd:doc type="stylesheet">
		<xd:short>Generate mapping of a single type</xd:short>
	</xd:doc>

	<xsl:template name="jniType">
		<xsl:param name="config" />
		<xsl:param name="param" />

		<xsl:variable name="type_info">
			<xsl:call-template name="metaFirstTypeInfo">
				<xsl:with-param name="root"
					select="$config/config/cpp/jni/types" />
				<xsl:with-param name="param" select="$param" />
			</xsl:call-template>
		</xsl:variable>

		<!-- print first type found in result list -->
		<xsl:value-of select="$type_info/type/@jni" />

	</xsl:template>

</xsl:stylesheet>
