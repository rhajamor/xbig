/**
 * 
 */
package org.xbig.test.t23;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Vector;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		Vector v = new Vector();
		v.add(v);
		v.delete();
	}
}
