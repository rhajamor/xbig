/**
 * 
 */
package org.xbig.test.t10_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.GlobalUtility;

/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void print() {
		int intValue=12345;
		Assert.assertEquals(GlobalUtility.a(intValue), intValue);
	}
}
