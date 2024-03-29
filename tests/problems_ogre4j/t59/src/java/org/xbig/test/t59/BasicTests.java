/**
 * 
 */
package org.xbig.test.t59;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.*;
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
        IBone bone = new Bone();
        String str = "Bulldozer Freny";
        int value = 4000;

        try {
            tp.createChild(str, vec, quat);
        } catch (Exception e) {
            // OK, native method returns null
        }
        try {
            tp.createChild(vec, quat);
        } catch (Exception e) {
            // OK, native method returns null
        }
        try {
            tp.createChild(value, vec, quat);
        } catch (Exception e) {
            // OK, native method returns null
        }

        try {
            bone.createChild(str, vec, quat);
        } catch (Exception e) {
            // OK, native method returns null
        }
        try {
            bone.createChild(vec, quat);
        } catch (Exception e) {
            // OK, native method returns null
        }
        try {
            bone.createChild(value, vec, quat);
        } catch (Exception e) {
            // OK, native method returns null
        }

        bone.delete();
        quat.delete();
        vec.delete();
        tp.delete();
    }

	@Test
	public void testRunOverloadedAndOverriddenMethod() {
	    ISceneQueryListener sql = new SceneQueryListener();
	    IAxisAlignedBoxSceneQuery aabsq = new ConcreteAxisAlignedBoxSceneQuery();

	    aabsq.execute(sql);

	    aabsq.delete();
	    sql.delete();
	}
}
