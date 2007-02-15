/**
 * 
 */
package org.xbig.test.t28;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.RadixSort;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		RadixSort rs = new RadixSort();
		rs.sort();
		rs.delete();
	}
}
