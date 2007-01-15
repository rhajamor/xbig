/**
 * 
 */
package org.xbig.test.t9_3;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.B;
import org.xbig.Tester;
import org.xbig.Vocals;
import org.xbig._Constants;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useInnerEnums() {
		Tester t = new Tester();

		Assert.assertTrue(t.isN(_Constants.Vocals.a));
		Assert.assertTrue(t.isA(_Constants.Vocals.e));
		Assert.assertTrue(t.isB(_Constants.Vocals.i));

		Assert.assertFalse(t.isN(_Constants.Vocals.a));
		Assert.assertFalse(t.isA(_Constants.Vocals.e));
		Assert.assertFalse(t.isB(_Constants.Vocals.i));

		t.delete();

		Vocals v = new Vocals();
		v.delete();
	}
}
