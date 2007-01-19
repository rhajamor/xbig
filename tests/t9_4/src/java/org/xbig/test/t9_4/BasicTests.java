/**
 * 
 */
package org.xbig.test.t9_4;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.B;
import org.xbig.Vocals1;
import org.xbig.n.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useInnerEnumsWithDifferentNames() {
		Vocals1 v = new Vocals1();
		org.xbig.Tester t = new org.xbig.Tester();

		Assert.assertTrue(t.isN(org.xbig.n.Vocals1.a));
		Assert.assertTrue(t.isA(A.Vocals2.e));
		Assert.assertTrue(t.isB(B.Vocals3.i));

		Assert.assertTrue(t.isObject(v));

		t.delete();

		org.xbig.n.Tester nt = new org.xbig.n.Tester();

		Assert.assertTrue(nt.isN(org.xbig.n.Vocals1.a));
		Assert.assertTrue(nt.isA(A.Vocals2.e));
		Assert.assertTrue(nt.isB(B.Vocals3.i));

		Assert.assertTrue(nt.isObject(v));

		nt.delete();

		v.delete();
	}

	@Test public void getEnums() {
		org.xbig.Returner r = new org.xbig.Returner();

		Assert.assertEquals(org.xbig.n.Vocals1.a, r.getN());
		Assert.assertEquals(A.Vocals2.a, r.getA());
		Assert.assertEquals(B.Vocals3.a, r.getB());

		Assert.assertEquals(5, r.getObject().get5());

		r.delete();

		org.xbig.n.Returner nr = new org.xbig.n.Returner();

		Assert.assertEquals(org.xbig.n.Vocals1.a, nr.getN());
		Assert.assertEquals(A.Vocals2.a, nr.getA());
		Assert.assertEquals(B.Vocals3.a, nr.getB());

		Assert.assertEquals(5, nr.getObject().get5());

		nr.delete();

		org.xbig.B.Returner br = new org.xbig.B.Returner();

		Assert.assertEquals(org.xbig.n.Vocals1.a, br.getN());
		Assert.assertEquals(A.Vocals2.a, br.getA());
		Assert.assertEquals(B.Vocals3.a, br.getB());

		Assert.assertEquals(5, br.getObject().get5());

		br.delete();
	}
}
