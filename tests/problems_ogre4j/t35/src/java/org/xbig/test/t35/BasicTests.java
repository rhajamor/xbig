/**
 * 
 */
package org.xbig.test.t35;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.NativeObjectPointer;
import org.xbig.base.InstancePointer;
import org.xbig.base.WithoutNativeObject;
import org.xbig.Ogre.Animation;
import org.xbig.Ogre.ConcreteSceneManager;
import org.xbig.Ogre.IAnimation;
import org.xbig.Ogre.IConcreteSceneManager;
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
        ISceneManager sm = new ConcreteSceneManager();
        Assert.assertEquals(sm.getTypeName(), "Bulldozer");

//        IAnimationIterator ai = new AnimationIterator(new InstancePointer(-1));
//        ai.setInstancePointer(-1, false);
//        ((AnimationIterator)ai).object.pointer = 0;

        IAnimationIterator ai = new AnimationIterator(WithoutNativeObject.I_WILL_DELETE_THIS_OBJECT);

        ((ConcreteSceneManager)sm).getAnimationIterator(ai);
        Assert.assertFalse(ai.hasMoreElements());
        ai.delete();

        sm.delete();
    }
}
