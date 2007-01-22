/**
 * 
 */
package org.xbig.test.t7_6;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.C;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useStructTypedef() {
		C c = new C();

		Assert.assertTrue(c.isN(1));
		Assert.assertTrue(c.isA(1));
		Assert.assertTrue(c.isB(1));

		c.delete();
	}
}
