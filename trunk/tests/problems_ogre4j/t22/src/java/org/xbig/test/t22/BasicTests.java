/**
 * 
 */
package org.xbig.test.t22;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.RenderSystemA;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		RenderSystemA rsa = new RenderSystemA();
		rsa.getName();
		rsa.delete();
	}
}
