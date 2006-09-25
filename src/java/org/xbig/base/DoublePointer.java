package org.xbig.base;

public class DoublePointer extends NumberPointer<Double> {
	
	public DoublePointer(InstancePointer pInstance) {
		super(pInstance);
	}

	private native void _dispose(long pInstance);

	private native double _get(long pInstance);

	private native long _next(long pInstance);

	private native void _set(long pInstance, double value);

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
		if (obj instanceof DoublePointer) {
			return this._get(object.pointer) == ((DoublePointer) obj)._get(object.pointer);			
		}
		return super.equals(obj);
	}
	@Override
	public float floatValue() {
		return (float) _get(object.pointer);
	}
	public Double get()
	{
		return _get(object.pointer);
	}
	@Override
	public int hashCode() {
		long bits = Double.doubleToLongBits(_get(object.pointer));
		return (int)(bits ^ (bits >>> 32));
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
	public DoublePointer next() {
		long ptr = _next(object.pointer);
		if(ptr==0)return null;		
		return new DoublePointer(new InstancePointer(ptr));
	}
	public void set(Double value) {
		_set(object.pointer, value);
	}

	@Override
	public String toString() {
		return Double.toString(get());
	}
}
