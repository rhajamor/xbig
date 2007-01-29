/**
 * 
 */
package org.xbig.test.t7_4;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.IA;
import org.xbig.IB;
import org.xbig.IC;
import org.xbig.ID;
import org.xbig.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useTemplateTypedef() {
		Tester t = new Tester();

		ID d = t.b();
		IB b = d.a();
		Assert.assertEquals(3, b.get3());
		Assert.assertTrue(t.a(d));
		d.b(b);

		IC c = t.d();
		t.c(c);
		int i = c.a();
		c.b(i);

		t.delete();
	}
}
