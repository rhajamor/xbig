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

/**
 * The type_info class describes type information generated within the program
 * by the compiler. Objects of this class effectively store a pointer to a name
 * for the type. The type_info class also stores an encoded value suitable for
 * comparing two types for equality or collating order. The encoding rules and
 * collating sequence for types are unspecified and may differ between programs.
 * see std::typeinfo
 * 
 * @author hrung
 */
public class TypeInfo extends NativeObject {

	public TypeInfo(InstancePointer pInstance) {
		super(pInstance);
	}

	private native int _before(long pInstance, long rhsTypeInfo);

	private native String _name(long pInstance);

	private native String _raw_name(long pInstance);

	public int before(TypeInfo rhs) {
		return _before(object.pointer, rhs.object.pointer);
	}

	@Override
	public void delete() {
		// Does nothing because you cannot instantiate objects of the type_info class directly,
		// because the class has only a private copy constructor. The only way
		// to construct a (temporary) type_info object is to use the typeid
		// operator. Since the assignment operator is also private, you cannot
		// copy or assign objects of class type_info.
	}

	/**
	 * @return returns A string representing the human-readable name of the
	 *         type.
	 */
	public String name() {
		return _name(object.pointer);
	}

	/**
	 * @return A string representing the decorated name of the object type. The
	 *         name is actually stored in its decorated form to save space.
	 *         Consequently, this function is faster than type_info::name
	 *         because it doesn't need to undecorate the name. The string
	 *         returned by the type_info::raw_name function is useful in
	 *         comparison operations but is not readable. If you need a
	 *         human-readable string, use the type_info::name function instead.
	 */
	public String raw_name() {
		return _raw_name(object.pointer);
	}

}
