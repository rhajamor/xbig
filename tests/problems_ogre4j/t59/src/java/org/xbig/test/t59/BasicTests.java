/**
 * 
 */
package org.xbig.test.t59;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.Vector3;
import org.xbig.Ogre.Quaternion;
import org.xbig.Ogre.TagPoint;
import org.xbig.Ogre.INode;
import org.xbig.Ogre.IBone;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
        TagPoint tp = new TagPoint();
        Vector3 vec = new Vector3();
        Quaternion quat = new Quaternion();
        INode node = null;
        IBone bone = null;
        String str = "Bulldozer Freny";
        int value = 4000;

        node = tp.createChild(str, vec, quat);
        node = tp.createChild(vec, quat);
        bone = tp.createChild(value, vec, quat);

        quat.delete();
        vec.delete();
        tp.delete();
    }
}
