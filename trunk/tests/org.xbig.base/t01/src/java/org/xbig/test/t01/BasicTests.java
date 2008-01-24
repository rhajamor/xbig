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
    public void getVoidPointer() {
        int bufferSize = 5;
        NativeBuffer buffer = new NativeBuffer(bufferSize);
        VoidPointer voidPointer = buffer.getVoidPointer();
        try {
            voidPointer.delete();
            Assert.fail();
        } catch (Exception e) {
            // OK
        }
        buffer.delete();
    }

    @Test
	public void readBuffer() {
	    int bufferSize = 5;
	    NativeBuffer buffer = new NativeBuffer(bufferSize);
	    A a = new A();

	    VoidPointer voidPointer = buffer.getVoidPointer();
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

    @Test
    public void writeBuffer() {
        int bufferSize = 5;
        byte value = 5;
        NativeBuffer buffer = new NativeBuffer(bufferSize);

        for (byte i=0; i<bufferSize; i++) {
            buffer.setIndex(i, i);
        }
        for (byte i=0; i<bufferSize; i++) {
            Assert.assertEquals(i, buffer.getIndex(i));
        }

        try {
            buffer.setIndex(bufferSize + 1, value);
            Assert.fail();
        } catch (IllegalArgumentException e) {
            // OK
        }
        try {
            buffer.setIndex(-1, value);
            Assert.fail();
        } catch (IllegalArgumentException e) {
            // OK
        }

        buffer.delete();

       try {
            buffer.setIndex(0, value);
            Assert.fail();
        } catch (IllegalStateException e) {
            // OK
        }
    }
}
