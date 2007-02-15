/**
 * 
 */
package org.xbig.test.t15;

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
		float[] af = new float[]{0.0f,0.0f,0.0f}
		float[] ak = new float[]{0.0f,0.0f,0.0f}
		m.EigenSolveSymmetric(af, ak);
		m.delete();
	}
}
