/**
 * 
 */
package org.xbig.test.t8_4;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.IA;
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

		IA a = new A();

		i = a.a(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		i = a.b(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		i = a.c(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		iPtr = a.a(f);
		Assert.assertEquals((int)f, iPtr.intValue());
		iPtr = a.c(f);
		Assert.assertEquals((int)f, iPtr.intValue());
		iPtr = a.d(f);
		Assert.assertEquals((int)f, iPtr.intValue());
		iPtr = a.a_const(f);
		Assert.assertEquals((int)f, iPtr.intValue());
		iPtr = a.e(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.g(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.h(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.i(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.z(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.y(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.x(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.z_const(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.w(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.w_const(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());

		i = a.a_const(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		iPtr = a.e_const(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.g_const(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.x_const(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		iPtr = a.y_const(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());

		((A)a).delete();
		fPtr.delete();
	}
}
