/**
 * 
 */
package org.xbig.test.t41;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.OverlayContainer;
import org.xbig.Ogre.OverlayContainerList;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        OverlayContainer oc = new OverlayContainer();
        OverlayContainerList ocl = new OverlayContainerList();
        ocl.push_back(oc);
        Assert.assertFalse(ocl.empty());
        ocl.delete();
        oc.delete();
	}
}
