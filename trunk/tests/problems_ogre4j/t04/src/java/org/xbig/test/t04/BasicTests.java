/**
 * 
 */
package org.xbig.test.t04;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.ManualObject;
import org.xbig.HardwareIndexBufferSharedPtr;
import org.xbig.VertexData;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		ManualObject mo = new ManualObject();
		HardwareIndexBufferSharedPtr hibsp = new HardwareIndexBufferSharedPtr();
		VertexData vd = new VertexData();

		ManualObject.ManualObjectSectionShadowRenderable mossr =
			new ManualObject.ManualObjectSectionShadowRenderable(mo, hibsp, vd, false, false);

		mossr.delete();
		vd.delete();
		hibsp.delete();
		mo.delete();
	}
}
