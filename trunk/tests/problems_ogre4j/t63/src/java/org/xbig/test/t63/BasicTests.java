/**
 * 
 */
package org.xbig.test.t63;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.IConcreteAxisAlignedBoxSceneQuery;
import org.xbig.Ogre.ConcreteAxisAlignedBoxSceneQuery;
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
        ConcreteAxisAlignedBoxSceneQuery daabq = new ConcreteAxisAlignedBoxSceneQuery(sm);

        daabq.delete();
        sm.delete();
    }
}
