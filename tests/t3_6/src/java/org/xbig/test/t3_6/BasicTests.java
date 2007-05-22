/**
 * 
 */
package org.xbig.test.t3_6;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void useOuterClass() {
		A a = new A();
		A.B ab = new A.B();
		int b = a.a((float)7.3);
		Assert.assertEquals(7, b);
		Assert.assertEquals(a.b(ab), 10);
		a.delete();
		ab.delete();
	}

	@Test
	public void useInnerStruct() {
		A.B a = new A.B();
		a.setz(7.3);
		double b = a.getz();
		Assert.assertEquals(7.3, b);
		float c = a.x(7);
		Assert.assertEquals(7.0f, c);
		a.delete();
	}
}
