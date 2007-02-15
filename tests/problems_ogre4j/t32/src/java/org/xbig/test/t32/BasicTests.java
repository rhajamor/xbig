/**
 * 
 */
package org.xbig.test.t32;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.ZZIP_FILE;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		ZZIP_FILE zf = new ZZIP_FILE();
		zf.delete();
	}
}
