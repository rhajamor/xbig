/**
 * 
 */
package org.xbig.test.t12_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.IntArray;
import org.xbig.base.AArray;
import org.xbig.ns1.A;

/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test1() {
	   A a = new A();       
       
       IntArray intArray = new IntArray(5);
       intArray.set(0,1);
       intArray.set(1,2);
       intArray.set(2,3);
       intArray.set(3,4);
       intArray.set(4,5);
       a.setIntArray(intArray);
       
       Assert.assertEquals(1, intArray.get(0));
       Assert.assertEquals(2, intArray.get(1));
       Assert.assertEquals(3, intArray.get(2));
       Assert.assertEquals(4, intArray.get(3));
       Assert.assertEquals(5, intArray.get(4));
       
       AArray aArray = new AArray(3);
       aArray.set(0,new A());
       aArray.set(1,new A());
       aArray.set(2,new A());
       aArray.set(3,new A());
       aArray.set(4,new A());
       a.setAArray(aArray);
       
       aArray.get(0).delete();
       aArray.get(1).delete();
       aArray.get(2).delete();
       aArray.get(3).delete();
       aArray.get(4).delete();

       aArray.delete();
       intArray.delete();
       a.delete();
	}
}
