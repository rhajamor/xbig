/**
 * 
 */
package org.xbig.test.t61;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.IRibbonTrail;
import org.xbig.Ogre.RibbonTrail;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
        RibbonTrail rt = new RibbonTrail();

        // this method must exist
        rt.doNotIgnore();

        // make sure ignored method does not exist
        boolean foundMethod = false;
        try {
            RibbonTrail.class.getDeclaredMethod("objectDestroyed", int.class);
            foundMethod = true;
        } catch (NoSuchMethodException e) {
            // OK
        }
        if (foundMethod)
            Assert.fail();

        rt.delete();
    }
}
