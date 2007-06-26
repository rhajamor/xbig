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
        Radian r2 = new Radian();
		p.getrotation(r2);
        r2.delete();
		p.delete();
		r.delete();
	}
}
