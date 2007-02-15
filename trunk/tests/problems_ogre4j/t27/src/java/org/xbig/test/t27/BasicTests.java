/**
 * 
 */
package org.xbig.test.t27;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Bitwise;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		Bitwise b = new Bitwise();
		b.convertBitPattern();
		b.delete();
	}
}
