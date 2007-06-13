/**
 * 
 */
package org.xbig.test.t63;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.IDefaultAxisAlignedBoxSceneQuery;
import org.xbig.Ogre.DefaultAxisAlignedBoxSceneQuery;
import org.xbig.Ogre.ISceneManager;
import org.xbig.Ogre.SceneManager;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
        SceneManager sm = new SceneManager();
        DefaultAxisAlignedBoxSceneQuery daabq = new DefaultAxisAlignedBoxSceneQuery(sm);

        daabq.delete();
        sm.delete();
    }
}
