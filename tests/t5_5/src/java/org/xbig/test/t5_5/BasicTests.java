/**
 * 
 */
package org.xbig.test.t5_5;

import org.junit.Test;
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

		a.b();
		b.b();
		b.c();
		c.a();
		c.b();
		c.c();

		c.delete();
	}
}
