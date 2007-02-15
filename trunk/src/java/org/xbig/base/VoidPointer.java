/* This source file is part of XBiG
 *     (XSLT Bindings Generator)
 * For the latest info, see http://sourceforge.net/projects/xbig/
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
 */
package org.xbig.base;

public class VoidPointer extends NativeObject {
	
	public VoidPointer(InstancePointer pInstance) {
		super(pInstance);
	}

	public VoidPointer(InstancePointer pointer, boolean b) {
		super(pointer,b);
	}

	private native void _dispose(long pInstance);

	@Override
	public void delete() {
		if(this.remote)
			throw new RuntimeException("Instance created by the library! It's not allowed to dispose it.");
		//_dispose(object.pointer);
		throw new RuntimeException("deleting ‘void*’ is undefined");
	}
	@Override
	public boolean equals(Object obj) {
		if (obj instanceof VoidPointer) {
			return this.object.pointer == ((VoidPointer) obj).object.pointer;			
		}
		return super.equals(obj);
	}
}
