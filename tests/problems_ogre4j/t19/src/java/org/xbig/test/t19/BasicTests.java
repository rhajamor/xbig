/**
 * 
 */
package org.xbig.test.t19;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Matrix3;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		Matrix3 m = new Matrix3();
		m.Inverse(m, 0.0F);
		m.Inverse(0.0F);
		m.delete();
	}
}
