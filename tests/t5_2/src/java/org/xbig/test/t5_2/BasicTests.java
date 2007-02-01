/**
 * 
 */
package org.xbig.test.t5_2;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.IA;
import org.xbig.B;
import org.xbig.IB;
import org.xbig.C;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useMultiSubClass() {
		int i;
		float f = 4.8f;

		IA a = new A();
		i = a.a(f);
		Assert.assertEquals((int)f, i);
		((A)a).delete();
		
		i = 5;
		IB b = new B();
		f = b.c(i);
		Assert.assertEquals(i, (int)f);
		((B)b).delete();

		long l = 3;
		double d;
		C c = new C();
		d = c.e(l);
		Assert.assertEquals(l, (long)d);

		a = c;
		b = c;

		c.delete();
	}
}
