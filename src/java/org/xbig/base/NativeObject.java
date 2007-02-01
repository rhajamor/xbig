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
 * $Author: bielig $
 */
package org.xbig.base;

public abstract class NativeObject implements INativeObject {

	/**
	 * Load native library
	 */
	static {
		System.loadLibrary("cpp2j-base");
	}

	/**
	 * Indicates if the native instance is created by the underlying library.
	 */
	protected boolean remote;
	
	/**
	 * Indicates if the native instance is deleted.
	 */
	protected boolean deleted;

	/**
	 * The pointer to the native instance. Stores the native reference.
	 */
	public InstancePointer object;

	/**
	 * Needed for Interfaces which are needed for multiple inheritance
	 * 
	 * @return the object
	 */
	public InstancePointer getInstancePointer() {
		return object;
	}

	/**
	 * Internal default constructor.
	 */
	protected NativeObject() {
	}

	/**
	 * Internal convenience construtcotr for NativeObject(pInstance, false).
	 * <p>
	 * <b>Never use this constructor. It is for internal usage only!</b>
	 * </p>
	 * 
	 * @param pInstance
	 *            The instance pointer to set.
	 */
	protected NativeObject(InstancePointer pInstance) {
		this(pInstance, true);
	}

	/**
	 * Internal constructor.<br>
	 * <b>Never use this constructor. It is for internal usage only!</b>
	 * 
	 * @param pInstance
	 *            The instance pointer to set.
	 * @param remote
	 *            If the instance was created by the underlying library.
	 */
	protected NativeObject(InstancePointer pInstance, boolean remote) {
		setInstancePointer(pInstance, remote);
	}

	/* (non-Javadoc)
	 * @see INativeObject#delete()
	 */
	public abstract void delete();

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	public boolean equals(Object obj) {
		if (obj instanceof NativeObject) {
			return object.equals(((NativeObject) obj).object);
		}
		return false;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#hashCode()
	 */
	public int hashCode() {
		return object.hashCode();
	}

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
	public void setInstancePointer(InstancePointer pInstance,
			boolean argRemote) {
		if(pInstance == null || pInstance.pointer == 0)
			throw new NullPointerException("Instance pointer is null!");
		this.object = pInstance;
		this.remote = argRemote;
	}

	/* (non-Javadoc)
	 * @see INativeObject#setInstancePointer(long)
	 */
	public void setInstancePointer(long pInstance) {
		setInstancePointer(pInstance, true);
	}

	/* (non-Javadoc)
	 * @see INativeObject#setInstancePointer(long, boolean)
	 */
	public void setInstancePointer(long pInstance, boolean createdByLibray) {
		setInstancePointer(new InstancePointer(pInstance), createdByLibray);
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		StringBuffer buf = new StringBuffer();
		buf.append("Native Ref: ");
		buf.append(object.toString());
		return buf.toString();
	}
}