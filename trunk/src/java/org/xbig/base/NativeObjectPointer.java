/**
 * NativeObjectPointer.java
 *
 * Copyright &copy; 2007, netAllied GmbH, Tettnang, Germany.
 * 
 * Version Information
 * -------------------
 * $Revision: $
 * $Date: $
 * $Author: $
 */
package org.xbig.base;

/**
 * The native object pointer is a generic to handle pointer pointers in C. E.g.
 * float ** a.
 * 
 * @author Kai Klesatschke <kai.klesatschke@netallied.de>
 */
public class NativeObjectPointer<T extends INativeObject> extends NativeObject
{
    /**
     * Creates a new java object that points to a pointer-pointer created
     * remote.
     * 
     * <p>
     * <b>Note:</b> This is not public API. Constructor is public for
     * internal use only.
     * </p>
     * 
     * @param pInstance
     *            The instance pointer for this NativeObjectPointer.
     */
    public NativeObjectPointer(InstancePointer pInstance)
    {
        super(pInstance);
    }

    /**
     * Native function to retreive the pointer pointer.
     * @param pInstance The this pointer.
     * @return The pointer pointer.
     */
    private native long _getObject(long pInstance);

    /* (non-Javadoc)
     * @see org.xbig.base.NativeObject#delete()
     */
    @Override
    public void delete()
    {
        //do nothing. user should never call this function.        
    }

    /**
     * Retreives the native object this NativeObjectPointer points to.
     * <p>
     * <b>Note:</b> For the given native object this function will free
     * possible alocated memory by calling {@link INativeObject#delete()}.
     * </p>
     * 
     * @param nativeObject
     *            The native object to set the instance pointer.
     * @throws NullPointerException
     *             if the native object is null.
     */
    public void getObject(T nativeObject)
    {
        nativeObject.delete();
        long ptr = _getObject(object.pointer);
        if (ptr == 0)
            throw new NullPointerException();
        nativeObject.setInstancePointer(ptr);
    }
}
