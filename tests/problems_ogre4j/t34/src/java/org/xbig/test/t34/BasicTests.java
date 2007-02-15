/**
 * 
 */
package org.xbig.test.t34;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.VoidPointer;
import org.xbig.SceneQuery;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		VoidPointer vp;
		SceneQuery.WorldFragment wf = new SceneQuery.WorldFragment();
		vp = wf.getgeometry();
		wf.setgeometry(vp);
		wf.delete();
	}
}
