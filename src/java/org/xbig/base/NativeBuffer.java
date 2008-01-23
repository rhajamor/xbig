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
 * Allows allocation of a memory region.
 * 
 */
public class NativeBuffer extends NativeObject {

    /**
     * Size of this buffer.
     */
    private int size = 0;

    /*
     * (non-Javadoc)
     * 
     * @see org.xbig.base.NativeObject#NativeObject(InstancePointer)
     */
    public NativeBuffer(InstancePointer pInstance) {
        super(pInstance);
    }

    /*
     * (non-Javadoc)
     * 
     * @see org.xbig.base.NativeObject#NativeObject(InstancePointer, boolean)
     */
    public NativeBuffer(InstancePointer pointer, boolean b) {
        super(pointer,b);
    }

    /**
     * Allocate memory of passed size.
     * 
     * @param size Size of memory to allocate.
     */
    public NativeBuffer(int size) {
        super(new InstancePointer(_create(size)),false);
        this.size = size;
    }

    private static native long _create(int size);

    private native void _dispose(long pInstance);

    /**
     * @{inheritdoc}
     * @see org.xbig.base.NativeObject#delete()
     */
    @Override
    public void delete() {
        if(this.remote)
            throw new RuntimeException("Instance created by the library! It's not allowed to dispose it.");
        _dispose(object.pointer);
        this.deleted = true;
    }

    /**
     * Get value from buffer at a given index.
     * 
     * @param index Index to get value from.
     */
    public byte getIndex(int index) {
        if (this.deleted) {
            throw new IllegalStateException();
        }
        if (index < 0 || index > this.size) {
            throw new IllegalArgumentException();
        }
        return _getIndex(object.pointer, index);
    }
    private native byte _getIndex(long pInstance, int index);

    /**
     * Get size of this buffer.
     * 
     * @return Size of this buffer.
     */
    public int getSize() {
        return this.size;
    }
}