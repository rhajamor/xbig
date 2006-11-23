/**
 * 
 */
package org.xbig.test.t3_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.B;
import org.xbig.C;
/**
 * @author bielig
 *
 */
public class BasicTests {
	
	@Test
	public void createStructWithDefaultConstructor() {
		B a = new B();
		a.delete();
	}

	@Test
	public void createStructWithExplicitConstructor() {
		C a = new C();
		a.delete();
	}
}
