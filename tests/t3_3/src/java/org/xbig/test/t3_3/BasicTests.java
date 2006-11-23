/**
 * 
 */
package org.xbig.test.t3_3;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.B;
/**
 * @author bielig
 *
 */
public class BasicTests {
	
	@Test
	public void callStructMethod() {
		B a = new B();
		float b = a.y(7);
		Assert.assertEquals(7, b);
		a.delete();
	}
}
