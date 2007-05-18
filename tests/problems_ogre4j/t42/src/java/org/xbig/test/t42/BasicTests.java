/**
 * 
 */
package org.xbig.test.t42;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.Bitwise;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        //Assert.assertFalse(Bitwise.mostSignificantBitSet(0));
        System.out.println(Bitwise.mostSignificantBitSet(0));
        System.out.println(Bitwise.firstPO2From(0));
	}
}
