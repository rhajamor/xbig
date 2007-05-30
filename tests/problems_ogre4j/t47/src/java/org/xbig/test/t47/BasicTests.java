/**
 * 
 */
package org.xbig.test.t47;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.A;
import org.xbig.Ogre.FloatVec;
import org.xbig.Ogre.StrVec;
import org.xbig.Ogre.StrStrVec;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        A a = new A();
        FloatVec fv = new FloatVec();
        StrVec sv = new StrVec();
        StrStrVec ssv = new StrStrVec();

        a.a(sv);
        a.a3(fv);
        a.b(ssv);
        a.c(fv);
        a.setmVec(sv);
        /*StrVec sv2 = a.getmVec();
        Assert.assertEquals(sv.getInstancePointer(), sv2.getInstancePointer());*/

        ssv.delete();
        sv.delete();
        fv.delete();
        a.delete();
	}
}
