/**
 * 
 */
package org.xbig.test.t36;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.*;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        AxisAlignedBoxSceneQuery aabsq = new AxisAlignedBoxSceneQuery();
        AxisAlignedBox aab = new AxisAlignedBox();
        aabsq.setBox(aab);
        IRegionSceneQuery rsq = aabsq;
        ISceneQuery sq = aabsq;
        ISceneQueryListener sql = aabsq;
        aab.delete();
        aabsq.delete();
	}
}
