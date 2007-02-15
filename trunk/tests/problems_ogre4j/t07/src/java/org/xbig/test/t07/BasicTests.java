/**
 * 
 */
package org.xbig.test.t07;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.ProgressiveMesh;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		ProgressiveMesh.LODFaceList lfl = new ProgressiveMesh.LODFaceList();
		lfl.delete();
	}
}
