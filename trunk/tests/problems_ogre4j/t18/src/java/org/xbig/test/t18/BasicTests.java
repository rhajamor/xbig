/**
 * 
 */
package org.xbig.test.t18;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.FloatPointer;
import org.xbig.Vector2;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		FloatPointer fp = new FloatPointer(0.0F);
		Vector2 v1 = new Vector2(fp);
		Vector2 v2 = new Vector2(0.0F);
		v2.delete();
		v1.delete();
		fp.delete();
	}
}
