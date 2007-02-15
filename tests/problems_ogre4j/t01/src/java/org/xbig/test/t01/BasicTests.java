/**
 * 
 */
package org.xbig.test.t01;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.MoveableObject;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		MoveableObject mo = new MoveableObject();
		mo.getAnimableValueNames();
		mo.delete();
	}
}
