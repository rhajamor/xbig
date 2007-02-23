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
	<xsl:import href="javaInterface.xslt" />
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
		
		<xsl:message>Generating Java code for class <xsl:value-of select="./@fullName"/></xsl:message>
		<!-- test if we handle a class or an enum -->
		<xsl:choose>
			<xsl:when test="./name() = 'enumeration'">
				<!-- compose filename of current class -->
				<xsl:variable name="filename"
					select="concat($outdir, '/', $java_ns_dir, '/', @name, '.java')" />

				<!-- open Java file -->
				<xsl:result-document href="{xbig:toFileURL($filename)}"
					format="textOutput">

					<xsl:call-template name="javaFileFirstContent">
						<xsl:with-param name="java_ns_name" select="$java_ns_name" />
						<xsl:with-param name="config" select="$config" />
					</xsl:call-template>

					<!-- write class implementation -->
					<xsl:call-template name="javaEnum">
						<xsl:with-param name="enum" select="." />
						<xsl:with-param name="buildFile" select="$buildFile" />
					</xsl:call-template>

				</xsl:result-document>
			</xsl:when>

			<!-- generate no interface for templates
				 there are problems with primitive types as type parameters
				 when passed by pointer and problems with templates making
				 assumptions on there type parameter like the OGRE IteratorWrappers -->
			<!-- reenabled
			<xsl:when test="./@template">
			</xsl:when>
			 -->

			<!-- classes -->
			<xsl:otherwise>
				<!-- generate Interface -->
				<!-- compose filename of current class -->
				<xsl:variable name="ifFilename"
					select="concat($outdir, '/',
							$java_ns_dir, '/',
							$config/config/java/interface/prefix,
							@name,
							$config/config/java/interface/suffix,
							'.java')" />

				<!-- open Java file -->
				<xsl:result-document href="{xbig:toFileURL($ifFilename)}"
					format="textOutput">

					<xsl:call-template name="javaFileFirstContent">
						<xsl:with-param name="java_ns_name" select="$java_ns_name" />
						<xsl:with-param name="config" select="$config" />
					</xsl:call-template>

					<!-- write interface implementation -->
					<xsl:call-template name="javaInterface">
						<xsl:with-param name="config" select="$config" />
						<xsl:with-param name="class" select="." />
						<xsl:with-param name="buildFile" select="$buildFile" />
					</xsl:call-template>

				</xsl:result-document>

				<!-- generate Class if necessary -->
<!--
				generate even for abstract classes
				<xsl:if test="not(xbig:areThereUnimplementedAbstractMethods(.)) and not(./@template)">
 -->				
				<xsl:if test="not(./@template)">
					<!-- compose filename of current class -->
					<xsl:variable name="filename"
						select="concat($outdir, '/', $java_ns_dir, '/', @name, '.java')" />

					<!-- open Java file -->
					<xsl:result-document href="{xbig:toFileURL($filename)}"
						format="textOutput">

						<xsl:call-template name="javaFileFirstContent">
							<xsl:with-param name="java_ns_name" select="$java_ns_name" />
							<xsl:with-param name="config" select="$config" />
						</xsl:call-template>

						<!-- write class implementation -->
						<xsl:call-template name="javaClass">
							<xsl:with-param name="config" select="$config" />
							<xsl:with-param name="class" select="." />
							<xsl:with-param name="buildFile" select="$buildFile" />
						</xsl:call-template>

					</xsl:result-document>
				</xsl:if>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>


	<xsl:template name="javaFileFirstContent">
		<xsl:param name="java_ns_name" />
		<xsl:param name="config" />

		<!-- write package -->
		<xsl:text>package&#32;</xsl:text>
		<xsl:value-of select="$java_ns_name" />
		<xsl:text>;&#10;&#10;</xsl:text>

		<!-- write import -->
		<xsl:text>&#10;</xsl:text>
		<xsl:text>import org.xbig.base.*;&#10;</xsl:text>
		<xsl:text>import std.*;&#10;</xsl:text>
		<xsl:text>import </xsl:text>
		<xsl:value-of select="$config/config/java/namespaces/packageprefix"/>
		<xsl:text>.*;&#10;</xsl:text>
		<xsl:text>&#10;</xsl:text>
	</xsl:template>

</xsl:stylesheet>
