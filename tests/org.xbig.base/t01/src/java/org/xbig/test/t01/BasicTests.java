/**
 * 
 */
package org.xbig.test.t01;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.NativeBuffer;
import org.xbig.base.VoidPointer;
import org.xbig.A;

/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test1() {
	    int bufferSize = 5;
	    NativeBuffer buffer = new NativeBuffer(bufferSize);
	    A a = new A();

	    VoidPointer voidPointer = new VoidPointer(buffer.getInstancePointer());
	    a.fillBuffer(voidPointer);
	    for (byte i=0; i<bufferSize; i++) {
	        Assert.assertEquals(i, buffer.getIndex(i));
	    }

	    try {
	        buffer.getIndex(bufferSize + 1);
	        Assert.fail();
	    } catch (IllegalArgumentException e) {
	        // OK
	    }
        try {
            buffer.getIndex(-1);
            Assert.fail();
        } catch (IllegalArgumentException e) {
            // OK
        }

	    a.delete();
	    buffer.delete();

       try {
            buffer.getIndex(0);
            Assert.fail();
        } catch (IllegalStateException e) {
            // OK
        }

	}
}
