/**
 * 
 */
package org.xbig.test.t16;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.OverlayManager;
import org.xbig.OverlayElement;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void print() {
		OverlayElement oe = new OverlayElement();
		OverlayManager om = new OverlayManager();
		om.destroyOverlayElement(oe, false);
		om.delete();
		oe.delete();
	}
}
