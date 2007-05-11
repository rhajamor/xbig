/**
 * 
 */
package org.xbig.test.t35;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.NativeObjectPointer;
import org.xbig.Ogre.Animation;
import org.xbig.Ogre.DefaultSceneManager;
import org.xbig.Ogre.IAnimation;
import org.xbig.Ogre.IDefaultSceneManager;
import org.xbig.Ogre.IMapIterator;
import org.xbig.Ogre.ISceneManager;
import org.xbig.Ogre.ISceneManager.IAnimationIterator;
import org.xbig.Ogre.SceneManager;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        ISceneManager sm = new DefaultSceneManager();
        Assert.assertEquals(sm.getTypeName(), "Bulldozer");

        IAnimationIterator ai = ((DefaultSceneManager)sm).getAnimationIterator();
        Assert.assertFalse(ai.hasMoreElements());

        //((DefaultSceneManager)sm).delete();
        sm.delete();
    }
}
