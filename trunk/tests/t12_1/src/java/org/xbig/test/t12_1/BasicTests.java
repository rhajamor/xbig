/**
 * 
 */
package org.xbig.test.t12_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.NativeObjectPointer;
import org.xbig.ns1.A;
import org.xbig.ns1.IA;
import org.xbig.ns1.ITester;
import org.xbig.ns1.Tester;

/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void usePointerPointer() {
		Tester t = new Tester();
		int i = 5;

		IA a = t.getPointer();
		a.setM(i);
		NativeObjectPointer<IA> aPtr = t.getPointerPointer();
		A b = new A();
		aPtr.getObject(b);
		Assert.assertEquals(i, a.getM());
		Assert.assertEquals(a.getM(), b.getM());

		IA a2 = new A();
		int i2 = 9;
		t.setValueOfPointer(a2, i2);
		Assert.assertEquals(i2, a2.getM());
		a2.delete();

		t.setValueOfPointerPointer(aPtr, i2);
		b = new A();
		aPtr.getObject(b);
		Assert.assertEquals(i2, b.getM());

		t.delete();
	}
}
