/**
 * 
 */
package org.xbig.test.t13;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.ISingleton;
import org.xbig.Root;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		Root root = new Root();
		Root.getSingletonPtr();
		Root.getSingleton();
		root.delete();
	}
}
