/**
 * 
 */
package org.xbig.test.t46;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.MovableObject;
import org.xbig.Ogre.RibbonTrail;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        MovableObject.Listener listener = new MovableObject.Listener();
        RibbonTrail rt = new RibbonTrail();
        rt.setListener(listener);
        Assert.assertEquals(listener.getInstancePointer(), rt.getListener().getInstancePointer());
        rt.delete();
        listener.delete();
	}
}
