/**
 * 
 */
package org.xbig.test.t8_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useMethodsWithConst() {
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

		a.delete();
	}
}
