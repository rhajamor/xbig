/**
 * 
 */
package org.xbig.test.t35;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.NativeObjectPointer;
import org.xbig.base.InstancePointer;
import org.xbig.Ogre.Animation;
import org.xbig.Ogre.DefaultSceneManager;
import org.xbig.Ogre.IAnimation;
import org.xbig.Ogre.IDefaultSceneManager;
import org.xbig.Ogre.IMapIterator;
import org.xbig.Ogre.ISceneManager;
import org.xbig.Ogre.ISceneManager.IAnimationIterator;
import org.xbig.Ogre.SceneManager.AnimationIterator;
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

//        IAnimationIterator ai = new AnimationIterator(new InstancePointer(-1));
//        ai.setInstancePointer(-1, false);
//        ((AnimationIterator)ai).object.pointer = 0;

        IAnimationIterator ai = new AnimationIterator();

        ((DefaultSceneManager)sm).getAnimationIterator(ai);
        Assert.assertFalse(ai.hasMoreElements());
        ai.delete();

        sm.delete();
    }
}
