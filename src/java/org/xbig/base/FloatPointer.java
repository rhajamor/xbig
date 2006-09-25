package org.xbig.base;

public class FloatPointer extends NumberPointer<Float> {
	
	public FloatPointer(InstancePointer pInstance) {
		super(pInstance);
	}

	private native void _dispose(long pInstance);

	private native float _get(long pInstance);

	private native long _next(long pInstance);

	private native void _set(long pInstance, float value);

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
		if (obj instanceof FloatPointer) {
			return this._get(object.pointer) == ((FloatPointer) obj)._get(object.pointer);			
		}
		return super.equals(obj);
	}
	@Override
	public float floatValue() {
		return _get(object.pointer);
	}
	public Float get()
	{
		return _get(object.pointer);
	}
	@Override
	public int hashCode() {
		return Float.floatToIntBits(_get(object.pointer));
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
	public FloatPointer next() {
		long ptr = _next(object.pointer);
		if(ptr==0)return null;		
		return new FloatPointer(new InstancePointer(ptr));
	}

	public void set(Float value) {
		_set(object.pointer, value);
	}

	@Override
	public String toString() {
		return Float.toString(get());
	}
}
