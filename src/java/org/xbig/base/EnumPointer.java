package org.xbig.base;


/**
 * 
 * This class maintains the adress of a single integer.
 * It makes sure that only allowed enumeration values of
 * it's type parameter are used.
 * 
 */
public class EnumPointer < T extends INativeEnum > extends NativeObject {

    /**
     * Needed to get access to allowed enumeration values.
     */
    private T val;

    /**
     * Allows native methods to return EnumPointers.
     */
    public EnumPointer(InstancePointer p, T val) {
        super(p);
        this.val = val;
    }

    /**
     * Constructor to create an integer variable on the heap
     * and initialise it with an allowed value.
     */
    public EnumPointer(T val) {
        super( new org.xbig.base.InstancePointer(__createEnumPointer(val.getValue())), false);
        this.val = val;
    }

    private native static long __createEnumPointer(int value);

    /**
     * Frees the memory used by the integer value.
     */
    public void delete() {
        if (this.remote) {
           throw new RuntimeException("can't dispose object created by native library");
        }

        if(!this.deleted) {
            __delete(object.pointer);
            this.deleted = true;
            this.object.pointer = 0;
        }
    }

    /**
     * If a client programmer forgets to free memory
     * there is a chance that the GC does it.
     */
    public void finalize() {
        if(!this.remote && !this.deleted) {
            delete();
        }
    }

    private final native void __delete(long _pointer_); 


    /**
     * Sets the integer value.
     */
    public void set(T val) {
        _set(this.object.pointer, val.getValue());
    }

    private native static void _set(long _pointer_, int value);

    /**
     * Returns the enumeration value.
     */
    public T get() {
        return (T)val.getEnum(_get(this.object.pointer));
    }

    private native static int _get(long _pointer_);
}
