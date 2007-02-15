/**
 * 
 */
package org.xbig.test.t05;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.RibbonTrail;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		RibbonTrail rt = new RibbonTrail();
		rt.delete();
	}
}
