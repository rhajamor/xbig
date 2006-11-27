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

	<xd:doc type="stylesheet">
		<xd:short>Creation of a XML structure for additional methods, like d-tors</xd:short>
	</xd:doc>

	<xsl:template name="cppCreateHelperMethods">
		<xsl:param name="config" />

		<!-- compose destructor name -->
		<xsl:variable name="destructor_name"
			select="$config/config/meta/destructor/name/text()" />

		<xsl:element name="function">

			<!-- d-tor -->
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

		<!-- create getters and setters for public attributes -->
		<!-- getter -->
		<xsl:for-each select="variable">
			<xsl:element name="function">
				<xsl:attribute name="public_attribute_getter">
					<xsl:text>true</xsl:text>
				</xsl:attribute>
				<xsl:attribute name="virt">
					<xsl:text>non-virtual</xsl:text>
				</xsl:attribute>
				<xsl:attribute name="visibility">
					<xsl:text>public</xsl:text>
				</xsl:attribute>
				<xsl:attribute name="static">
					<xsl:value-of select="@static" />
				</xsl:attribute>
				<xsl:attribute name="const">
					<xsl:value-of select="@const" />
				</xsl:attribute>
				<xsl:attribute name="passedBy">
					<xsl:value-of select="@passedBy" />
				</xsl:attribute>
				<xsl:element name="attribute_name">
					<xsl:value-of select="name"/>
				</xsl:element>
				<xsl:element name="type">
					<xsl:value-of select="type" />
				</xsl:element>
				<xsl:element name="name">
					<xsl:value-of>
						<xsl:value-of select="'__'"/>
						<xsl:value-of select="$config/config/meta/publicattribute/get/text()"/>
						<xsl:value-of select="name"/>
					</xsl:value-of>
				</xsl:element>
				<xsl:element name="definition">
					<xsl:value-of select="definition" />
				</xsl:element>
			</xsl:element>

			<!-- setter -->
			<xsl:element name="function">
				<xsl:attribute name="public_attribute_setter">
					<xsl:text>true</xsl:text>
				</xsl:attribute>
				<xsl:attribute name="virt">
					<xsl:text>non-virtual</xsl:text>
				</xsl:attribute>
				<xsl:attribute name="visibility">
					<xsl:text>public</xsl:text>
				</xsl:attribute>
				<xsl:attribute name="static">
					<xsl:value-of select="@static" />
				</xsl:attribute>
				<xsl:attribute name="const">
					<xsl:value-of select="@const" />
				</xsl:attribute>
				<xsl:attribute name="passedBy">
					<xsl:value-of select="@passedBy" />
				</xsl:attribute>
				<xsl:element name="attribute_name">
					<xsl:value-of select="name"/>
				</xsl:element>
				<xsl:element name="type">
					<xsl:text>void</xsl:text>
				</xsl:element>
				<xsl:element name="name">
					<xsl:value-of>
						<xsl:value-of select="'__'"/>
						<xsl:value-of select="$config/config/meta/publicattribute/set/text()"/>
						<xsl:value-of select="name"/>
					</xsl:value-of>
				</xsl:element>
				<xsl:element name="definition">
					<xsl:value-of select="definition" />
				</xsl:element>
				<xsl:element name="parameters">
					<xsl:element name="parameter">
						<xsl:attribute name="passedBy">
							<xsl:value-of select="@passedBy" />
						</xsl:attribute>
						<xsl:element name="type">
							<xsl:value-of select="type" />
						</xsl:element>
						<xsl:element name="name">
							<xsl:value-of select="$config/config/cpp/variables/jni/attributevalue/@name" />
						</xsl:element>
					</xsl:element>
				</xsl:element>
			</xsl:element>
		</xsl:for-each>

	</xsl:template>
</xsl:stylesheet>
