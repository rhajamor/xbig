/**
 * 
 */
package org.xbig.test.t2_4;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
/**
 * @author bielig
 *
 */
public class BasicTests {
	
	@Test
	public void callMethodsWithReferences() {
		A a = new A();
		int b = a.a((float)7.3);
		Assert.assertEquals(7, b);
		b = a.b((float)7.3);
		Assert.assertEquals(7, b);
		b = a.c((float)7.3);
		Assert.assertEquals(7, b);
		a.delete();
	}
}
