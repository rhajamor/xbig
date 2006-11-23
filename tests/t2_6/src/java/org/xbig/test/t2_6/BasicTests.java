/**
 * 
 */
package org.xbig.test.t2_6;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
/**
 * @author bielig
 *
 */
public class BasicTests {
	
	@Test
	public void useOuterClass() {
		A a = new A();
		int b = a.a((float)7.3);
		Assert.assertEquals(7, b);
		a.delete();
	}

	@Test
	public void useInnerClass() {
		B a = new B();
		float b = a.x(7);
		Assert.assertEquals(7, b);
		a.delete();
	}
}
