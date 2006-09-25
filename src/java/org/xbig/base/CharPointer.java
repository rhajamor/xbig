package org.xbig.base;

public class CharPointer extends NumberPointer<Character> {
	
	public CharPointer(InstancePointer pInstance) {
		super(pInstance);
	}

	public CharPointer(InstancePointer pointer, boolean b) {
		super(pointer,b);
	}

	private native void _dispose(long pInstance);

	private native char _get(long pInstance);

	private native long _next(long pInstance);

	private native void _set(long pInstance, char value);

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
		if (obj instanceof CharPointer) {
			return this._get(object.pointer) == ((CharPointer) obj)._get(object.pointer);			
		}
		return super.equals(obj);
	}
	@Override
	public float floatValue() {
		return (float) _get(object.pointer);
	}
	public Character get()
	{
		return _get(object.pointer);
	}
	@Override
	public int hashCode() {
		return intValue();
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
	public CharPointer next() {
		long ptr = _next(object.pointer);
		if(ptr==0)return null;		
		return new CharPointer(new InstancePointer(ptr));
	}
	
	public void set(Character value) {
		_set(object.pointer, value);
	}

	@Override
	public String toString() {
		return Character.toString(get());
	}
}
