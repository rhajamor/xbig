/**
 * 
 */
package org.xbig.test.t4_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.n.A;
/**
 * @author bielig
 *
 */
public class BasicTests {
	
	@Test
	public void print() {
		A a = new A();
	   int b = a.a((float)7.3);
	   Assert.assertEquals(7, b);
	   a.delete();
	}
}
