/**
 * 
 */
package org.xbig.test.t8_3;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.B;
import org.xbig.base.*;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useMethodsWithManyConst() {
		IntegerPointer iPtr;
		FloatPointer fPtr = new FloatPointer(7.3f);
		int i;
		float f = fPtr.floatValue();

		A a = new A();

		i = a.a(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		i = a.b(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		i = a.c(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		i = a.a_const(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		iPtr = a.d(fPtr.floatValue());
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.e(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.g(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.e_const(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());

		// these overloaded methods are not generated
		i = a.a(final fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		i = a.b(final fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		i = a.c(final fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		i = a.a_const(final fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		iPtr = a.e(final fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.g(final fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.e_const(final fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());

		iPtr = a.h(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.g_const(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.i(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());

		a.delete();


		B b = new B();

		iPtr = b.a(f);
		Assert.assertEquals((int)f, iPtr.intValue());
		iPtr = b.c(f);
		Assert.assertEquals((int)f, iPtr.intValue());
		iPtr = b.a_const(f);
		Assert.assertEquals((int)f, iPtr.intValue());

		b.delete();

		fPtr.delete();
	}
}