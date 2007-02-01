/**
 * 
 */
package org.xbig.test.t1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.StringPointer;
import org.xbig.t1.t11.T1;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		int i = 4;
		long ui = 52544236L;
		String s = "Bulldozer Frenzy";
		StringPointer sPtr = new StringPointer(s);

		T1 t1 = new T1(i, ui, sPtr);

		Assert.assertEquals(i, t1.getInteger());
		Assert.assertEquals(ui, t1.getUnsignedInteger());
		Assert.assertEquals(s, t1.getString().get());

		t1.delete();
		sPtr.delete();
	}
}
