/**
 * 
 */
package org.xbig.test.t5_3;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.IA;
import org.xbig.B;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useSubClassOfAbstractBaseClass() {
		int i;
		float f = 4.8f;

		IA a = new B();
		i = a.a(f);
		Assert.assertEquals((int)f, i);
		
		B b = (B)a;
		f = b.c(i);
		Assert.assertEquals(i, (int)f);

		b.b();

		((B)b).delete();
	}
}
