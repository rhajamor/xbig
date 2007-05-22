/**
 * 
 */
package org.xbig.test.t43;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.BillboardChain;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        BillboardChain bc = new BillboardChain("", 0, 0, false, false, false);
//        BillboardChain.Element e = new BillboardChain.Element();
//        bc.addChainElement(0, e);
        bc.setMaxChainElements(0);
        bc.delete();
	}
}
