/**
 * 
 */
package org.xbig.test.t5_6;

import org.junit.*;
import org.xbig.IA;
import org.xbig.IB;
import org.xbig.C;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useSubClassOfThreeLevelTree() {
		IA a = new C();
		IB b = (IB)a;
		C c = (C)a;

		Assert.assertEquals(2l,a.b());
        Assert.assertEquals(2l,b.b());
        Assert.assertEquals(3l,b.c());
        Assert.assertEquals(1,c.a());
        Assert.assertEquals(2l,c.b());
        Assert.assertEquals(3l,c.c());

		c.delete();
	}
}
