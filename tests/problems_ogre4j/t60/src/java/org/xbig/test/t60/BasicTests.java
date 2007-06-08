/**
 * 
 */
package org.xbig.test.t60;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.RibbonTrail;
import org.xbig.Ogre.IMovableObject;
import org.xbig.Ogre.MovableObject;
import org.xbig.Ogre.Light;
import org.xbig.Ogre.ILightList;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
        RibbonTrail rt = new RibbonTrail();

        IMovableObject mo = rt;
        ILightList ll = rt.queryLights();
        Assert.assertTrue(ll.empty());

        MovableObject.Listener l = new MovableObject.Listener();
        l.objectQueryLights(rt);
        l.delete();

        rt.delete();
    }
}
