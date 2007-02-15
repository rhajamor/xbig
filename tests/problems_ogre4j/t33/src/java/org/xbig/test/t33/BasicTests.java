/**
 * 
 */
package org.xbig.test.t33;

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
		RadixSort.ContainerIter ci = new RadixSort.ContainerIter();
		ci.delete();
		rs.delete();
	}
}
