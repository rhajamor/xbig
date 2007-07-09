/**
 * 
 */
package org.xbig.test.t64;

import org.junit.Assert;
import org.junit.Test;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
        org.xbig.ogre4j.IA a1 = new org.xbig.ogre4j.A();
        org.xbig.ogre4j.emittercommands.IA a2 = new org.xbig.ogre4j.emittercommands.A();
        org.xbig.ogre4j.overlayelementcommands.IA a3 = new org.xbig.ogre4j.overlayelementcommands.A();
        org.xbig.OverlayElementCommands.IA a4 = new org.xbig.OverlayElementCommands.A();
        org.xbig.OverlayElementCommands.EmitterCommands.IA a5 = new org.xbig.OverlayElementCommands.EmitterCommands.A();
        org.xbig.FOO.IA a6 = new org.xbig.FOO.A();
        org.xbig.ogre4j.Vocals1 v = org.xbig.ogre4j.Vocals1.u;

        Assert.assertEquals(a1.get1(), a2.a(a1));
        Assert.assertEquals(a1.get1(), a2.b(a1).get1());
        Assert.assertEquals(v, a2.c(v));

        a1.delete();
        a2.delete();
        a3.delete();
        a4.delete();
        a5.delete();
        a6.delete();
    }

    @Test
    public void inheritance() {
        org.xbig.ogre4j.IA a1 = new org.xbig.ogre4j.A();
        org.xbig.IB b1 = new org.xbig.B();
        org.xbig.FOO.IA a2 = new org.xbig.FOO.A();
        org.xbig.ogre4j.IB b2 = new org.xbig.ogre4j.B();
        org.xbig.ogre4j.IC c1 = new org.xbig.ogre4j.C();

        Assert.assertEquals(a1.get1(), b1.get1());
        Assert.assertEquals(a1.get1(), c1.get1());

        a1.delete();
        a2.delete();
        a1 = b1;
        a2 = b2;
        a1.delete();
        a2.delete();
        a1 = c1;
        a1.delete();
    }
}
