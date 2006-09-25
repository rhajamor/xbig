package org.xbig.base;

public class LongPointer extends NumberPointer<Long> {
	
	public LongPointer(InstancePointer pInstance) {
		super(pInstance);
	}

	private native void _dispose(long pInstance);

	private native long _get(long pInstance);

	private native long _next(long pInstance);

	private native void _set(long pInstance, long value);

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
		if (obj instanceof LongPointer) {
			return this._get(object.pointer) == ((LongPointer) obj)._get(object.pointer);			
		}
		return super.equals(obj);
	}
	@Override
	public float floatValue() {
		return (float) _get(object.pointer);
	}
	public Long get()
	{
		return _get(object.pointer);
	}
	@Override
	public int hashCode() {
		long value = _get(object.pointer);
		return (int)(value ^ (value >>> 32));
	}

	@Override
	public int intValue() {
		return (int) _get(object.pointer);
	}

	@Override
	public long longValue() {
		return (long) _get(object.pointer);
	}

	@Override
	public LongPointer next() {
		long ptr = _next(object.pointer);
		if(ptr==0)return null;		
		return new LongPointer(new InstancePointer(ptr));
	}
	
	public void set(Long value)	{
		_set(object.pointer, value);
	}

	@Override
	public String toString() {
		return Long.toString(get());
	}
}
