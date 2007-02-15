/**
 * 
 */
package org.xbig.test.t20;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Math;
import org.xbig.Ray;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		Math m = new Math();
		Ray r = new Ray();
		//m.intersects(r, , false);
		//m.intersects(r, , false);
		r.delete();
		m.delete();
	}
}
