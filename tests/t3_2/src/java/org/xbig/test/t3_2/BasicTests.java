/**
 * 
 */
package org.xbig.test.t3_2;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.B;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void accessPublicStructAttribute() {
		B a = new B();
		a.setz(7.3);
		double b = a.getz();
		Assert.assertEquals(7.3, b);
		a.delete();
	}
}
