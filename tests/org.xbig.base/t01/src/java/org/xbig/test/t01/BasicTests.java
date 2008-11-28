/**
 * 
 */
package org.xbig.test.t01;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.NativeByteBuffer;
import org.xbig.base.NativeCharBuffer;
import org.xbig.base.NativeLongBuffer;
import org.xbig.base.NativeFloatBuffer;
import org.xbig.base.NativeIntBuffer;
import org.xbig.base.NativeDoubleBuffer;
import org.xbig.base.NativeShortBuffer;
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
        NativeByteBuffer buffer = new NativeByteBuffer(bufferSize);
        VoidPointer voidPointer = buffer.getVoidPointer();
        try {
            voidPointer.delete();
            Assert.fail();
        } catch (Exception e) {
            // OK
        }
        buffer.delete();
    }

	//------------------ByteBuffer----------------------------
    @Test
	public void readByteBuffer() {
	    int bufferSize = 5;
	    NativeByteBuffer buffer = new NativeByteBuffer(bufferSize);
	    A a = new A();

	    VoidPointer voidPointer = buffer.getVoidPointer();
	    a.fillByteBuffer(voidPointer);
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
    public void writeByteBuffer() {
        int bufferSize = 5;
        byte value = 5;
        NativeByteBuffer buffer = new NativeByteBuffer(bufferSize);

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
    //------------------CharBuffer----------------------------
    @Test
	public void readCharBuffer() {
	    int bufferSize = 5;
	    NativeCharBuffer buffer = new NativeCharBuffer(bufferSize);
	    A a = new A();

	    VoidPointer voidPointer = buffer.getVoidPointer();
	    a.fillCharBuffer(voidPointer);
	    for (char i=0; i<bufferSize; i++) {
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
    public void writeCharBuffer() {
        int bufferSize = 5;
        char value = 5;
        NativeCharBuffer buffer = new NativeCharBuffer(bufferSize);

        for (char i=0; i<bufferSize; i++) {
            buffer.setIndex(i, i);
        }
        for (char i=0; i<bufferSize; i++) {
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

    //------------------ShortBuffer----------------------------
    @Test
	public void readShortBuffer() {
	    int bufferSize = 5;
	    NativeShortBuffer buffer = new NativeShortBuffer(bufferSize);
	    A a = new A();

	    VoidPointer voidPointer = buffer.getVoidPointer();
	    a.fillShortBuffer(voidPointer);
	    for (short i=0; i<bufferSize; i++) {
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
    public void writeShortBuffer() {
        int bufferSize = 5;
        short value = 5;
        NativeShortBuffer buffer = new NativeShortBuffer(bufferSize);

        for (short i=0; i<bufferSize; i++) {
            buffer.setIndex(i, i);
        }
        for (short i=0; i<bufferSize; i++) {
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

    //------------------IntBuffer----------------------------
    @Test
	public void readIntBuffer() {
	    int bufferSize = 5;
	    NativeIntBuffer buffer = new NativeIntBuffer(bufferSize);
	    A a = new A();

	    VoidPointer voidPointer = buffer.getVoidPointer();
	    a.fillIntBuffer(voidPointer);
	    for (int i=0; i<bufferSize; i++) {
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
    public void writeIntBuffer() {
        int bufferSize = 5;
        int value = 5;
        NativeIntBuffer buffer = new NativeIntBuffer(bufferSize);

        for (int i=0; i<bufferSize; i++) {
            buffer.setIndex(i, i);
        }
        for (int i=0; i<bufferSize; i++) {
            Assert.assertEquals( i, buffer.getIndex(i));
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

    //------------------LongBuffer----------------------------
    @Test
	public void readLongBuffer() {
	    int bufferSize = 5;
	    NativeLongBuffer buffer = new NativeLongBuffer(bufferSize);
	    A a = new A();

	    VoidPointer voidPointer = buffer.getVoidPointer();
	    a.fillLongBuffer(voidPointer);
	    for (long i=0; i<bufferSize; i++) {
	        Assert.assertEquals(i, buffer.getIndex((int)i));
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
    public void writeLongBuffer() {
        int bufferSize = 5;
        long value = 5;
        NativeLongBuffer buffer = new NativeLongBuffer(bufferSize);

        for (long i=0; i<bufferSize; i++) {
            buffer.setIndex((int)i, i);
        }
        for (long i=0; i<bufferSize; i++) {
            Assert.assertEquals(i, buffer.getIndex((int)i));
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
    //------------------FloatBuffer----------------------------
    @Test
	public void readFloatBuffer() {
	    int bufferSize = 5;
	    NativeFloatBuffer buffer = new NativeFloatBuffer(bufferSize);
	    A a = new A();

	    VoidPointer voidPointer = buffer.getVoidPointer();
	    a.fillFloatBuffer(voidPointer);
	    for (float i=0; i<bufferSize; i++) {
	        Assert.assertEquals(i, buffer.getIndex((int)i));
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
    public void writeFloatBuffer() {
        int bufferSize = 5;
        float value = 5;
        NativeFloatBuffer buffer = new NativeFloatBuffer(bufferSize);

        for (float i=0; i<bufferSize; i++) {
            buffer.setIndex((int)i, i);
        }
        for (float i=0; i<bufferSize; i++) {
            Assert.assertEquals(i, buffer.getIndex((int)i));
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

    //------------------DoubleBuffer----------------------------
    @Test
	public void readDoubleBuffer() {
	    int bufferSize = 5;
	    NativeDoubleBuffer buffer = new NativeDoubleBuffer(bufferSize);
	    A a = new A();

	    VoidPointer voidPointer = buffer.getVoidPointer();
	    a.fillDoubleBuffer(voidPointer);
	    for (double i=0; i<bufferSize; i++) {
	        Assert.assertEquals(i, buffer.getIndex((int)i));
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
    public void writeDoubleBuffer() {
        int bufferSize = 5;
        double value = 5;
        NativeDoubleBuffer buffer = new NativeDoubleBuffer(bufferSize);

        for (double i=0; i<bufferSize; i++) {
            buffer.setIndex((int)i, i);
        }
        for (double i=0; i<bufferSize; i++) {
            Assert.assertEquals(i, buffer.getIndex((int)i));
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
