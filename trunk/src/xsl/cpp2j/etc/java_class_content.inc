
/**
 * <p>
 * This constructor is public for internal useage only!
 * Do not use it!
 * </p>
 */
public #classname#(org.xbig.base.InstancePointer p) {
	super(p);
}

protected #classname#(org.xbig.base.InstancePointer p, boolean remote) {
	super(p, remote);
}

public void delete() {
	if (this.remote)
       throw new RuntimeException("can't dispose object not created by native library");

    __delete(object.pointer);
    this.deleted = true;
}
	
public void finalize() {
	if(!this.remote &amp;&amp; !this.deleted)
		delete();
}
	
			
private final native void __delete(long _pointer_);	


