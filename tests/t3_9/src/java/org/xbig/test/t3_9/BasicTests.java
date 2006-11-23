/**
 * 
 */
package org.xbig.test.t3_9;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.n.B;
/**
 * @author bielig
 *
 */
public class BasicTests {
	
	@Test
	public void useStructFromInsideNamespace() {
		B a = new B();
		a.setz(7.3);
		int b = a.getz();
		Assert.assertEquals(7, b);
		float c = a.x(7);
		Assert.assertEquals(7, c);
		a.delete();
	}
}
