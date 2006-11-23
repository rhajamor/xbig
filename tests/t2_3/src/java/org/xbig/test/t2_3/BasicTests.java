/**
 * 
 */
package org.xbig.test.t2_3;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
/**
 * @author bielig
 *
 */
public class BasicTests {
	
	@Test
	public void callMethod() {
		A a = new A();
		int b = a.a((float)7.3);
		Assert.assertEquals(7, b);
		a.delete();
	}
}
