/**
 * 
 */
package org.xbig.test.t12;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.ColourValue;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		ColourValue cv = new ColourValue(1.0f, 1.0f, 1.0f, 1.0f);
		cv.delete();
	}
}
