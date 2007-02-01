/**
 * 
 */
package org.xbig.test.t12_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.NativeObjectPointer;
import org.xbig.ns1.A;

/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test1() {
	   A a = new A();       
       NativeObjectPointer<A> aa = a.getPointerPointer();
       
       A b = new A();
       aa.getObject(b);
       
       a.delete();
       b.delete();
	}
}
