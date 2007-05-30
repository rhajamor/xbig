/**
 * 
 */
package org.xbig.test.t17;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.StringPointer;
import org.xbig.TextureUnitState;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		//StringPointer sp = new StringPointer("");
		TextureUnitState tus = new TextureUnitState();
		tus.setCubicTextureName("", false);
		tus.delete();
		//sp.delete();
	}
}
