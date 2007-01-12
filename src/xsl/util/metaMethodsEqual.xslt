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

	<xd:doc type="stylesheet">
		<xd:short>helper functions to check if methods are overloaded</xd:short>
	</xd:doc>

	<xd:doc type="function">
		<xd:short>check if two methods have the same name and parameter types</xd:short>
	</xd:doc>
	<xsl:function name="xbig:areTheseMethodsEqualExceptConst" as="xs:boolean">
		<xsl:param name="meth1"/>
		<xsl:param name="meth2"/>

		<xsl:choose>

			<!-- test if both methods have the same name -->
			<xsl:when test="$meth1/name = $meth2/name">
				<xsl:choose>

					<!-- test if both methods have the same number of parameters -->
					<xsl:when test="count($meth1/parameters) = count($meth2/parameters)">
						<xsl:variable name="parameterEquality">
							<xsl:for-each select="$meth1/parameters/parameter">
								<xsl:element name="para">
									<xsl:choose>

										<!-- test if each parameter has the same type 
											 and is passed by the same way
											 for both methods -->
										<xsl:when test="./type = $meth2/parameters/parameter[position()]/type and
														./@passedBy = $meth2/parameters/parameter[position()]/@passedBy">
											<xsl:value-of select="true()"/>
										</xsl:when>

										<!-- parameter type or passed by is different -->
										<xsl:otherwise>
											<xsl:value-of select="false()"/>
										</xsl:otherwise>
									</xsl:choose>
								</xsl:element>
							</xsl:for-each>
						</xsl:variable>

						<!-- calc one result of all parameters -->
						<xsl:choose>
							<xsl:when test="$parameterEquality/* = false()">
								<xsl:value-of select="false()"/>
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of select="true()"/>
							</xsl:otherwise>
						</xsl:choose>
					</xsl:when>

					<!-- if the number of parameters is different -->
					<xsl:otherwise>
						<xsl:value-of select="false()"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>

			<!-- if the name is different -->
			<xsl:otherwise>
				<xsl:value-of select="false()"/>
			</xsl:otherwise>
		</xsl:choose>

	</xsl:function>

	<xd:doc type="function">
		<xd:short>check if two methods have the same constness, same name and parameter types</xd:short>
	</xd:doc>
	<xsl:function name="xbig:areTheseMethodsEqual" as="xs:boolean">
		<xsl:param name="meth1"/>
		<xsl:param name="meth2"/>

		<xsl:variable name="equalWithoutConst" select="xbig:areTheseMethodsEqualExceptConst($meth1, $meth2)"/>

		<!-- test if both methods have the same constness -->
		<xsl:choose>
			<xsl:when test="$equalWithoutConst">
				<xsl:choose>
					<xsl:when test="$meth1/@const = $meth2/@const">
						<xsl:value-of select="true()"/>
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="false()"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>

			<!-- if the constness is different -->
			<xsl:otherwise>
				<xsl:value-of select="false()"/>
			</xsl:otherwise>

		</xsl:choose>
	</xsl:function>

</xsl:stylesheet>
