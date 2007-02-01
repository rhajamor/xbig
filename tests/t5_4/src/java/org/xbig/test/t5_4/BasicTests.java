/**
 * 
 */
package org.xbig.test.t5_4;

import org.junit.Test;
import org.xbig.IA;
import org.xbig.IB;
import org.xbig.IC;
import org.xbig.C;
import org.xbig.ID;
import org.xbig.D;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useSubClassOfDiamondTree() {
		IA a = new C();
		a.abstractA();
		a.notAbstract();
		((C)a).delete();

		IB b = new D();
		b.abstractB();
		b.notAbstract();

		a = b;
		IC c = (IC)b;

		D d = (D)b;
		d.abstractA();
		d.notAbstract();
		d.abstractB();

		d.delete();
	}
}
