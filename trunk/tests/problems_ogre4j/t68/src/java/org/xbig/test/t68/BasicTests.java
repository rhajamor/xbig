/**
 * 
 */
package org.xbig.test.t68;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.*;
import org.xbig.Ogre.*;
import org.xbig.std.*;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
	    IGpuProgramManager gpm = new GpuProgramManager();

	    IResourcePtr rp = new ResourcePtr(WithoutNativeObject.I_WILL_DELETE_THIS_OBJECT);
	    gpm.getByName(rp, new String(), false);
	    rp.delete();

	    rp = new ResourcePtr(WithoutNativeObject.I_WILL_DELETE_THIS_OBJECT);
        gpm.getByName(rp, new String());
        rp.delete();

	    gpm.delete();
    }
}
