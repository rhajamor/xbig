/**
 * 
 */
package org.xbig.test.t66;

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
	public void testMap() {
	    final String key1 = "one";
        final String key2 = "two";
        final String key3 = "three";
        IA a1 = new A();
        IA a2 = new A();
        IA a3 = new A();

        IMap nativeMap = new Map();
        nativeMap.insert(key1, a1);
        nativeMap.insert(key2, a2);
        nativeMap.insert(key3, a3);

        IA returned = nativeMap.get(key2);

        a3.delete();
        a2.delete();
        a1.delete();
        nativeMap.delete();
    }

    @Test
    public void testVector() {
        String s1 = "one";
        String s2 = "two";
        String s3 = "three";

        String[] strArr = new String[3];
        strArr[0] = s1;
        strArr[1] = s2;
        strArr[2] = s3;

        IVector nativeVector = new Vector();
        nativeVector.push_back(s1);
        nativeVector.push_back(s2);
        nativeVector.push_back(s3);

        for (int i=0; i<3; i++) {
            StringPointer returned = nativeVector.at(i);
            Assert.assertEquals(strArr[i], returned.get());
        }

        nativeVector.delete();
    }
}
