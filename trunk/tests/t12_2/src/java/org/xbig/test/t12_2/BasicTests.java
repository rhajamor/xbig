/**
 * 
 */
package org.xbig.test.t12_2;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.NativeObjectPointer;
import org.xbig.base.IntegerPointer;
import org.xbig.ns1.ITester;
import org.xbig.ns1.Tester;

/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void usePointerPointerForPrimitiveType() {
		Tester t = new Tester();
		int i = 5;

		IntegerPointer iPtr = t.getPointer();
		iPtr.set(i);
		NativeObjectPointer<IntegerPointer> iPtrPtr = t.getPointerPointer();
		IntegerPointer b = new IntegerPointer(0);
		iPtrPtr.getObject(b);
		Assert.assertEquals(i, iPtr.get());
		Assert.assertEquals(iPtr.get(), b.get());

		IntegerPointer iPtr2 = new IntegerPointer(0);
		int i2 = 9;
		t.setValueOfPointer(iPtr2, i2);
		Assert.assertEquals(i2, iPtr2.get());
		iPtr2.delete();

		t.setValueOfPointerPointer(iPtrPtr, i2);
		b = new IntegerPointer(0);
		iPtrPtr.getObject(b);
		Assert.assertEquals(i2, b.get());

		t.delete();
	}
}
