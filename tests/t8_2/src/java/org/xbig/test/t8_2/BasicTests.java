/**
 * 
 */
package org.xbig.test.t8_2;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useMethodsWithManyConst() {
		A a = new A();

		int i = 5;
		float f = 3.4f;

		i = a.a(f);
		Assert.assertEquals((int)f, i);
		i = a.b(f);
		Assert.assertEquals((int)f, i);
		i = a.c(f);
		Assert.assertEquals((int)f, i);
		i = a.d(f);
		Assert.assertEquals((int)f, i);
		i = a.a_const(f);
		Assert.assertEquals((int)f, i);
		i = a.b_const(f);
		Assert.assertEquals((int)f, i);
		i = a.c_const(f);
		Assert.assertEquals((int)f, i);
		i = a.d_const(f);
		Assert.assertEquals((int)f, i);
		i = a.e(f);
		Assert.assertEquals((int)f, i);
		i = a.f(f);
		Assert.assertEquals((int)f, i);
		i = a.g(f);
		Assert.assertEquals((int)f, i);
		i = a.h(f);
		Assert.assertEquals((int)f, i);
		i = a.i(f);
		Assert.assertEquals((int)f, i);

		a.delete();
	}
}
