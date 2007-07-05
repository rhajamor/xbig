
/**
 * <p>
 * This constructor is public for internal useage only!
 * Do not use it!
 * </p>
 */
public #classname#(org.xbig.base.InstancePointer p) {
	super(p);
}

/**
 * <p>
 * Creates a Java wrapper object for an existing C++ object.
 * If remote is set to 'true' this object cannot be deleted in Java.
 * </p>
 */
protected #classname#(org.xbig.base.InstancePointer p, boolean remote) {
	super(p, remote);
}

/**
 * {@inheritDoc}
 */
public #classname#(org.xbig.base.WithoutNativeObject val) {
	super(val);
}

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

public void finalize() {
	if(!this.remote &amp;&amp; !this.deleted) {
		delete();
	}
}
	
			
private final native void __delete(long _pointer_);	


