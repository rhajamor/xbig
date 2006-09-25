package org.xbig.base;

/**
 * Native number represents pointers of native primitive numeric values. E.g
 * int. This allows the user to work with primitive values returned in a pointer
 * or by reference.
 * 
 * @author hrung
 */
public abstract class NumberPointer<T> extends NativeObject {

	public NumberPointer(InstancePointer pInstance) {
		super(pInstance);
	}

	public NumberPointer(InstancePointer pointer, boolean b) {
		super(pointer,b);
	}

	/**
	 * Returns the value of the specified number as a <code>byte</code>. This
	 * may involve rounding or truncation.
	 * 
	 * @return the numeric value represented by this object after conversion to
	 *         type <code>byte</code>.
	 */
	public byte byteValue() {
		return (byte) intValue();
	}

	/**
	 * Returns the value of the specified number as a <code>double</code>.
	 * This may involve rounding.
	 * 
	 * @return the numeric value represented by this object after conversion to
	 *         type <code>double</code>.
	 */
	public abstract double doubleValue();

	/**
	 * Returns the value of the specified number as a <code>float</code>.
	 * This may involve rounding.
	 * 
	 * @return the numeric value represented by this object after conversion to
	 *         type <code>float</code>.
	 */
	public abstract float floatValue();

	/**
	 * @return The value of the native number.
	 */
	public abstract T get();

	/**
	 * Returns the value of the specified number as an <code>int</code>. This
	 * may involve rounding or truncation.
	 * 
	 * @return the numeric value represented by this object after conversion to
	 *         type <code>int</code>.
	 */
	public abstract int intValue();

	/**
	 * Returns the value of the specified number as a <code>long</code>. This
	 * may involve rounding or truncation.
	 * 
	 * @return the numeric value represented by this object after conversion to
	 *         type <code>long</code>.
	 */
	public abstract long longValue();

	/**
	 * Sets the value of the native number
	 * 
	 * @param value
	 *            the value to set.
	 */
	public abstract void set(T value);

	/**
	 * Returns the value of the specified number as a <code>short</code>.
	 * This may involve rounding or truncation.
	 * 
	 * @return the numeric value represented by this object after conversion to
	 *         type <code>short</code>.
	 */
	public short shortValue() {
		return (short) intValue();
	}
	
	/**
	 * @return The pointer to the next number in memory. 
	 */
	public abstract NumberPointer next();
}
