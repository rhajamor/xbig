/**
 * 
 */
package org.xbig.test.t3_8;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
/**
 * @author bielig
 *
 */
public class BasicTests {

	@Test
	public void useOuterStruct() {
		A a = new A();
		int b = a.a((float)7.3);
		Assert.assertEquals(7, b);
		a.delete();
	}

	@Test
	public void useInnerClass() {
		A.B a = new A.B();
		a.setz(7.3);
		double b = a.getz();
		Assert.assertEquals(7.3, b);
		float c = a.x(7);
		Assert.assertEquals(7.0f, c);
		a.delete();
	}
}
