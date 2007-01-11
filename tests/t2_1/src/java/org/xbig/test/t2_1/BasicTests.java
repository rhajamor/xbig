/**
 * 
 */
package org.xbig.test.t2_1;

import org.junit.Test;
import org.xbig.A;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void createAndDeleteObject() {
		A a = new A();
		a.delete();
	}
}
