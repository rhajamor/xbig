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
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useInnerEnums() {
		Tester t = new Tester();

		Assert.assertTrue(t.isN(org.xbig.n.Vocals.a));
		Assert.assertTrue(t.isA(A.Vocals.e));
		Assert.assertTrue(t.isB(B.Vocals.i));
/*
		Assert.assertFalse(t.isN(A.Vocals.a));
		Assert.assertFalse(t.isA(B.Vocals.e));
		Assert.assertFalse(t.isB(org.xbig.n.Vocals.i));
*/
		t.delete();

		Vocals v = new Vocals();
		v.delete();
	}
}
