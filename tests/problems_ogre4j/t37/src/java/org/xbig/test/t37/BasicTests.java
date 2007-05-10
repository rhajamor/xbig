/**
 * 
 */
package org.xbig.test.t37;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.VoidPointer;
import org.xbig.Ogre.AlignedMemory;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        VoidPointer vPtr = AlignedMemory.allocate(5, 1);
        Assert.assertNotNull(vPtr);
        AlignedMemory.deallocate(vPtr);

//        AlignedMemory am = new AlignedMemory();
//        VoidPointer vPtr = am.allocate(5, 1);
//        Assert.assertNotNull(vPtr);
//        am.deallocate(vPtr);
//        am.delete();
	}
}
