/**
 * 
 */
package org.xbig.test.t38;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.ConfigFile;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        ConfigFile cf = new ConfigFile();
        cf.delete();
	}
}
