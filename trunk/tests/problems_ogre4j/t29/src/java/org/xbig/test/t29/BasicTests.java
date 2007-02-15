/**
 * 
 */
package org.xbig.test.t29;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.CompositorChain;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		CompositorChain.Instances is = new CompositorChain.Instances();
		CompositorChain.InstanceIterator ii = new CompositorChain.InstanceIterator();
		ii.delete();
		is.delete();
	}
}
