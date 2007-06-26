/**
 * 
 */
package org.xbig.test.t7_5;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.IA;
//import org.xbig.IB;
import org.xbig.IC;
import org.xbig.ID;
import org.xbig.IZ;
import org.xbig.Tester;
import org.xbig.A;
import org.xbig.C;
import org.xbig.D;
import org.xbig.Z;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useTypedefForStructTemplate() {
		Tester t = new Tester();

		ID d = new D();
        t.b(d);
		IA a = new A();
        d.a(a);
		Assert.assertEquals(3, a.get3());
		Assert.assertTrue(t.a(d));
		d.b(a);

		d.sety(a);
		IA a2 = new A();
        d.gety(a2);
		Assert.assertEquals(3, a2.get3());
		a2.delete();
		a.delete();
		d.delete();

		IC c = new C();
        t.d(c);
		t.c(c);
		int i = c.a();
		c.b(i);
		c.delete();

		t.delete();
	}

	@Test
	public void useInClassTemplateTypedef() {
		Tester t = new Tester();

		IA.IY y = new A.Y();
        t.z(y);
		IZ z = new Z();
        y.a(z);
		Assert.assertEquals(7, z.get7());
		Assert.assertTrue(t.x(y));
		y.b(z);

		y.sety(z);
		IZ z2 = new Z();
        y.gety(z2);
		Assert.assertEquals(7, z2.get7());
		z2.delete();
		z.delete();
		y.delete();

		t.delete();
	}
}
