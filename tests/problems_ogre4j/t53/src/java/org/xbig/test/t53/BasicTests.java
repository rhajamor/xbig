/**
 * 
 */
package org.xbig.test.t53;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.ISharedPtr;
import org.xbig.Ogre.ResourcePtr;
import org.xbig.Ogre.TexturePtr;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
        TexturePtr tp = new TexturePtr();
        ResourcePtr rp = new ResourcePtr();
        ISharedPtr sp = null;

        sp = tp;
        sp = rp;

        rp.delete();
        tp.delete();
    }
}
