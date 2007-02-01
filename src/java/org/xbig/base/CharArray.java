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

public class CharArray extends CharPointer {

	/**
	 * length of the array
	 */
	private int length = 0;

	/**
	 * iteration count. incremented by #next()
	 */
	private int count = 0;

	protected CharArray(InstancePointer pInstance) {
		super(pInstance);
	}

	public CharArray(int length) {
		super(new InstancePointer(_createInstance(length)), false);
		this.length = length;
	}

	private static native long _createInstance(int length);

	public int getLength() {
		return length;
	}

	@Override
	public Character get() {
		if (count == length)
			throw new IndexOutOfBoundsException();
		return super.get();
	}

	@Override
	public CharPointer next() {
		this.count++;
		if (count == length)
			throw new IndexOutOfBoundsException();
		return super.next();
	}

	@Override
	public void set(Character value) {
		if (count == length)
			throw new IndexOutOfBoundsException();
		super.set(value);
	}
	
	public Character get(int index)
	{
		if (index >= length || index < 0)
			throw new IndexOutOfBoundsException();
		return _get(object.pointer, index);
	}
	public void set(Character value, int index)
	{
		if (index >= length || index < 0)
			throw new IndexOutOfBoundsException();
		_set(object.pointer, value, index);
	}
	
	private native char _get(long pInstance, int index);
	private native void _set(long pInstance, char value, int index);
}
