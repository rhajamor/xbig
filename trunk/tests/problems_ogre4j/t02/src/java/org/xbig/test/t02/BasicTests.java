/**
 * 
 */
package org.xbig.test.t02;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Particle;
import org.xbig.Radian;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		Radian r = new Radian();
		Particle p = new Particle();
		p.setRotation(r);
		p.getRotation();
		p.setrotation(r);
		p.getrotation();
		p.delete();
		r.delete();
	}
}
