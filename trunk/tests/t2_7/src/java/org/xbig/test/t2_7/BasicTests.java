/**
 * 
 */
package org.xbig.test.t2_7;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useStaticMembers() {
		int b = A.a((float)7.3);
		Assert.assertEquals(7, b);
		A.setb(b);
		Assert.assertEquals(b, A.getb());
	}
}
