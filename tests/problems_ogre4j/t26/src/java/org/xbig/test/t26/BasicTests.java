/**
 * 
 */
package org.xbig.test.t26;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.ConfigOption;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		ConfigOption co = new ConfigOption();
		co.delete();
	}
}
