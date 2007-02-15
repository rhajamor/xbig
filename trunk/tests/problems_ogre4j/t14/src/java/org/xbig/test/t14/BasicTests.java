/**
 * 
 */
package org.xbig.test.t14;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.RenderSystem;
import org.xbig.RenderSystemList;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		RenderSystem rs = new RenderSystem();
		RenderSystemList rsl = new RenderSystemList();
		rsl.push_back(rs);
		rsl.at(0);
		rsl.delete();
		rs.delete();
	}
}
