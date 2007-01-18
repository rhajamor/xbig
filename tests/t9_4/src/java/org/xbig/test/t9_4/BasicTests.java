/**
 * 
 */
package org.xbig.test.t9_4;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.B;
import org.xbig.Tester;
import org.xbig.n.Tester;
import org.xbig.Vocals1;
import org.xbig._Constants;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useInnerEnumsWithDifferentNames() {
		Vocals1 v = new Vocals1();
		org.xbig.Tester t = new org.xbig.Tester();

		Assert.assertTrue(t.isN(_Constants.Vocals1.a));
		Assert.assertTrue(t.isA(_Constants.Vocals2.e));
		Assert.assertTrue(t.isB(_Constants.Vocals3.i));

		Assert.assertTrue(t.isObject(v));

		Assert.assertFalse(t.isN(_Constants.Vocals2.a));
		Assert.assertFalse(t.isA(_Constants.Vocals3.e));
		Assert.assertFalse(t.isB(_Constants.Vocals1.i));

		t.delete();

		org.xbig.n.Tester nt = new org.xbig.n.Tester();

		Assert.assertTrue(nt.isN(_Constants.Vocals1.a));
		Assert.assertTrue(nt.isA(_Constants.Vocals2.e));
		Assert.assertTrue(nt.isB(_Constants.Vocals3.i));

		Assert.assertTrue(nt.isObject(v));

		Assert.assertFalse(nt.isN(_Constants.Vocals2.a));
		Assert.assertFalse(nt.isA(_Constants.Vocals3.e));
		Assert.assertFalse(nt.isB(_Constants.Vocals1.i));

		nt.delete();

		v.delete();
	}
}
