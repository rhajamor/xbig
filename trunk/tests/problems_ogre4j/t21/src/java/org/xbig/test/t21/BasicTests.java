/**
 * 
 */
package org.xbig.test.t21;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.StringPointer;
import org.xbig.ResourceGroupManager;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		StringPointer sp = new StringPointer("");
		ResourceGroupManager rgm = new ResourceGroupManager();
		resourceExists(, sp);
		rgm.delete();
		sp.delete();
	}
}
