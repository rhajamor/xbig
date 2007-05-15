/**
 * 
 */
package org.xbig.test.t11_1;

import org.junit.Assert;
import org.junit.Test;


/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void print() {
	   int a=1234;
	   int b=2345;
	   org.xbig.GlobalUtility.seta(a);
	   Assert.assertEquals(org.xbig.GlobalUtility.geta(), a);
	   org.xbig.GlobalUtility.setb(b);
	   Assert.assertEquals(org.xbig.GlobalUtility.getb(), b);

	   int l1a=3456;
	   int l1b=4567;
	   org.xbig.l1.GlobalUtility.seta(l1a);
	   Assert.assertEquals(org.xbig.l1.GlobalUtility.geta(), l1a);
	   org.xbig.l1.GlobalUtility.setb(l1b);
	   Assert.assertEquals(org.xbig.l1.GlobalUtility.getb(), l1b);

	   int l1l2a=5678;
	   int l1l2b=6789;
	   org.xbig.l1.l2.GlobalUtility.seta(l1l2a);
	   Assert.assertEquals(org.xbig.l1.l2.GlobalUtility.geta(), l1l2a);
	   org.xbig.l1.l2.GlobalUtility.setb(l1l2b);
	   Assert.assertEquals(org.xbig.l1.l2.GlobalUtility.getb(), l1l2b);
	   
	}
}
