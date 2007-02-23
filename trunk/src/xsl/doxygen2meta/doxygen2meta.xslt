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
	
	Author: Hubert Rung			<hubert.rung@netallied.de>
	Christoph Nenning
	Frank Bielig
-->

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xd="http://www.pnp-software.com/XSLTdoc" version="2.0"
	xmlns:str="http://exslt.org/strings">

	<xsl:import href="../exslt/str.split.template.xsl" />

	<xd:doc type="stylesheet">
		<xd:author>Hubert Rung</xd:author>
		<xd:copyright>netAllied GmbH</xd:copyright>
		<xd:short>
			Transforms the Doxygen output to better readable meta layer.
		</xd:short>
		<xd:detail>
			This Stylesheet generates a XML file from the Doxygen
			output.
			<br />
			The XML file contains all informations of the source
			library.
			<br />
			In a second step this XML file can be used to generate
			wrappers for the library.
			<br />
		</xd:detail>
	</xd:doc>
	<xsl:output method="xml" version="1.0" encoding="iso-8859-1"
		indent="yes" />


	<!-- global Parameters -->
	<xsl:param name="externalTypes" />


	<!-- ############################## MAIN - calls namespace ############################## -->
	<xd:doc>
		<xd:short>Generate the root node of the XML file.</xd:short>
		<xd:detail>
			Calls template
			<b>namespace</b>
			for every namespace compound in the Doxygen output.
			<br />
			Generates a
			<code>libraryfile</code>
			element for each header file of the source library. These
			file names will be used to include them in the precompiled
			header file
			<b>Precompiled.h</b>
			.
			<br />
		</xd:detail>
	</xd:doc>
	<xsl:template match="/">
		<xsl:element name="meta"
			namespace="http://xbig.sourceforge.net/XBiG">
			<xsl:attribute name="schemaLocation">
				http://xbig.sourceforge.net/XMLSchema/xsd/meta.xsd
			</xsl:attribute>

			<xsl:element name="namespace">
				<xsl:attribute name="name" select="''" />
				<xsl:attribute name="fullName" select="''" />
				<xsl:for-each
					select="doxygen/compounddef[@kind='namespace']">
					<!-- because doxygen has a flat structure -->
					<xsl:choose>
						<xsl:when test="not(root()//compounddef
									[@kind='namespace']/innernamespace/@refid = @id)">
							<xsl:call-template name="namespace" />
						</xsl:when>
					</xsl:choose>
				</xsl:for-each>

				<!-- classes -->
				<xsl:for-each
					select="doxygen/compounddef[@kind='class']">
					<!-- because doxygen has a flat structure -->
					<xsl:choose>
						<xsl:when test="not(root()//compounddef
									[@kind='class' or @kind='struct' or @kind='namespace']
									/innerclass/@refid = @id)">
							<xsl:call-template name="class">
								<xsl:with-param name="refid" select="@id" />
							</xsl:call-template>
						</xsl:when>
					</xsl:choose>
				</xsl:for-each>

				<!-- structs -->
				<xsl:for-each
					select="doxygen/compounddef[@kind='struct']">
					<!-- because doxygen has a flat structure -->
					<xsl:choose>
						<xsl:when test="not(root()//compounddef
									[@kind='class' or @kind='struct' or @kind='namespace']
									/innerclass/@refid = @id)">
							<xsl:call-template name="struct">
								<xsl:with-param name="refid"
									select="@id" />
							</xsl:call-template>
						</xsl:when>
					</xsl:choose>
				</xsl:for-each>

				<!-- global typedefs -->
				<!-- <xsl:for-each select="doxygen/compounddef[@kind='typedef']"> -->
				<!-- check doxygen version -->
				<xsl:choose>
					<xsl:when test="/doxygen/@version='1.5.1-p1'">
						<xsl:for-each
								select="doxygen/compounddef[@kind='file']/sectiondef[@kind='typedef']">
							<xsl:call-template name="typedef" />
						</xsl:for-each>
					</xsl:when>
					<xsl:otherwise>
						<xsl:for-each
							select="doxygen/compounddef[@kind='file']/sectiondef[@kind='']">
							<xsl:choose>
								<!-- if there are more than one entries in all.xml -->
								<xsl:when test="last() > 1">
									<xsl:if test="position() = 1">
										<xsl:call-template name="typedef" />
									</xsl:if>
								</xsl:when>
								<xsl:otherwise>
									<xsl:call-template name="typedef" />
								</xsl:otherwise>
							</xsl:choose>
						</xsl:for-each>
					</xsl:otherwise>
				</xsl:choose>

				<!-- global enums -->
				<!-- <xsl:for-each select="doxygen/compounddef[@kind='enum']"> -->
				<!-- check doxygen version -->
				<xsl:choose>
					<xsl:when test="/doxygen/@version='1.5.1-p1'">
						<xsl:for-each select="doxygen/compounddef[@kind='file']/
								sectiondef[@kind='enum']/memberdef[@kind='enum']">
							<xsl:call-template name="enumeration" />
						</xsl:for-each>
					</xsl:when>
					<xsl:otherwise>
						<xsl:for-each select="doxygen/compounddef[@kind='file']/
								sectiondef[@kind='']/memberdef[@kind='enum']">
							<xsl:choose>
								<!-- if there are more than one entries in all.xml -->
								<xsl:when test="last() > 1">
									<xsl:if test="position() = 1">
										<xsl:call-template name="enumeration" />
									</xsl:if>
								</xsl:when>
								<xsl:otherwise>
									<xsl:call-template name="enumeration" />
								</xsl:otherwise>
							</xsl:choose>
						</xsl:for-each>
					</xsl:otherwise>
				</xsl:choose>

				<!-- global functions -->
				<!-- <xsl:for-each select="doxygen/compounddef[@kind='func']"> -->
				<xsl:for-each
					select="doxygen/compounddef[@kind='file']/sectiondef[@kind='func']">
					<xsl:if test="not(memberdef/templateparamlist)">
						<xsl:call-template name="function" />
					</xsl:if>
				</xsl:for-each>

    			<!-- variables in the global namespace -->
		    	<!-- create unique list of variables because of a bug in doxygen -->
				<xsl:variable name="unique-variable-list"
					select="doxygen/compounddef[@kind='file']/sectiondef[@kind='']/memberdef[@kind='variable']/definition[not(.=following::definition)]/.." />
				<xsl:for-each select="$unique-variable-list">
					<xsl:call-template name="variable" />
				</xsl:for-each>

				<!-- external types, like C++ STL -->
				<xsl:for-each select="$externalTypes/external/types/*">
					<xsl:copy-of select="."/>
				</xsl:for-each>

			</xsl:element>

			<!-- documentation -->
			<xsl:call-template name="documentation" />

			<!-- header files of the source library -->
			<xsl:for-each select="doxygen/compounddef[@kind='file']">
				<xsl:element name="libraryfile">
					<xsl:value-of select="compoundname" />
				</xsl:element>
			</xsl:for-each>

		</xsl:element>
	</xsl:template>

	<!-- ############### NAMESPACE - calls class; globals - calls typedef, enum, function, variable ################# -->
	<!-- cursor on doxygen/compounddef -->
	<xd:doc>
		<xd:short>
			Generates a
			<b>namespace</b>
			element for each namespace.
		</xd:short>
		<xd:detail>
			Sets the attribute
			<b>name</b>
			with it's name. Inner namespaces will be seperated by
			<code>::</code>
			symbols.
			<br />
			Calls template
			<b>class</b>
			for each class of the current namespace.
			<br />
			Calls template
			<b>variable</b>
			for global variables of the current namespace.
			<br />
			Calls template
			<b>typedef</b>
			for global typedefs of the current namespace.
			<br />
			Calls template
			<b>enumeration</b>
			for global enumerations of the current namespace.
			<br />
			Calls template
			<b>function</b>
			for global functions of the current namespace.
			<br />
			Calls template
			<b>documentation</b>
			for itself.
			<br />
		</xd:detail>
	</xd:doc>
	<xsl:template name="namespace">
		<xsl:element name="namespace">

			<xsl:variable name="name">
				<xsl:variable name="nameTokens">
					<xsl:call-template name="str:split">
						<xsl:with-param name="string"
							select="compoundname" />
						<xsl:with-param name="pattern" select="'::'" />
					</xsl:call-template>
				</xsl:variable>
				<xsl:value-of select="$nameTokens/token[last()]" />
			</xsl:variable>
			<xsl:attribute name="name" select="$name" />
			<xsl:attribute name="fullName" select="compoundname" />

			<!-- inner namespace -->
			<xsl:variable name="innernamespaceRefID"
				select="innernamespace/@refid" />
			<xsl:for-each
				select="root()//compounddef[@id=$innernamespaceRefID]">
				<xsl:call-template name="namespace" />
			</xsl:for-each>

			<!-- classes -->
			<xsl:for-each select="innerclass">
				<xsl:call-template name="class">
					<xsl:with-param name="refid" select="@refid" />
				</xsl:call-template>
			</xsl:for-each>

			<!-- global typedefs -->
			<!-- <xsl:for-each select="doxygen/compounddef[@kind='typedef']"> -->
			<!-- check doxygen version -->
			<xsl:choose>
				<xsl:when test="/doxygen/@version='1.5.1-p1'">
					<xsl:for-each
							select="sectiondef[@kind='typedef']">
						<xsl:call-template name="typedef" />
					</xsl:for-each>
				</xsl:when>
				<xsl:otherwise>
					<xsl:for-each
						select="sectiondef[@kind='']">
						<xsl:choose>
							<!-- if there are more than one entries in all.xml -->
							<xsl:when test="last() > 1">
								<xsl:if test="position() = 1">
									<xsl:call-template name="typedef" />
								</xsl:if>
							</xsl:when>
							<xsl:otherwise>
								<xsl:call-template name="typedef" />
							</xsl:otherwise>
						</xsl:choose>
					</xsl:for-each>
				</xsl:otherwise>
			</xsl:choose>

			<!-- global enums -->
			<!-- <xsl:for-each select="doxygen/compounddef[@kind='enum']"> -->
			<!-- check doxygen version -->
			<xsl:choose>
				<xsl:when test="/doxygen/@version='1.5.1-p1'">
					<xsl:for-each select="sectiondef[@kind='enum']/memberdef[@kind='enum']">
						<xsl:call-template name="enumeration" />
					</xsl:for-each>
				</xsl:when>
				<xsl:otherwise>
					<xsl:for-each select="sectiondef[@kind='']/memberdef[@kind='enum']">
						<xsl:choose>
							<!-- if there are more than one entries in all.xml -->
							<xsl:when test="last() > 1">
								<xsl:if test="position() = 1">
									<xsl:call-template name="enumeration" />
								</xsl:if>
							</xsl:when>
							<xsl:otherwise>
								<xsl:call-template name="enumeration" />
							</xsl:otherwise>
						</xsl:choose>
					</xsl:for-each>
				</xsl:otherwise>
			</xsl:choose>

			<!-- global variables in the namespace -->
			<!-- create unique list of variables because of a bug in doxygen -->
			<xsl:variable name="unique-variable-list"
				select="sectiondef[@kind='']/memberdef[@kind='variable']/definition[not(.=following::definition)]/.." />
			<xsl:for-each select="$unique-variable-list">
				<xsl:call-template name="variable" />
			</xsl:for-each>

			<!-- global functions -->
			<xsl:for-each select="sectiondef[@kind='func']">
				<xsl:if test="not(memberdef/templateparamlist)">
					<xsl:call-template name="function" />
				</xsl:if>
			</xsl:for-each>

			<!-- documentation -->
			<xsl:call-template name="documentation" />

		</xsl:element>
	</xsl:template>


	<!-- ############### CLASS - calls struct, derivation, enumeration, typedef, function ################## -->
	<!-- cursor on doxygen/compounddef/innerclass -->
	<xd:doc>
		<xd:short>
			Generates a
			<b>class</b>
			element for each class of the current namespace.
		</xd:short>
		<xd:detail>
			Sets the attribute
			<b>name</b>
			with it's name.
			<br />
			Sets the attribute
			<b>fullName</b>
			with it's fully qualified name.
			<br />
			Sets the attribute
			<b>template</b>
			set to
			<code>true</code>
			if the current class is a template.
			<br />
			Sets the attribute
			<b>templateType</b>
			with it's type if the current class is a template.
			<br />
			Sets the attribute
			<b>templateDeclaration</b>
			with it's declaration type if the current class is a
			template.
			<br />
			Sets the attribute
			<b>templateName</b>
			with it's template name if the current class is a template.
			<br />
			Calls template
			<b>struct</b>
			for each public struct of the current class.
			<br />
			Calls template
			<b>derivation</b>
			for subclasses and baseclasses of the current class.
			<br />
			Calls template
			<b>enumeration</b>
			for enumerations of the current class.
			<br />
			Calls template
			<b>typedef</b>
			for typedefs of the current class.
			<br />
			Calls template
			<b>variable</b>
			for public variables of the current class.
			<br />
			Calls template
			<b>function</b>
			for public functions and public static functions of the
			current class.
			<br />
			Calls template
			<b>class</b>
			for inner classes of the current class.
			<br />
			Calls template
			<b>documentation</b>
			for itself.
			<br />
		</xd:detail>
		<xd:param name="refid">
			ID of the class inside the Doxygen XML
		</xd:param>
	</xd:doc>

	<xsl:template name="class">
		<xsl:param name="refid" />

		<!-- structs -->
		<xsl:for-each
			select="root()//compounddef[@id=$refid and @kind='struct' and @prot='public']">
			<!-- select="root()//compounddef[@id=$refid and @kind='struct' and @prot='public']/sectiondef[@kind='public-attrib']"> -->
			<xsl:call-template name="struct" />
		</xsl:for-each>

		<!-- classes -->
		<xsl:for-each
			select="root()//compounddef[@id=$refid and @kind='class' and @prot='public']">
			<xsl:element name="class">

				<xsl:call-template name="classAndStructBody">
					<xsl:with-param name="refid" select="@id" />
				</xsl:call-template>

			</xsl:element>
		</xsl:for-each>
	</xsl:template>


	<!-- ##################### DERIVATION ######################### -->
	<!-- cursor on doxygen/compounddef -->
	<xd:doc>
		<xd:short>
			Generates a
			<b>derives</b>
			element if the current class has got one or more subclasses.
			<br />
			Generates a
			<b>inherits</b>
			element if the current class has got one or more
			baseclasses.
			<br />
		</xd:short>
		<xd:detail>
			Below the
			<b>derives</b>
			element there will be one
			<b>subClass</b>
			element for each subclass of the current class with it's
			name.
			<br />
			Subclasses are unimportant for the wrapper generation and
			won't be used.
			<br />
			Below the
			<b>inherits</b>
			element there will be one
			<b>baseClass</b>
			element for each subclass of the current class with it's
			name.
			<br />
			Non template classes will be shown first, as this is
			important for the derivation order in Java.
			<br />
		</xd:detail>
		<xd:param name="refid">
			ID of the class inside the Doxygen XML
		</xd:param>
	</xd:doc>
	<xsl:template name="derivation">
		<xsl:param name="refid" />
		<xsl:if test="derivedcompoundref">
			<xsl:element name="derives">
				<xsl:for-each select="derivedcompoundref">
					<xsl:element name="subClass">
						<xsl:choose>
							<!-- if there is no namespace -->
							<xsl:when
								test="not(contains(@refid,'_1_1'))">
								<xsl:value-of select="." />
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of
									select="substring-after(@refid,'_1_1')" />
							</xsl:otherwise>
						</xsl:choose>
					</xsl:element>
				</xsl:for-each>
			</xsl:element>
		</xsl:if>
		<xsl:if test="basecompoundref">
			<xsl:element name="inherits">
				<xsl:for-each
					select="inheritancegraph/node[link/@refid=$refid]">
					<xsl:for-each select="childnode">
						<xsl:variable name="childid" select="@refid" />
						<!-- non templates first -->
						<xsl:if
							test="not(contains(substring-after(../../node[@id=$childid]/label,'::'),'&lt;'))">

							<xsl:element name="baseClass">

								<!-- remember the full name of base classes -->
								<xsl:attribute name="fullBaseClassName"
									select="../../node[@id=$childid]/label" />

								<xsl:variable name="baseClass"
									select="substring-after(../../node[@id=$childid]/label,'::')" />
								<xsl:choose>
									<!-- if there is no namespace -->
									<xsl:when
										test="substring-after(../../node[@id=$childid]/label,'::') = ''">
										<xsl:value-of
											select="../../node[@id=$childid]/label" />
									</xsl:when>
									<xsl:when
										test="contains($baseClass,'::')">
										<xsl:value-of
											select="replace($baseClass,'::','.')" />
									</xsl:when>
									<xsl:otherwise>
										<xsl:value-of
											select="$baseClass" />
									</xsl:otherwise>
								</xsl:choose>
							</xsl:element>
						</xsl:if>
					</xsl:for-each>
					<xsl:for-each select="childnode">
						<xsl:variable name="childid" select="@refid" />
						<!-- templates -->
						<xsl:if
							test="contains(substring-after(../../node[@id=$childid]/label,'::'),'&lt;')">
							<xsl:element name="baseClass">

								<!-- remember the full name of base classes -->
								<xsl:attribute name="fullBaseClassName"
									select="../../node[@id=$childid]/label" />

								<xsl:variable name="baseClass"
									select="substring-after(../../node[@id=$childid]/label,'::')" />
								<xsl:choose>
									<xsl:when
										test="contains($baseClass,'::')">
										<xsl:value-of
											select="replace($baseClass,'::','.')" />
									</xsl:when>
									<xsl:otherwise>
										<xsl:value-of
											select="$baseClass" />
									</xsl:otherwise>
								</xsl:choose>
							</xsl:element>
						</xsl:if>
					</xsl:for-each>
				</xsl:for-each>
			</xsl:element>
		</xsl:if>
	</xsl:template>
	<!-- ##################### ENUMERATION ######################### -->
	<!-- cursor on doxygen/compounddef/sectiondef -->
	<xd:doc>
		<xd:short>
			Generates an
			<b>enumeration</b>
			element for each enumeration of the current class.
		</xd:short>
		<xd:detail>
			Sets the attribute
			<b>name</b>
			with the name of the enumeration.
			<br />
			Below the
			<b>enumeration</b>
			element there will be one
			<b>enum</b>
			element for each value of the current enumeration.
			<br />
			The
			<b>enum</b>
			element retains the attribute
			<b>name</b>
			with the name of the value.
			<br />
			Calls template
			<b>documentation</b>
			for itself.
			<br />
		</xd:detail>
	</xd:doc>
	<xsl:template name="enumeration">

		<!-- check if we are inside a class -->
		<xsl:choose>

			<!-- global or inside namespace -->
			<xsl:when test="@kind='enum'">
				<xsl:element name="enumeration">
					<xsl:attribute name="name" select="name" />
					<xsl:attribute name="fullName">
						<xsl:choose>
							<xsl:when
								test="../../@kind = 'namespace'">
								<xsl:value-of
									select="concat(../../compoundname, '::', name)" />
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of select="name" />
							</xsl:otherwise>
						</xsl:choose>
					</xsl:attribute>

					<xsl:for-each select="enumvalue">
						<xsl:element name="enum">
							<xsl:attribute name="name" select="name" />
							<xsl:if test="initializer">
								<xsl:attribute name="initializer"
									select="normalize-space(initializer)" />
							</xsl:if>
						</xsl:element>
					</xsl:for-each>
					<!-- documentation -->
					<xsl:call-template name="documentation" />
				</xsl:element>
			</xsl:when>

			<!-- inside class -->
			<xsl:otherwise>
				<xsl:for-each select="memberdef[@kind='enum']">
					<!-- test if enum belongs to actual class -->
					<xsl:if test="starts-with(@id,../../@id)">
						<xsl:element name="enumeration">
							<xsl:attribute name="name" select="name" />
							<xsl:attribute name="fullName"
								select="concat(../../compoundname, '::', name)" />
							<xsl:for-each select="enumvalue">
								<xsl:element name="enum">
									<xsl:attribute name="name"
										select="name" />
									<xsl:if test="initializer">
										<xsl:attribute
											name="initializer" select="normalize-space(initializer)" />
									</xsl:if>
								</xsl:element>
							</xsl:for-each>

							<!-- documentation -->
							<xsl:call-template name="documentation" />

						</xsl:element>
					</xsl:if>
				</xsl:for-each>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<!-- ##################### TYPEDEF - calls typeMap ######################### -->
	<!-- cursor on doxygen/compounddef/sectiondef -->
	<xd:doc>
		<xd:short>
			Generates an
			<b>typedef</b>
			element for each typedef of the current class.
		</xd:short>
		<xd:detail>
			Sets the attribute
			<b>name</b>
			with the name of the typedef.
			<br />
			Sets the attribute
			<b>protection</b>
			with values:
			<ul>
				<li>public</li>
				<li>protected</li>
				<li>private</li>
			</ul>
			<br />
			Sets the attribute
			<b>name</b>
			with the name of the typedef.
			<br />
			Sets the attribute
			<b>basetype</b>
			with the definition of the typedef.
			<br />
			Sets the attribute
			<b>type</b>
			with the value of the template parameter, if the
			<b>basetype</b>
			is a template.
			<br />
			Calls template
			<b>typeMap</b>
			for the mapping of the template parameter, if the
			<b>basetype</b>
			is a template.
			<br />
			Calls template
			<b>documentation</b>
			for itself.
			<br />
		</xd:detail>
	</xd:doc>
	<xsl:template name="typedef">
		<xsl:for-each select="memberdef[@kind='typedef']">
			<xsl:element name="typedef">
				<xsl:attribute name="name" select="name" />
				<xsl:attribute name="fullName">
					<xsl:choose>
						<xsl:when
							test="../../@kind = 'namespace' 
										or ../../@kind = 'class' 
										or ../../@kind = 'struct'">
							<xsl:value-of
								select="concat(../../compoundname, '::', name)" />
						</xsl:when>
						<xsl:otherwise>
							<xsl:value-of select="name" />
						</xsl:otherwise>
					</xsl:choose>
				</xsl:attribute>
				<xsl:attribute name="protection" select="@prot" />
				<xsl:attribute name="basetype" select="normalize-space(./type)" />

				<!-- copy all includes into meta output -->
				<xsl:choose>
					<xsl:when test="../../@kind = 'class' or ../../@kind = 'struct'">
						<xsl:copy-of copy-namespaces="no" select="../../includes"/>
					</xsl:when>

					<!-- inside a file -->
					<xsl:otherwise>
						<xsl:element name="includes">
							<xsl:attribute name="local" select="'yes'"/>
							<xsl:value-of select="../../compoundname"/>
						</xsl:element>
					</xsl:otherwise>
				</xsl:choose>

				<!-- 
				<xsl:variable name="type"
					select="replace(type,'std::string','String')" />
				 -->
				<!-- 
				<xsl:variable name="type" select="type"/>
				<xsl:choose>
					<xsl:when
						test="contains($type,'std::') or contains($type,',')">
						<xsl:attribute name="basetype"
							select="substring-before(type,'&lt;')" />
						<xsl:variable name="basetype"
							select="substring-before(type,'&lt;')" />
						<xsl:if test="contains($basetype,'&#xA;')">
							<xsl:attribute name="basetype"
								select="normalize-space(substring-after($basetype,'&#xA;'))" />
						</xsl:if>
						<xsl:variable name="string1"
							select="substring-after($type,'&lt; ')" />
						<xsl:choose>
						 -->
							<!-- e.g. std::multimap< std::pair<size_t, size_t>, std::pair<size_t, size_t> > -->
							<!-- 
							<xsl:when
								test="starts-with($string1,'std::')">
								<xsl:variable name="type1"
									select="substring-before($string1,', std::')" />
								<xsl:element name="typedef">
									<xsl:attribute name="basetype"
										select="substring-before($type1,'&lt;')" />
									<xsl:variable name="string1"
										select="substring-after($type1,'&lt; ')" />
									<xsl:call-template name="typeMap">
										<xsl:with-param name="type"
											select="normalize-space(substring-before($string1,','))" />
									</xsl:call-template>
									<xsl:variable name="string2"
										select="substring-before($string1,' &gt;')" />
									<xsl:call-template name="typeMap">
										<xsl:with-param name="type"
											select="normalize-space(substring-after($string2,','))" />
									</xsl:call-template>
								</xsl:element>
								<xsl:variable name="type2"
									select="substring-after($string1,'&gt;, ')" />
								<xsl:element name="typedef">
									<xsl:attribute name="basetype"
										select="substring-before($type2,'&lt;')" />
									<xsl:variable name="string1"
										select="substring-after($type2,'&lt; ')" />
									<xsl:call-template name="typeMap">
										<xsl:with-param name="type"
											select="normalize-space(substring-before($string1,','))" />
									</xsl:call-template>
									<xsl:variable name="string2"
										select="substring-before($string1,' &gt;')" />
									<xsl:call-template name="typeMap">
										<xsl:with-param name="type"
											select="normalize-space(substring-after($string2,','))" />
									</xsl:call-template>
								</xsl:element>
							</xsl:when>
							<xsl:when test="contains($string1,',')">
								<xsl:variable name="string2"
									select="substring-after(type,', ')" />
								<xsl:call-template name="typeMap">
									<xsl:with-param name="type"
										select="substring-before($string1,',')" />
									<xsl:with-param name="passedBy">
										<xsl:choose>
											<xsl:when
												test="contains(substring-before($string1,','),'*')">
												<xsl:value-of
													select="'pointer'" />
											</xsl:when>
											<xsl:otherwise>
												<xsl:value-of
													select="'value'" />
											</xsl:otherwise>
										</xsl:choose>
									</xsl:with-param>
								</xsl:call-template>
								<xsl:choose>
								 -->
									<!-- e.g. std::map<Vector3, size_t, vectorLess> -->
									<!-- 
									<xsl:when
										test="contains($string2,',')">
										<xsl:call-template
											name="typeMap">
											<xsl:with-param name="type"
												select="normalize-space(substring-before($string2,','))" />
										</xsl:call-template>
									</xsl:when>
									 -->
									<!-- e.g. std::map<Vector3, size_t> -->
									<!-- 
									<xsl:otherwise>
										<xsl:call-template
											name="typeMap">
											<xsl:with-param name="type"
												select="substring-before($string2,' ')" />
											<xsl:with-param
												name="passedBy">
												<xsl:choose>
													<xsl:when
														test="contains($string2,'*')">
														<xsl:value-of
															select="'pointer'" />
													</xsl:when>
													<xsl:otherwise>
														<xsl:value-of
															select="'value'" />
													</xsl:otherwise>
												</xsl:choose>
											</xsl:with-param>
										</xsl:call-template>
									</xsl:otherwise>
								</xsl:choose>
							</xsl:when>
							<xsl:otherwise>
								<xsl:call-template name="typeMap">
									<xsl:with-param name="type"
										select="normalize-space(substring-before($string1,'&gt;'))" />
									<xsl:with-param name="passedBy">
										<xsl:choose>
											<xsl:when
												test="contains($string1,'*')">
												<xsl:value-of
													select="'pointer'" />
											</xsl:when>
											<xsl:otherwise>
												<xsl:value-of
													select="'value'" />
											</xsl:otherwise>
										</xsl:choose>
									</xsl:with-param>
								</xsl:call-template>
							</xsl:otherwise>
						</xsl:choose>
					</xsl:when>
					 -->
					<!-- iterator, simple typedefs -->
					<!-- 
					<xsl:otherwise>
						<xsl:attribute name="basetype" select="type" />
						<xsl:variable name="basetype" select="type" />
						<xsl:if test="contains($basetype,'&#xA;')">
							<xsl:attribute name="basetype"
								select="normalize-space(substring-after($basetype,'&#xA;'))" />
						</xsl:if>
						<xsl:choose>
							<xsl:when
								test="type/ref[@kindref='member']">
								<xsl:choose>
									<xsl:when
										test="contains(type/ref[@kindref='member'],'::')">
										<xsl:attribute name="type"
											select="substring-after(type/ref[@kindref='member'],'::')" />
									</xsl:when>
									<xsl:otherwise>
										<xsl:attribute name="type"
											select="type/ref[@kindref='member']" />
									</xsl:otherwise>
								</xsl:choose>
							</xsl:when>
							<xsl:when
								test="type/ref[@kindref='compound']">
								<xsl:choose>
									<xsl:when
										test="count(type/ref[@kindref='compound'])=2">
										<xsl:attribute name="type"
											select="type/ref[@kindref='compound' and position()=2]" />
									</xsl:when>
									<xsl:otherwise>
										<xsl:variable name="string1"
											select="substring-after(type,'&lt;')" />
										<xsl:attribute name="type"
											select="normalize-space(substring-before($string1,'&gt;'))" />
									</xsl:otherwise>
									 -->
									<!--
										<xsl:otherwise>
										<xsl:attribute name="type" select="type/ref[@kindref='compound']"/>
										</xsl:otherwise>
									-->
									<!-- 
								</xsl:choose>
							</xsl:when>
						</xsl:choose>
					</xsl:otherwise>
				</xsl:choose>
				 -->

				<!-- documentation -->
				<xsl:call-template name="documentation" />

			</xsl:element>
		</xsl:for-each>
	</xsl:template>


	<!-- ##################### STRUCT - calls typeMap ######################### -->
	<!-- cursor on doxygen/compounddef/sectiondef -->
	<xd:doc>
		<xd:short>
			Generates an
			<b>struct</b>
			element for each struct of the current class.
		</xd:short>
		<xd:detail>
			Sets the attribute
			<b>name</b>
			with the name of the struct.
			<br />
			Sets the attribute
			<b>protection</b>
			with values:
			<ul>
				<li>public</li>
				<li>protected</li>
				<li>private</li>
			</ul>
			<br />
			Sets the attribute
			<b>name</b>
			with the name of the typedef.
			<br />
			Sets the attribute
			<b>template</b>
			set to
			<code>true</code>
			if the current struct is a template.
			<br />
			Sets the attribute
			<b>templateType</b>
			with it's type if the current struct is a template.
			<br />
			Sets the attribute
			<b>templateDeclaration</b>
			with it's declaration type if the current struct is a
			template.
			<br />
			Sets the attribute
			<b>templateName</b>
			with it's template name if the current struct is a template.
			<br />
			Below the
			<b>struct</b>
			element there will be one
			<b>param</b>
			element for each variable of the current struct.
			<br />
			Name and type of the variable will be stored in the elements
			<b>name</b>
			and
			<b>type</b>
			below the
			<b>param</b>
			element.
			<br />
			Calls template
			<b>typeMap</b>
			for the mapping of the type of the variable.
			<br />
			Calls template
			<b>function</b>
			for public functions of the struct.
			<br />
			Calls template
			<b>structattributes</b>
			for public attributes of the struct.
			<br />
			Calls template
			<b>documentation</b>
			for itself.
			<br />
		</xd:detail>
	</xd:doc>

	<xsl:template name="struct">
		<xsl:param name="refid" />

		<xsl:element name="struct">

			<xsl:call-template name="classAndStructBody">
				<xsl:with-param name="refid" select="@id" />
			</xsl:call-template>

		</xsl:element>
	</xsl:template>


	<!-- ############## FUNCTION - calls type ############## -->
	<!-- cursor on doxygen/compounddef/sectiondef -->
	<xd:doc>
		<xd:short>
			Generates an
			<b>function</b>
			element for each function of the current namespace, class or
			struct.
		</xd:short>
		<xd:detail>
			Sets the attribute
			<b>virt</b>
			to differ abstract functions, with values:
			<ul>
				<li>non-virtual</li>
				<li>virtual</li>
				<li>pure-virtual</li>
			</ul>
			<br />
			Sets the attribute
			<b>const</b>
			to differ constant and non-constant functions, with values:
			<ul>
				<li>true</li>
				<li>false</li>
			</ul>
			<br />
			Sets the attribute
			<b>template</b>
			set to
			<code>true</code>
			if the current function is a template.
			<br />
			Sets the attribute
			<b>templateType</b>
			with it's type if the current function is a template.
			<br />
			Sets the attribute
			<b>templateDeclaration</b>
			with it's declaration type if the current function is a
			template.
			<br />
			Sets the attribute
			<b>templateName</b>
			with it's template name if the current function is a
			template.
			<br />
			Name and type of the function will be stored in the elements
			<b>name</b>
			and
			<b>type</b>
			below the
			<b>function</b>
			element.
			<br />
			The element
			<b>definition</b>
			below the
			<b>function</b>
			element is for debugging only.
			<br />
			Below the
			<b>function</b>
			element there will be one
			<b>parameters</b>
			element if the function has got parameters.
			<br />
			Name and type of the parameters will be stored in the
			elements
			<b>name</b>
			and
			<b>type</b>
			below the
			<b>parameters</b>
			element.
			<br />
			Calls template
			<b>type</b>
			for the elements
			<b>name</b>
			and
			<b>type</b>
			.
			<br />
			Calls template
			<b>documentation</b>
			for itself.
			<br />
		</xd:detail>
	</xd:doc>
	<xsl:template name="function">
		<xsl:for-each select="memberdef">
			<!-- test if function belongs to actual class (the location test could be deleted)  -->
			<!-- 
			<xsl:if
				test="ends-with(location/@file,../../includes) and starts-with(@id,../../@id)">
			 -->
				<xsl:choose>
					<!-- destructor - do nothing -->
					<xsl:when test="starts-with(name,'~')" />
					<xsl:otherwise>
						<xsl:element name="function">
							<xsl:attribute name="virt" select="@virt" />
							<xsl:attribute name="visibility"
								select="@prot" />
							<xsl:attribute name="static">
								<xsl:choose>
									<xsl:when test="@static='yes'">
										<xsl:value-of select="'true'" />
									</xsl:when>
									<xsl:when test="@static='no'">
										<xsl:value-of select="'false'" />
									</xsl:when>
								</xsl:choose>
							</xsl:attribute>
							<xsl:attribute name="const">
								<xsl:choose>
									<xsl:when test="@const='yes'">
										<xsl:value-of select="'true'" />
									</xsl:when>
									<xsl:when test="@const='no'">
										<xsl:value-of select="'false'" />
									</xsl:when>
								</xsl:choose>
							</xsl:attribute>
							<!-- template attributes -->
							<xsl:if test="templateparamlist">
								<xsl:variable name="refid"
									select="../../@id" />
								<xsl:attribute name="template"
									select="'true'" />
								<xsl:attribute name="templateType"
									select="templateparamlist/param/type" />
								<xsl:attribute
									name="templateDeclaration"
									select="templateparamlist/param/declname" />
								<xsl:for-each
									select="inheritancegraph/node">
									<xsl:if test="link/@refid=$refid">
										<xsl:variable name="childnode"
											select="childnode/@refid" />
										<xsl:for-each
											select="../node">
											<xsl:if
												test="@id=$childnode">
												<xsl:attribute
													name="templateName">
													<xsl:variable
														name="string" select="substring-before(label,' &gt;')" />
													<xsl:value-of
														select="substring-after($string,'&lt; ')" />
												</xsl:attribute>
											</xsl:if>
										</xsl:for-each>
									</xsl:if>
								</xsl:for-each>
							</xsl:if>
							<!-- type of the function -->
							<xsl:if test="type and type!='virtual'">
								<xsl:call-template name="type" />
							</xsl:if>
							<xsl:element name="definition">
								<xsl:value-of select="definition" />
							</xsl:element>
							<!-- name of the function -->
							<xsl:element name="name">
								<!-- <xsl:choose>
									<xsl:when
									test="contains(name,'::')">
									<xsl:value-of
									select="substring-after(name,'::')" />
									</xsl:when>
									<xsl:otherwise> -->
								<xsl:value-of select="name" />
								<!-- </xsl:otherwise>
									</xsl:choose> -->
							</xsl:element>
							<!-- parameter of the function -->
							<xsl:if
								test="(param/type!='' or param/declname!='') and not(param/type='void')">
								<xsl:element name="parameters">
									<xsl:for-each select="param">
										<xsl:element name="parameter">
											<xsl:call-template
												name="type" />
										</xsl:element>
									</xsl:for-each>
								</xsl:element>
							</xsl:if>

							<!-- documentation -->
							<xsl:call-template name="documentation" />

						</xsl:element>
					</xsl:otherwise>
				</xsl:choose>
			<!-- 
			</xsl:if>
			 -->
		</xsl:for-each>
	</xsl:template>
	<!-- ##################### TYPE - calls typeMap ##################### -->
	<!-- cursor on doxygen/compounddef/sectiondef/memberdef/param -->
	<xd:doc>
		<xd:short>
			Sets the attributes for a function parameter or a variable.
			Generates an
			<b>name</b>
			element for a function parameter or a variable.
		</xd:short>
		<xd:detail>
			Sets the attribute
			<b>passedBy</b>
			with values:
			<ul>
				<li>reference</li>
				<li>pointer</li>
				<li>value</li>
			</ul>
			<br />
			Calls template
			<b>typeMap</b>
			for the type of a function parameter or a variable.
			<br />
		</xd:detail>
	</xd:doc>
	<xsl:template name="type">
		<xsl:choose>
			<!-- passed by reference -->
			<xsl:when test="contains(type,'&amp;')">
				<xsl:attribute name="passedBy" select="'reference'" />
				<xsl:call-template name="typeMap">
					<xsl:with-param name="type" select="substring-before(type,' &amp;')"/>
				</xsl:call-template>
				<!-- 
				<xsl:choose>
				 -->
					<!-- current class is a template -->
					<!-- 
					<xsl:when
						test="../../templateparamlist or ../../../templateparamlist">
						<xsl:call-template name="typeMap">
							<xsl:with-param name="type"
								select="substring-before(type,' &amp;')" />
						</xsl:call-template>
					</xsl:when>
					<xsl:when test="type/ref">
						<xsl:call-template name="typeMap">
							 -->
							<!-- don't put the select instruction into the "with-param" element,will cause multiple select of type/ref -->
							<!-- 
							<xsl:with-param name="type">
								<xsl:value-of select="type/ref" />
							</xsl:with-param>
						</xsl:call-template>
					</xsl:when>
					<xsl:otherwise>
						<xsl:call-template name="typeMap">
							<xsl:with-param name="type"
								select="substring-before(type,' &amp;')" />
						</xsl:call-template>
					</xsl:otherwise>
				</xsl:choose>
				 -->
			</xsl:when>
			<!-- passed by pointer -->
			<xsl:when test="contains(type,'*')">
				<xsl:attribute name="passedBy" select="'pointer'" />
				<xsl:call-template name="typeMap">
					<xsl:with-param name="type" select="type" />
				</xsl:call-template>
				<!-- 
				<xsl:variable name="type"
					select="substring-before(type,' *')" />
				 -->
				<!-- 
				<xsl:choose>
					 -->
					<!-- current class is a template -->
					<!-- 
					<xsl:when
						test="../../templateparamlist or ../../../templateparamlist">
						<xsl:call-template name="typeMap">
							 -->
							<!-- 
							<xsl:with-param name="type"
								select="substring-before(type,' *')" />
							 -->
							<!-- 
							<xsl:with-param name="type" select="type" />
						</xsl:call-template>
					</xsl:when>
					<xsl:when test="type/ref">
						<xsl:call-template name="typeMap">
							<xsl:with-param name="type">
								<xsl:value-of select="type/ref" />
							</xsl:with-param>
						</xsl:call-template>
					</xsl:when>
					<xsl:otherwise>
						<xsl:call-template name="typeMap">
							 -->
							<!-- 
							<xsl:with-param name="type"
								select="substring-before(type,' *')" />
							 -->
							<!-- 
							<xsl:with-param name="type" select="type" />
						</xsl:call-template>
					</xsl:otherwise>
				</xsl:choose>
				 -->
			</xsl:when>
			<!-- passed by value -->
			<xsl:otherwise>
				<xsl:attribute name="passedBy" select="'value'" />
				<xsl:choose>
					<!-- current class is a template -->
					<xsl:when
						test="../../templateparamlist or ../../../templateparamlist">
						<xsl:call-template name="typeMap">
							<xsl:with-param name="type" select="type" />
						</xsl:call-template>
					</xsl:when>
					<xsl:when test="count(type/ref)=1">
						<xsl:call-template name="typeMap">
							<xsl:with-param name="type">
								<!-- <xsl:value-of select="type/ref" /> -->
								<xsl:value-of select="type" />
							</xsl:with-param>
						</xsl:call-template>
					</xsl:when>
					<xsl:otherwise>
						<xsl:call-template name="typeMap">
							<xsl:with-param name="type" select="type" />
						</xsl:call-template>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:otherwise>
		</xsl:choose>
		<!-- name -->
		<xsl:if test="declname!=''">
			<xsl:element name="name">
				<xsl:value-of select="declname" />
			</xsl:element>
		</xsl:if>
	</xsl:template>
	<!-- ######################## TYPEMAP ######################## -->
	<!-- cursor on doxygen/compounddef/sectiondef/memberdef/param -->
	<xd:doc>
		<xd:short>
			Generates a
			<b>type</b>
			element for a function parameter or a variable.
		</xd:short>
		<xd:detail>
			The typemap template a mapping for primitive types. It also
			removes unwanted symbols.
			<br />
			Sets the attribute
			<b>const</b>
			to
			<code>true</code>
			if the current parameter is constant.
			<br />
			Sets the attribute
			<b>array</b>
			with the array arguments.
			<br />
			Sets the attribute
			<b>passedBy</b>
			for the type, with values:
			<ul>
				<li>reference</li>
				<li>pointer</li>
				<li>value</li>
			</ul>
			<br />
		</xd:detail>
		<xd:param name="type">
			type of function, parameter or variable
		</xd:param>
		<xd:param name="passedBy">reference, pointer or value</xd:param>
	</xd:doc>
	<xsl:template name="typeMap">
		<xsl:param name="type" />
		<xsl:param name="passedBy" />
		<xsl:if test="type!=''">
			<xsl:element name="type">

				<!-- check for const, take care of const pointer or const data
					(const int* vs int* const) -->
				<xsl:choose>
					<!-- <xsl:when test="$passedBy = 'pointer'"> -->
					<xsl:when test="contains(type, '*')">
						<!-- const data -->
						<xsl:if
							test="contains(substring-before(type, '*'), 'const')">
							<xsl:attribute name="const" select="'true'" />
						</xsl:if>
						<!-- const pointer -->
						<xsl:if
							test="contains(substring-after(type, '*'), 'const')">
							<xsl:attribute name="constPointer"
								select="'true'" />
						</xsl:if>
					</xsl:when>
					<xsl:otherwise>
						<xsl:if test="contains(type,'const')">
							<xsl:attribute name="const" select="'true'" />
						</xsl:if>
					</xsl:otherwise>
				</xsl:choose>

				<xsl:if test="array">
					<xsl:attribute name="array" select="array" />
				</xsl:if>
				<xsl:if test="$passedBy">
					<xsl:attribute name="passedBy" select="$passedBy" />
				</xsl:if>

				<!-- remove const prefix or postfix -->
				<xsl:variable name="non_const_type">
					<xsl:choose>
						<xsl:when test="starts-with($type, 'const')">
							<xsl:value-of
								select="replace($type, '[ \t]*^const[ \t]', '')" />
						</xsl:when>
						<xsl:when test="contains($type,'const')">
							<xsl:value-of
								select="substring-before($type, 'const')" />
						</xsl:when>
						<xsl:otherwise>
							<xsl:value-of select="$type" />
						</xsl:otherwise>
					</xsl:choose>
				</xsl:variable>

				<!-- remove parameter passing modifiers -->
				<!-- 
				<xsl:variable name="stripped_type" select="replace($non_const_type, '[\*&amp;\[].*$', '')"/>
				 -->
				<xsl:variable name="typeWithoutRef" select="replace($non_const_type, '[&amp;\[].*$', '')"/>

				<xsl:variable name="pointerPointerToken" select="'#POINTER_POINTER_TOKEN#'"/>
				<xsl:variable name="stripped_type">
					<xsl:choose>
						<xsl:when test="contains($typeWithoutRef, '*')">
							<xsl:choose>
								<!-- recognize pointer pointer -->
								<xsl:when test="contains(substring-after($typeWithoutRef, '*'), '*')">
									<!-- keep some '*' to recognize pointer pointer -->
									<!-- 
									<xsl:value-of select="concat(substring-before($typeWithoutRef, '*'),
																 substring-after($typeWithoutRef, '*'))"/>
									 -->
									
									<xsl:value-of select="concat(substring-before($typeWithoutRef, '*'),
															$pointerPointerToken)"/>
								</xsl:when>
								<xsl:otherwise>
									<xsl:value-of select="substring-before($typeWithoutRef, '*')"/>
								</xsl:otherwise>
							</xsl:choose>
						</xsl:when>
						<xsl:otherwise>
							<xsl:value-of select="$typeWithoutRef"/>
						</xsl:otherwise>
					</xsl:choose>
				</xsl:variable>

				<xsl:if test="contains($stripped_type, $pointerPointerToken)">
					<xsl:attribute name="pointerPointer" select="'true'"/>
				</xsl:if>

				<xsl:choose>
					<xsl:when test="contains($stripped_type, $pointerPointerToken)">
						<xsl:value-of select="normalize-space(substring-before($stripped_type,
												$pointerPointerToken))" />
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="normalize-space($stripped_type)" />
					</xsl:otherwise>
				</xsl:choose>
			</xsl:element>
		</xsl:if>
	</xsl:template>
	<!-- ############ VARIABLE ############ -->
	<xd:doc>
		<xd:short>
			Generates a
			<b>variable</b>
			element for a global or in-class variable.
		</xd:short>
		<xd:detail>
			Calls template
			<b>type</b>
			for the type of the variable.
			<br />
			The element
			<b>argsstring</b>
			below the
			<b>variable</b>
			element is for array types.
			<br />
			The element
			<b>definition</b>
			below the
			<b>variable</b>
			element is for debugging only.
			<br />
			The element
			<b>name</b>
			below the
			<b>variable</b>
			element contains the name of the variable.
			<br />
		</xd:detail>
		<xd:param name="type">
			type of function, parameter or variable
		</xd:param>
		<xd:param name="passedBy">reference, pointer or value</xd:param>
	</xd:doc>
	<!-- cursor on doxygen/compounddef/sectiondef -->
	<xsl:template name="variable">
		<xsl:for-each select="memberdef[@kind='variable']">
			<xsl:element name="variable">
				<!--
					<xsl:attribute name="static">
					<xsl:choose>
					<xsl:when test="starts-with(type,'const')">
					<xsl:value-of select="'true'"/>
					</xsl:when>
					<xsl:otherwise>
					<xsl:value-of select="'false'"/>
					</xsl:otherwise>
					</xsl:choose>
					</xsl:attribute>
				-->
				<xsl:attribute name="visibility" select="@prot" />
				<xsl:attribute name="static">
					<xsl:choose>
						<xsl:when test="@static='yes'">
							<xsl:value-of select="'true'" />
						</xsl:when>
						<xsl:when test="@static='no'">
							<xsl:value-of select="'false'" />
						</xsl:when>
					</xsl:choose>
				</xsl:attribute>
				<xsl:attribute name="const">
					<xsl:choose>
						<xsl:when test="@const='yes'">
							<xsl:value-of select="'true'" />
						</xsl:when>
						<xsl:when test="@const='no' or not(@const)">
							<xsl:value-of select="'false'" />
						</xsl:when>
					</xsl:choose>
				</xsl:attribute>

				<xsl:if test="type and type!='virtual'">
					<xsl:call-template name="type" />
				</xsl:if>
				<xsl:if test="argsstring!=''">
					<xsl:element name="argsstring">
						<xsl:value-of select="argsstring" />
					</xsl:element>
				</xsl:if>
				<xsl:element name="definition">
					<xsl:value-of select="definition" />
				</xsl:element>
				<xsl:element name="name">
					<xsl:value-of select="name" />
				</xsl:element>
			</xsl:element>
		</xsl:for-each>
	</xsl:template>

	<!-- ############ DOCUMENTATION ############ -->
	<xd:doc>
		<xd:short>
			Generates a
			<b>briefdescription</b>
			and a
			<b>detaileddescription</b>
			element.
		</xd:short>
		<xd:detail>
			This template just copys the existing documentation from
			all.xml to meta.xml.
		</xd:detail>
	</xd:doc>
	<xsl:template name="documentation">
		<xsl:if test="briefdescription/*">
			<xsl:copy-of select="briefdescription" />
		</xsl:if>
		<xsl:if test="detaileddescription/*">
			<xsl:copy-of select="detaileddescription" />
		</xsl:if>
	</xsl:template>

	<!-- ############ STRUCT ATTRIBUTES ############ -->
	<xd:doc>
		<xd:short>
			Generates elements for attributes of structs.
		</xd:short>
		<xd:detail>
			It is needed for two cases in template struct
		</xd:detail>
	</xd:doc>
	<xsl:template name="structattributes">
		<xsl:for-each select="memberdef[@kind='variable']">
			<xsl:element name="param">
				<xsl:choose>
					<xsl:when test="contains(type, '&amp;')">
						<xsl:attribute name="passedBy">
							reference
						</xsl:attribute>
					</xsl:when>
					<xsl:when test="contains(type, '*')">
						<xsl:attribute name="passedBy">
							pointer
						</xsl:attribute>
					</xsl:when>
				</xsl:choose>
				<xsl:element name="name">
					<xsl:value-of select="name" />
				</xsl:element>
				<xsl:call-template name="typeMap">
					<xsl:with-param name="type"
						select="normalize-space(type)" />
				</xsl:call-template>
				<xsl:if test="argsstring!=''">
					<xsl:element name="argsstring">
						<xsl:value-of select="argsstring" />
					</xsl:element>
				</xsl:if>
			</xsl:element>
		</xsl:for-each>
	</xsl:template>



	<xsl:template name="createDefaultConstructor">
		<xsl:param name="className" />

		<!-- generate default c-tor if necessary -->
		<xsl:if
			test="not(sectiondef[@kind='public-func']/memberdef/name=$className) and
					  not(sectiondef[@kind='private-func']/memberdef/name=$className) and
					  not(sectiondef[@kind='protected-func']/memberdef/name=$className)">
			<xsl:element name="function">
				<xsl:attribute name="virt">
					<xsl:text>non-virtual</xsl:text>
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
				<xsl:element name="name">
					<xsl:value-of select="$className" />
				</xsl:element>
				<xsl:element name="definition">
					<xsl:value-of
						select="concat(compoundname, '::', $className)" />
				</xsl:element>

			</xsl:element>
		</xsl:if>
	</xsl:template>



	<xsl:template name="classAndStructBody">
		<xsl:param name="refid" />

		<xsl:variable name="className">
			<xsl:choose>

				<!-- if this class is inside a namespace -->
				<xsl:when test="contains(compoundname,'::')">
					<xsl:variable name="compoundNameTokens">
						<xsl:call-template name="str:split">
							<xsl:with-param name="string"
								select="compoundname" />
							<xsl:with-param name="pattern"
								select="'::'" />
						</xsl:call-template>
					</xsl:variable>
					<xsl:value-of
						select="$compoundNameTokens/token[last()]">
					</xsl:value-of>
				</xsl:when>

				<xsl:otherwise>
					<xsl:value-of select="compoundname" />
				</xsl:otherwise>

			</xsl:choose>
		</xsl:variable>
		<xsl:attribute name="name" select="$className" />
		<xsl:attribute name="fullName" select="compoundname" />

		<!-- template attributes -->
		<xsl:if test="templateparamlist">
			<xsl:attribute name="template" select="'true'" />
<!-- 
			<xsl:attribute name="templateType"
				select="templateparamlist/param/type" />
			<xsl:attribute name="templateDeclaration"
				select="templateparamlist/param/declname" />
 -->
			<xsl:element name="templateparameters">
				<xsl:for-each select="templateparamlist/param">
					<xsl:element name="templateparameter">
						<xsl:attribute name="templateType" select="type" />
						<xsl:attribute name="templateDeclaration" select="declname" />
					</xsl:element>
				</xsl:for-each>
			</xsl:element>

			<xsl:for-each select="inheritancegraph/node">
				<xsl:if test="link/@refid=$refid">
					<xsl:variable name="childnode"
						select="childnode/@refid" />
					<xsl:for-each select="../node">
						<xsl:if test="@id=$childnode">
							<xsl:attribute name="templateName">
								<xsl:variable name="string"
									select="substring-before(label,' &gt;')" />
								<xsl:value-of
									select="substring-after($string,'&lt; ')" />
							</xsl:attribute>
						</xsl:if>
					</xsl:for-each>
				</xsl:if>
			</xsl:for-each>

		</xsl:if> <!-- template -->

		<!-- getting the right name of inner classes -->
		<xsl:variable name="name"
			select="substring-after(compoundname,'::')" />
		<!-- 
		<xsl:if test="contains($name,'::')">
			<xsl:attribute name="name"
				select="substring-after($name,'::')" />
			<xsl:variable name="name"
				select="substring-after($name,'::')" />
			<xsl:if test="contains($name,'::')">
				<xsl:attribute name="name"
					select="substring-after($name,'::')" />
				<xsl:variable name="name"
					select="substring-after($name,'::')" />
				<xsl:if test="contains($name,'::')">
					<xsl:attribute name="name"
						select="substring-after($name,'::')" />
				</xsl:if>
			</xsl:if>
		</xsl:if>
		 -->

		<!-- copy all includes into meta output -->
		<xsl:copy-of copy-namespaces="no" select="includes" />


		<!-- cursor on doxygen/compounddef[@kind="class"] -->
		<!-- derivation -->
		<xsl:call-template name="derivation">
			<xsl:with-param name="refid" select="$refid" />
		</xsl:call-template>
		<!-- enumerations -->
		<xsl:for-each select="sectiondef[@kind='public-type']">
			<!-- or @kind='protected-type'-->
			<xsl:choose>
				<xsl:when test="memberdef[@kind='enum']">
					<xsl:call-template name="enumeration" />
				</xsl:when>
			</xsl:choose>
		</xsl:for-each>
		<!-- typedefs -->
		<xsl:for-each select="sectiondef[@kind='public-type']">
			<xsl:choose>
				<xsl:when test="memberdef[@kind='typedef']">
					<xsl:call-template name="typedef" />
				</xsl:when>
			</xsl:choose>
		</xsl:for-each>
		<!-- public variables -->
		<xsl:for-each
			select="sectiondef[@kind='public-attrib' or @kind='public-static-attrib']">
			<xsl:call-template name="variable" />
		</xsl:for-each>
		<!-- public functions -->
		<xsl:for-each select="sectiondef[@kind='public-func']">
			<xsl:choose>
				<xsl:when test="memberdef[@kind='function']">
					<xsl:call-template name="function" />
				</xsl:when>
			</xsl:choose>
		</xsl:for-each>
		<!-- static functions -->
		<xsl:for-each select="sectiondef[@kind='public-static-func']">
			<xsl:choose>
				<xsl:when test="memberdef[@kind='function']">
					<xsl:call-template name="function" />
				</xsl:when>
			</xsl:choose>
		</xsl:for-each>

		<xsl:call-template name="createDefaultConstructor">
			<xsl:with-param name="className">
				<xsl:value-of select="$className" />
			</xsl:with-param>
		</xsl:call-template>

		<!-- recursion for inner classes -->
		<xsl:for-each select="innerclass">
			<xsl:call-template name="class">
				<xsl:with-param name="refid" select="@refid" />
			</xsl:call-template>
		</xsl:for-each>

		<!-- documentation -->
		<xsl:call-template name="documentation" />
	</xsl:template>



</xsl:stylesheet>
<!--
	How to use the version from the old generator project:
	
	Using the Stylesheet with version 2.0 with Saxon:
	java -jar bin/saxon8_2.jar -o build/meta.xml build/all.xml xslt/input.xslt
	memory problems, try this:
	java -Xmx512M -jar bin/saxon8_2.jar -o build/meta.xml build/all.xml xslt/input.xslt
-->