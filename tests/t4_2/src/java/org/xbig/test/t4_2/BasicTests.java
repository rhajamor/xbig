/**
 * 
 */
package org.xbig.test.t4_2;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.n.m.A;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void createObjectFromInsideNestedNamespace() {
		A a = new A();
		int b = a.a((float)7.3);
		Assert.assertEquals(7, b);
		a.delete();
	}
}
