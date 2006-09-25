package org.xbig.base;

public class CharArray extends CharPointer {

	/**
	 * length of the array
	 */
	private int length = 0;

	/**
	 * iteration count. incremented by #next()
	 */
	private int count = 0;

	protected CharArray(InstancePointer pInstance) {
		super(pInstance);
	}

	public CharArray(int length) {
		super(new InstancePointer(_createInstance(length)), false);
		this.length = length;
	}

	private static native long _createInstance(int length);

	public int getLength() {
		return length;
	}

	@Override
	public Character get() {
		if (count == length)
			throw new IndexOutOfBoundsException();
		return super.get();
	}

	@Override
	public CharPointer next() {
		this.count++;
		if (count == length)
			throw new IndexOutOfBoundsException();
		return super.next();
	}

	@Override
	public void set(Character value) {
		if (count == length)
			throw new IndexOutOfBoundsException();
		super.set(value);
	}
	
	public Character get(int index)
	{
		if (index >= length || index < 0)
			throw new IndexOutOfBoundsException();
		return _get(object.pointer, index);
	}
	public void set(Character value, int index)
	{
		if (index >= length || index < 0)
			throw new IndexOutOfBoundsException();
		_set(object.pointer, value, index);
	}
	
	private native char _get(long pInstance, int index);
	private native void _set(long pInstance, char value, int index);
}
