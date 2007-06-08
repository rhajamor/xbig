/**
 * 
 */
package org.xbig.test.t56;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.TextureUnitState;
import org.xbig.Ogre.ShadowVolumeExtrudeProgram;
import org.xbig.Ogre.IFrustum;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
        TextureUnitState tus = new TextureUnitState();

        IFrustum f = tus.getfrustum();
        ShadowVolumeExtrudeProgram.getprogramNames();

        tus.delete();
    }
}
