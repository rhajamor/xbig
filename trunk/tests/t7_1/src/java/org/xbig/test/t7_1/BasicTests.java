/**
 * 
 */
package org.xbig.test.t7_1;

import org.junit.Test;
import org.junit.Assert;
import org.xbig.A;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void usePrimitiveTypedef() {
		A a = new A();

		int i = 5;
		Assert.assertEquals(i, a.a(i));

		a.delete();
	}
}
