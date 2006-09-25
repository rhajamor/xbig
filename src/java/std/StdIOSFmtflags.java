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
package std;

import org.xbig.base.InstancePointer;
import org.xbig.base.NativeObject;

public class StdIOSFmtflags<T> extends NativeObject {

	protected StdIOSFmtflags(InstancePointer pInstance) {
		super(pInstance);
	}

	protected StdIOSFmtflags(InstancePointer pInstance, boolean createdByLibrary) {
		super(pInstance, createdByLibrary);
	}

	public void delete() {
		if (this.remote)
			throw new RuntimeException(
					"can't dispose object created by the library");
		_dispose(object.pointer);
	}

	public T boolalpha, dec, fixed, hex, internal, left, oct, right,
			scientific, showbase, showpoint, showpos, skipws, unitbuf,
			uppercase, adjustfield, basefield, floatfield;

	private native void _dispose(long pInstance);
}
