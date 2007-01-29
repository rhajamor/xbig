/**
 * 
 */
package org.xbig.test.t7_5;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.IA;
import org.xbig.IB;
import org.xbig.IC;
import org.xbig.ID;
import org.xbig.IZ;
import org.xbig.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useTypedefForStructTemplate() {
		Tester t = new Tester();

		ID d = t.b();
		IA a = d.a();
		Assert.assertEquals(3, a.get3());
		Assert.assertTrue(t.a(d));
		d.b(a);

		d.sety(a);
		Assert.assertEquals(3, d.gety().get3());

		IC c = t.d();
		t.c(c);
		int i = c.a();
		c.b(i);

		t.delete();
	}

	@Test
	public void useInClassTemplateTypedef() {
		Tester t = new Tester();

		IA.IY y = t.z();
		IZ z = y.a();
		Assert.assertEquals(7, z.get7());
		Assert.assertTrue(t.x(y));
		y.b(z);

		y.sety(z);
		Assert.assertEquals(7, y.gety().get7());

		t.delete();
	}
}
