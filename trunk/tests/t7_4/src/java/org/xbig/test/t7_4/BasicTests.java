/**
 * 
 */
package org.xbig.test.t7_4;

import org.junit.Assert;
import org.junit.Test;
//import org.xbig.IA;
import org.xbig.IB;
import org.xbig.IC;
import org.xbig.ID;
import org.xbig.Tester;
import org.xbig.B;
import org.xbig.C;
import org.xbig.D;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useTemplateTypedef() {
		Tester t = new Tester();
		int value = 5;

		// typedef for template with class
		ID d = new D();
        t.b(d);
		IB b = new B();
        d.a(b);
		b.set(value);
		Assert.assertEquals(3, b.get3());
		Assert.assertTrue(t.a(d));
		d.b(b);
		d.delete();

		// test if object returned by value is still valid
		Assert.assertEquals(value, b.get());
		b.delete();

		// typedef for template with primitive type
		IC c = new C();
        t.d(c);
		t.c(c);
		int i = c.a();
		c.b(i);
		c.delete();

		t.delete();
	}
}
