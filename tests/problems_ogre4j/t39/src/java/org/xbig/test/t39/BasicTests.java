/**
 * 
 */
package org.xbig.test.t39;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.GpuProgramParameters.AutoConstantEntry;
import org.xbig.Ogre.GpuProgramParameters.AutoConstantList;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        AutoConstantEntry ace = new AutoConstantEntry();
        AutoConstantList acl = new AutoConstantList();
        acl.push_back(ace);
        Assert.assertFalse(acl.empty());
        acl.delete();
        ace.delete();
	}
}
