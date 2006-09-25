/* This source file is part of ogre4j
 *     (The JNI bindings for OGRE)
 * For the latest info, see http://www.ogre4j.org/
 * 
 * Copyright (c) 2005 netAllied GmbH, Tettnang
 * Also see acknowledgements in Readme.html
 * 
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307, USA, or go to
 * http://www.gnu.org/copyleft/lesser.txt.
 * 
 * 
 * InstancePointer.java
 * 
 * Version Information
 * -------------------
 * $Revision: 1.1 $
 * $Date: 2006/09/20 11:36:09 $
 * $Author: bielig $
 */
package org.xbig.base;

/**
 * Wrapper for native pointer values.
 * 
 * @author Kai Klesatschke <yavin@ogre4j.org>
 * @author Hubert Rung <hubert.rung@netallied.de>
 */
public class InstancePointer {
	
	public long pointer;

	public InstancePointer(long value) {
		this.pointer = value;
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
	public int hashCode() {
		return (int) pointer;
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	public boolean equals(Object obj) {
		if (obj instanceof InstancePointer)
			return pointer == ((InstancePointer) obj).pointer;

		return false;
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		return Long.toString(pointer);
	}
}
