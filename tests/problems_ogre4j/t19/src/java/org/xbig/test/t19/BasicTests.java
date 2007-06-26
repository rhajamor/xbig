/**
 * 
 */
package org.xbig.test.t19;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Matrix3;
import org.xbig.IMatrix3;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		Matrix3 m = new Matrix3();

        m.Inverse(m, 0.0F);
        IMatrix3 tmp = new Matrix3();
        m.Inverse(tmp, 0.0F);
        tmp.delete();

        m.delete();
	}
}
