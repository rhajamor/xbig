/**
 * 
 */
package org.xbig.test.t65;

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
	public void testMapIterator() {
	    final String key1 = "one";
        final String key2 = "two";
        final String key3 = "three";
        final int value1 = 1;
        final int value2 = 2;
        final int value3 = 3;
        IA a1 = new A(value1);
        IA a2 = new A(value2);
        IA a3 = new A(value3);

        IAMap nativeMap = new AMap();
        nativeMap.insert(key1, a1);
        nativeMap.insert(key2, a2);
        nativeMap.insert(key3, a3);

        IAIterator it1 = new AIterator(nativeMap);
        String firstKeyReturned = it1.peekNextKey();
        it1.moveNext();
        String secondKeyReturned = it1.peekNextKey();
        Assert.assertFalse(firstKeyReturned.equals(secondKeyReturned));

        IAIterator it2 = new AIterator(nativeMap);
        Assert.assertEquals(firstKeyReturned, it2.peekNextKey());
        it2.operatorAssignment(it1);
        Assert.assertEquals(secondKeyReturned, it2.peekNextKey());

        it2.delete();
        it1.delete();
        a3.delete();
        a2.delete();
        a1.delete();
        nativeMap.delete();
    }

    @Test
    public void testSharedPtr() {
        final int value = 5;

        ICodecDataPtr cdPtr = new CodecDataPtr();
        ICodecData cd = new CodecData(value);

        cdPtr.bind(cd);
        Assert.assertEquals(value, cdPtr.get().getM());

        ICodecDataPtr cdPtr2 = new CodecDataPtr();
        cdPtr2.operatorAssignment(cdPtr);
        Assert.assertEquals(value, cdPtr.get().getM());

        cdPtr2.delete();
        cd.delete();
        cdPtr.delete();
    }

    @Test
    public void testException() {
        IException e1 = new FileNotFoundException();
        IException e2 = new IOException();

        e1.operatorAssignment(e2);

        e2.delete();
        e1.delete();
    }
}
