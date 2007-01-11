/**
 * 
 */
package org.xbig.test.t2_2;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void accessAttributes() {
		A a = new A();
		a.seta(5);
		int b = a.geta();
		Assert.assertEquals(5, b);
		a.delete();
	}
}
