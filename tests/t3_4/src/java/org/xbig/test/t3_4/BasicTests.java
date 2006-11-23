/**
 * 
 */
package org.xbig.test.t3_4;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.B;
/**
 * @author bielig
 *
 */
public class BasicTests {

	B a;

	@Before
	public void setUp() {
		a = new B();
	}

	@After
	public void tearDown() {
		a.delete();
	}

	@Test
	public void callStructMethodsWithReferences() {
		int b = a.a((float)7.3);
		Assert.assertEquals(7, b);
		b = a.b((float)7.3);
		Assert.assertEquals(7, b);
		b = a.c((float)7.3);
		Assert.assertEquals(7, b);
	}

	@Test
	public void accessStructReferenceAttribute() {
		a.setz(7.3);
		int b = a.getz();
		Assert.assertEquals(7, b);
	}
}
