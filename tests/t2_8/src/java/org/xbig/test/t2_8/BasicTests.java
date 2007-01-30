/**
 * 
 */
package org.xbig.test.t2_8;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.B;
import org.xbig.IB;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useStaticMembers() {
		A a = new A();
		B b = new B();
		IB b2;

		a.a(b);
		b2 = a.b();
		Assert.assertEquals(1, b2.get1());
		Assert.assertTrue(a.c(b));
		b2 = a.d();
		Assert.assertEquals(1, b2.get1());

		a.delete();
		b.delete();
	}
}
