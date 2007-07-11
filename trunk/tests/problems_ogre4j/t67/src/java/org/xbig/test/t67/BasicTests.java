/**
 * 
 */
package org.xbig.test.t67;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.*;
import org.xbig.Ogre.*;
import org.xbig.std.*;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
	    IBufferUsageList bul = new BufferUsageList();

	    HardwareBuffer.Usage[] arr = new HardwareBuffer.Usage[3];
	    arr[0] = HardwareBuffer.Usage.HBU_STATIC;
	    arr[1] = HardwareBuffer.Usage.HBU_DYNAMIC;
	    arr[2] = HardwareBuffer.Usage.HBU_WRITE_ONLY;

	    bul.push_back(arr[0]);
	    bul.push_back(arr[1]);
	    bul.push_back(arr[2]);

	    for(int i=0; i<3; i++) {
	        HardwareBuffer.Usage returned = bul.at(i);
	        Assert.assertEquals(arr[i], returned);
	    }

	    bul.delete();
    }
}
