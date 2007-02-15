/**
 * 
 */
package org.xbig.test.t26;

import org.junit.Assert;
import org.junit.Test;
import org.xbig._ConfigOption;
import org.xbig.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		_ConfigOption co = new _ConfigOption();
		Tester t = new Tester();
		t.a(co);
		t.delete();
		co.delete();
	}
}
