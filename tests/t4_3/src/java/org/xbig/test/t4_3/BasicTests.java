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
		org.xbig.IA a = null;
		org.xbig.n.IA na = null;
		org.xbig.n.m.IA nma = null;
		org.xbig.o.IA oa = null;
		org.xbig.o.p.IA opa = null;
		org.xbig.o.n.IA ona = null;
		org.xbig.o.p.q.IA opqa = null;

		org.xbig.C c = new org.xbig.C();
		org.xbig.n.C nc = new org.xbig.n.C();
		org.xbig.n.m.C nmc = new org.xbig.n.m.C();
		org.xbig.o.C oc = new org.xbig.o.C();
		org.xbig.o.p.C opc = new org.xbig.o.p.C();
		org.xbig.o.n.C onc = new org.xbig.o.n.C();
		org.xbig.o.p.q.C opqc = new org.xbig.o.p.q.C();

		a = c.getG();
		na = c.getN();
		nma = c.getM();
		oa = c.getO();
		opa = c.getP();
		opqa = c.getQ();
		ona = c.getON();

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

		a = nc.getG();
		na = nc.getN();
		nma = nc.getM();
		oa = nc.getO();
		opa = nc.getP();
		opqa = nc.getQ();
		ona = nc.getON();

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

		a = nmc.getG();
		na = nmc.getN();
		nma = nmc.getM();
		oa = nmc.getO();
		opa = nmc.getP();
		opqa = nmc.getQ();
		ona = nmc.getON();

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

		a = oc.getG();
		na = oc.getN();
		nma = oc.getM();
		oa = oc.getO();
		opa = oc.getP();
		opqa = oc.getQ();
		ona = oc.getON();

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

		a = opc.getG();
		na = opc.getN();
		nma = opc.getM();
		oa = opc.getO();
		opa = opc.getP();
		opqa = opc.getQ();
		ona = opc.getON();

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

		a = opqc.getG();
		na = opqc.getN();
		nma = opqc.getM();
		oa = opqc.getO();
		opa = opqc.getP();
		opqa = opqc.getQ();
		ona = opqc.getON();

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

		a = onc.getG();
		na = onc.getN();
		nma = onc.getM();
		oa = onc.getO();
		opa = onc.getP();
		opqa = onc.getQ();
		ona = onc.getON();

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
