/**
 * 
 */
package org.xbig.test.t06;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.TextureUnitState;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		TextureUnitState.TextureEffect te = new TextureUnitState.TextureEffect();
		te.getcontroller();
		te.delete();
	}
}
