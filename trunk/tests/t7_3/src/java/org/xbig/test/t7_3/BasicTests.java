/**
 * 
 */
package org.xbig.test.t7_3;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.IA;
import org.xbig.C;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useStructTypedef() {
		IA a = new A();

		int i = 5;
		Assert.assertEquals(i, a.get5());

		C c = new C();
		Assert.assertEquals(i, c.a(a));

		a.delete();

		a = new A();
        c.getB(a);
		a.delete();

		c.delete();
	}
}
