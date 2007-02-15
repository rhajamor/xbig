/**
 * 
 */
package org.xbig.test.t25;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.RaySceneQueryResultEntry;
import org.xbig.SceneQuery;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		SceneQuery.WorldFragment wf = new SceneQuery.WorldFragment();
		RaySceneQueryResultEntry rsqre = new RaySceneQueryResultEntry();
		rsqre.setworldFragment(wf);
		rsqre.getworldFragment();
		rsqre.delete();
		wf.delete();
	}
}
