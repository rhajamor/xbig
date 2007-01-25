
protected #classname#(org.xbig.base.InstancePointer p) {
	super(p);
}

/**
 * <p>
 * Usually this constructor should not be used!
 * But there is an exception:
 * </p>
 * <br></br>
 * <p>
 * This constructor can be used for template return values.
 * see org.xbig.base.ParametrizedTemplateReturnPlaceHolder
 * </p>
 * <br></br>
 * <p>
 * set p to the InstancePointer of the object you get
 * and remote to true
 * </p>
 */
public #classname#(org.xbig.base.InstancePointer p, boolean remote) {
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


