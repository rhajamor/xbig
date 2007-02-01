/**
 * 
 */
package org.xbig.test.t9_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.Vocals;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useEnum() {
		A a = new A();

		Assert.assertTrue(a.isA(Vocals.a));
		Assert.assertTrue(a.isE(Vocals.e));
		Assert.assertTrue(a.isI(Vocals.i));
		Assert.assertTrue(a.isO(Vocals.o));
		Assert.assertTrue(a.isU(Vocals.u));

		Assert.assertFalse(a.isU(Vocals.a));

		a.delete();
	}
}
