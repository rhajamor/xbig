/**
 * 
 */
package org.xbig.test.t44;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.Any;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        Any a = new Any();
        Assert.assertTrue(a.isEmpty());
        a.delete();
	}
}
