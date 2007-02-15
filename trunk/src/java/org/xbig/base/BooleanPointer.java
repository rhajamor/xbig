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

public class BooleanPointer extends NumberPointer<Boolean> {

	public BooleanPointer(InstancePointer pInstance) {
		super(pInstance);
	}

	public BooleanPointer(int value) {
		super(new InstancePointer(_create(value)),false);
	}

	private static native long _create(int value);

	private native void _dispose(long pInstance);

	private native boolean _get(long pInstance);	
	
	private native long _next(long pInstance);

	private native void _set(long pInstance, boolean value);

	@Override
	public void delete() {
		if(this.remote)
			throw new RuntimeException("Instance created by the library! It's not allowed to dispose it.");
		_dispose(object.pointer);
	}
	
	@Override
	public double doubleValue() {
		if(_get(object.pointer))
			return 1.0;
		return 0.0;
	}

	@Override
	public boolean equals(Object obj) {
		if (obj instanceof BooleanPointer) {
			return this._get(object.pointer) == ((BooleanPointer) obj)._get(object.pointer);			
		}
		return super.equals(obj);
	}
	
	@Override
	public float floatValue() {
		if(_get(object.pointer))
			return 1.0F;
		return 0.0F;
	}
	public Boolean get()
	{
		return _get(object.pointer);
	}
	@Override
	public int hashCode() {
		if(_get(object.pointer))
			return 1;
		return 0;
	}

	@Override
	public int intValue() {		
		if(_get(object.pointer))
			return 1;
		return 0;
	}

	@Override
	public long longValue() {		
		if(_get(object.pointer))
			return 1L;
		return 0L;
	}

	@Override
	public BooleanPointer next() {
		long ptr = _next(object.pointer);
		if(ptr==0)return null;		
		return new BooleanPointer(new InstancePointer(ptr));
	}
	
	public void set(Boolean value) {
		_set(object.pointer, value);
	}

	@Override
	public String toString() {
		return Boolean.toString(_get(object.pointer));
	}
}
