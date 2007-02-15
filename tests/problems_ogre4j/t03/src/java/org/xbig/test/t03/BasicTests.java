/**
 * 
 */
package org.xbig.test.t03;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.CompositorInstance;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		CompositorInstance.TargetOperation.RenderQueueBitSet rqbs =
			new CompositorInstance.TargetOperation.RenderQueueBitSet();
		//System.out.println(rqbs.to_string());
		//Assert.fail();
		rqbs.delete();
	}
}
