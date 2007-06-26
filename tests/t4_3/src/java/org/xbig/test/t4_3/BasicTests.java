/**
 * 
 */
package org.xbig.test.t4_3;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;


/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void resolveTypes() {
		org.xbig.A a = new org.xbig.A();
		org.xbig.n.A na = new org.xbig.n.A();
		org.xbig.n.m.A nma = new org.xbig.n.m.A();
		org.xbig.o.A oa = new org.xbig.o.A();
		org.xbig.o.p.A opa = new org.xbig.o.p.A();
		org.xbig.o.n.A ona = new org.xbig.o.n.A();
		org.xbig.o.p.q.A opqa = new org.xbig.o.p.q.A();

		Assert.assertEquals(5, a.get5());
		Assert.assertEquals(2, na.get2());
		Assert.assertEquals(1, nma.get1());
		Assert.assertEquals(4, oa.get4());
		Assert.assertEquals(3, opa.get3());
		Assert.assertEquals(6, ona.get6());
		Assert.assertEquals(7, opqa.get7());

		org.xbig.B b = new org.xbig.B();
		org.xbig.n.B nb = new org.xbig.n.B();
		org.xbig.n.m.B nmb = new org.xbig.n.m.B();
		org.xbig.o.B ob = new org.xbig.o.B();
		org.xbig.o.p.B opb = new org.xbig.o.p.B();
		org.xbig.o.n.B onb = new org.xbig.o.n.B();
		org.xbig.o.p.q.B opqb = new org.xbig.o.p.q.B();

		Assert.assertTrue(b.isG(a));
		Assert.assertTrue(b.isN(na));
		Assert.assertTrue(b.isM(nma));
		Assert.assertTrue(b.isO(oa));
		Assert.assertTrue(b.isP(opa));
		Assert.assertTrue(b.isQ(opqa));
		Assert.assertTrue(b.isON(ona));

		Assert.assertTrue(nb.isG(a));
		Assert.assertTrue(nb.isN(na));
		Assert.assertTrue(nb.isM(nma));
		Assert.assertTrue(nb.isO(oa));
		Assert.assertTrue(nb.isP(opa));
		Assert.assertTrue(nb.isQ(opqa));
		Assert.assertTrue(nb.isON(ona));

		Assert.assertTrue(nmb.isG(a));
		Assert.assertTrue(nmb.isN(na));
		Assert.assertTrue(nmb.isM(nma));
		Assert.assertTrue(nmb.isO(oa));
		Assert.assertTrue(nmb.isP(opa));
		Assert.assertTrue(nmb.isQ(opqa));
		Assert.assertTrue(nmb.isON(ona));

		Assert.assertTrue(ob.isG(a));
		Assert.assertTrue(ob.isN(na));
		Assert.assertTrue(ob.isM(nma));
		Assert.assertTrue(ob.isO(oa));
		Assert.assertTrue(ob.isP(opa));
		Assert.assertTrue(ob.isQ(opqa));
		Assert.assertTrue(ob.isON(ona));

		Assert.assertTrue(opb.isG(a));
		Assert.assertTrue(opb.isN(na));
		Assert.assertTrue(opb.isM(nma));
		Assert.assertTrue(opb.isO(oa));
		Assert.assertTrue(opb.isP(opa));
		Assert.assertTrue(opb.isQ(opqa));
		Assert.assertTrue(opb.isON(ona));

		Assert.assertTrue(onb.isG(a));
		Assert.assertTrue(onb.isN(na));
		Assert.assertTrue(onb.isM(nma));
		Assert.assertTrue(onb.isO(oa));
		Assert.assertTrue(onb.isP(opa));
		Assert.assertTrue(onb.isQ(opqa));
		Assert.assertTrue(onb.isON(ona));

		Assert.assertTrue(opqb.isG(a));
		Assert.assertTrue(opqb.isN(na));
		Assert.assertTrue(opqb.isM(nma));
		Assert.assertTrue(opqb.isO(oa));
		Assert.assertTrue(opqb.isP(opa));
		Assert.assertTrue(opqb.isQ(opqa));
		Assert.assertTrue(opqb.isON(ona));

		a.delete();
		na.delete();
		nma.delete();
		oa.delete();
		opa.delete();
		ona.delete();
		opqa.delete();

		b.delete();
		nb.delete();
		nmb.delete();
		ob.delete();
		opb.delete();
		onb.delete();
		opqb.delete();
	}

	@Test
	public void getObjectsFromNativeLib() {
		org.xbig.IA a = new org.xbig.A();
		org.xbig.n.IA na = new org.xbig.n.A();
		org.xbig.n.m.IA nma = new org.xbig.n.m.A();
		org.xbig.o.IA oa = new org.xbig.o.A();
		org.xbig.o.p.IA opa = new org.xbig.o.p.A();
		org.xbig.o.n.IA ona = new org.xbig.o.n.A();
		org.xbig.o.p.q.IA opqa = new org.xbig.o.p.q.A();

		org.xbig.C c = new org.xbig.C();
		org.xbig.n.C nc = new org.xbig.n.C();
		org.xbig.n.m.C nmc = new org.xbig.n.m.C();
		org.xbig.o.C oc = new org.xbig.o.C();
		org.xbig.o.p.C opc = new org.xbig.o.p.C();
		org.xbig.o.n.C onc = new org.xbig.o.n.C();
		org.xbig.o.p.q.C opqc = new org.xbig.o.p.q.C();

		c.getG(a);
		c.getN(na);
		c.getM(nma);
		c.getO(oa);
		c.getP(opa);
		c.getQ(opqa);
		c.getON(ona);

		Assert.assertEquals(5, a.get5());
		Assert.assertEquals(2, na.get2());
		Assert.assertEquals(1, nma.get1());
		Assert.assertEquals(4, oa.get4());
		Assert.assertEquals(3, opa.get3());
		Assert.assertEquals(6, ona.get6());
		Assert.assertEquals(7, opqa.get7());

//		a.delete();
//		na.delete();
//		nma.delete();
//		oa.delete();
//		opa.delete();
//		ona.delete();
//		opqa.delete();

		nc.getG(a);
		nc.getN(na);
		nc.getM(nma);
		nc.getO(oa);
		nc.getP(opa);
		nc.getQ(opqa);
		nc.getON(ona);

		Assert.assertEquals(5, a.get5());
		Assert.assertEquals(2, na.get2());
		Assert.assertEquals(1, nma.get1());
		Assert.assertEquals(4, oa.get4());
		Assert.assertEquals(3, opa.get3());
		Assert.assertEquals(6, ona.get6());
		Assert.assertEquals(7, opqa.get7());

//		a.delete();
//		na.delete();
//		nma.delete();
//		oa.delete();
//		opa.delete();
//		ona.delete();
//		opqa.delete();

		nmc.getG(a);
		nmc.getN(na);
		nmc.getM(nma);
		nmc.getO(oa);
		nmc.getP(opa);
		nmc.getQ(opqa);
		nmc.getON(ona);

		Assert.assertEquals(5, a.get5());
		Assert.assertEquals(2, na.get2());
		Assert.assertEquals(1, nma.get1());
		Assert.assertEquals(4, oa.get4());
		Assert.assertEquals(3, opa.get3());
		Assert.assertEquals(6, ona.get6());
		Assert.assertEquals(7, opqa.get7());

//		a.delete();
//		na.delete();
//		nma.delete();
//		oa.delete();
//		opa.delete();
//		ona.delete();
//		opqa.delete();

		oc.getG(a);
		oc.getN(na);
		oc.getM(nma);
		oc.getO(oa);
		oc.getP(opa);
		oc.getQ(opqa);
		oc.getON(ona);

		Assert.assertEquals(5, a.get5());
		Assert.assertEquals(2, na.get2());
		Assert.assertEquals(1, nma.get1());
		Assert.assertEquals(4, oa.get4());
		Assert.assertEquals(3, opa.get3());
		Assert.assertEquals(6, ona.get6());
		Assert.assertEquals(7, opqa.get7());

//		a.delete();
//		na.delete();
//		nma.delete();
//		oa.delete();
//		opa.delete();
//		ona.delete();
//		opqa.delete();

		opc.getG(a);
		opc.getN(na);
		opc.getM(nma);
		opc.getO(oa);
		opc.getP(opa);
		opc.getQ(opqa);
		opc.getON(ona);

		Assert.assertEquals(5, a.get5());
		Assert.assertEquals(2, na.get2());
		Assert.assertEquals(1, nma.get1());
		Assert.assertEquals(4, oa.get4());
		Assert.assertEquals(3, opa.get3());
		Assert.assertEquals(6, ona.get6());
		Assert.assertEquals(7, opqa.get7());

//		a.delete();
//		na.delete();
//		nma.delete();
//		oa.delete();
//		opa.delete();
//		ona.delete();
//		opqa.delete();

		opqc.getG(a);
		opqc.getN(na);
		opqc.getM(nma);
		opqc.getO(oa);
		opqc.getP(opa);
		opqc.getQ(opqa);
		opqc.getON(ona);

		Assert.assertEquals(5, a.get5());
		Assert.assertEquals(2, na.get2());
		Assert.assertEquals(1, nma.get1());
		Assert.assertEquals(4, oa.get4());
		Assert.assertEquals(3, opa.get3());
		Assert.assertEquals(6, ona.get6());
		Assert.assertEquals(7, opqa.get7());

//		a.delete();
//		na.delete();
//		nma.delete();
//		oa.delete();
//		opa.delete();
//		ona.delete();
//		opqa.delete();

		onc.getG(a);
		onc.getN(na);
		onc.getM(nma);
		onc.getO(oa);
		onc.getP(opa);
		onc.getQ(opqa);
		onc.getON(ona);

		Assert.assertEquals(5, a.get5());
		Assert.assertEquals(2, na.get2());
		Assert.assertEquals(1, nma.get1());
		Assert.assertEquals(4, oa.get4());
		Assert.assertEquals(3, opa.get3());
		Assert.assertEquals(6, ona.get6());
		Assert.assertEquals(7, opqa.get7());

		a.delete();
		na.delete();
		nma.delete();
		oa.delete();
		opa.delete();
		ona.delete();
		opqa.delete();

		c.delete();
		nc.delete();
		nmc.delete();
		oc.delete();
		opc.delete();
		onc.delete();
		opqc.delete();
	}
}
