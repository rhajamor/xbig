/**
 * 
 */
package org.xbig.test.t40;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.Node;
import org.xbig.Ogre.ChildNodeMap;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        Node n = new Node();
        ChildNodeMap cnm = new ChildNodeMap();
        cnm.insert("key", n);
        Assert.assertFalse(cnm.empty());
        cnm.delete();
        n.delete();
	}
}
