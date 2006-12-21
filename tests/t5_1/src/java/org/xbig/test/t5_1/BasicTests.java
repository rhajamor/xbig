/**
 * 
 */
package org.xbig.test.t5_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.B;
/**
 * @author bielig
 *
 */
public class BasicTests {
	
	@Test
	public void print() {
		int i;
		float f = 4.8f;

		A a = new A();
		i = a.a(f);
		Assert.assertEquals((int)f, i);
		a.delete();
		
		B b = new B();
		i = 2;
		f = b.c(i);
		Assert.assertEquals(i, (int)f);

		i = 0;
		f = 4.8f;
		i = b.a(f);
		Assert.assertEquals((int)f, i);

		a = b;
		i = a.a(f);
		Assert.assertEquals((int)f, i);

		i = 5;
		b.set(i);
		Assert.assertEquals(i, a.get());
		b.delete();
	}
}
