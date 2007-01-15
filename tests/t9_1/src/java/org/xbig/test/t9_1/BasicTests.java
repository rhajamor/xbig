/**
 * 
 */
package org.xbig.test.t9_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig._Constants;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useEnum() {
		A a = new A();

		Assert.assertTrue(a.isA(_Constants.Vocals.a));
		Assert.assertTrue(a.isE(_Constants.Vocals.e));
		Assert.assertTrue(a.isI(_Constants.Vocals.i));
		Assert.assertTrue(a.isO(_Constants.Vocals.o));
		Assert.assertTrue(a.isU(_Constants.Vocals.u));

		Assert.assertFalse(a.isU(_Constants.Vocals.a));

		a.delete();
	}
}
