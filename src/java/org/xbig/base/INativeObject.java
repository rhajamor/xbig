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
 * NativeObject.java
 * 
 * Version Information
 * -------------------
 * $Revision: 1.1 $
 * $Date: 2006/09/20 11:36:09 $
 * $Author: nenning $
 */
package org.xbig.base;

public interface INativeObject {

	/**
	 * Needed for Interfaces which are needed for multiple inheritance
	 * 
	 * @return the object
	 */
	InstancePointer getInstancePointer();

	/**
	 * Subclasses must implement this but if the native instance was created by
	 * the underlying library the native call to dispose must <b>not</b>
	 * happen!
	 * 
	 * @see #remote
	 */
	void delete();

	/**
	 * Sets the instance pointer for the native object that is managed by this
	 * java object.
	 * <p>
	 * <b>Note:</b> This is an internal method. Do not use it to change the
	 * instance pointer!
	 * </p>
	 * 
	 * @param pInstance
	 *            The instance pointer to set.
	 * @param argRemote
	 *            If the native object is created by the underlaying library.
	 * @throws NullPointerException if the instance pointer is null.          
	 */
	void setInstancePointer(InstancePointer pInstance, boolean argRemote);

	/**
	 * Convenience method to set the instance pointer. Sets the createdByLibrary
	 * flag to true.
	 * <p>
	 * <b>Note:</b> This is an internal method. Do not use it to change the
	 * instance pointer!
	 * </p>
	 * 
	 * @see #setInstancePointer(long, boolean)
	 */
	void setInstancePointer(long pInstance);

	/**
	 * Convenience method to set the instance pointer. Creates the
	 * InstancePointer object.
	 * <p>
	 * <b>Note:</b> This is an internal method. Do not use it to change the
	 * instance pointer!
	 * </p>
	 * 
	 * @see #setInstancePointer(InstancePointer, boolean)
	 */
	void setInstancePointer(long pInstance, boolean createdByLibray);

}