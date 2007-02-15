/**
 * 
 */
package org.xbig.test.t24;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.SceneQuery;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void print() {
		SceneQuery.WorldFragment wf = new SceneQuery.WorldFragment();
		wf.setplanes( wf.getplanes() );
		wf.delete();
	}
}
