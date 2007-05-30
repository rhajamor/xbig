/**
 * 
 */
package org.xbig.test.t48;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.IMaterialSerializer;
import org.xbig.Ogre.MaterialSerializer;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        IMaterialSerializer.IEffectMap em = new MaterialSerializer.EffectMap();

        em.delete();
	}
}
