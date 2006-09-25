package org.xbig.base;

public class IntegerPointer extends NumberPointer<Integer> {

	public IntegerPointer(InstancePointer pInstance) {
		super(pInstance);
	}

	private native void _dispose(long pInstance);

	private native int _get(long pInstance);	
	
	private native long _next(long pInstance);

	private native void _set(long pInstance, int value);

	@Override
	public void delete() {
		if(this.remote)
			throw new RuntimeException("Instance created by the library! It's not allowed to dispose it.");
		_dispose(object.pointer);
	}
	
	@Override
	public double doubleValue() {
		return _get(object.pointer);
	}

	@Override
	public boolean equals(Object obj) {
		if (obj instanceof IntegerPointer) {
			return this._get(object.pointer) == ((IntegerPointer) obj)._get(object.pointer);			
		}
		return super.equals(obj);
	}
	
	@Override
	public float floatValue() {
		return _get(object.pointer);
	}
	public Integer get()
	{
		return _get(object.pointer);
	}
	@Override
	public int hashCode() {
		return _get(object.pointer);
	}

	@Override
	public int intValue() {		
		return _get(object.pointer);
	}

	@Override
	public long longValue() {		
		return _get(object.pointer);
	}

	@Override
	public IntegerPointer next() {
		long ptr = _next(object.pointer);
		if(ptr==0)return null;		
		return new IntegerPointer(new InstancePointer(ptr));
	}
	
	public void set(Integer value) {
		_set(object.pointer, value);
	}

	@Override
	public String toString() {
		return Integer.toString(_get(object.pointer));
	}
}
