/**
 * 
 */
package org.xbig.test.t58;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.WaveformControllerFunction;
import org.xbig.Ogre.IControllerFunction;
import org.xbig.Ogre.WaveformType;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
        WaveformControllerFunction wcf = new WaveformControllerFunction(WaveformType.WFT_SINE, 0.0F, 1.0F, 0.0F, 1.0F, true, 0.5F);

        IControllerFunction cf = wcf;
        float value = 9.3F;
        Assert.assertEquals(value, wcf.calculate(value));

        wcf.delete();
    }
}
