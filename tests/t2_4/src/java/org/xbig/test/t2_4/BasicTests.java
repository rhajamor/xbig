/**
 * 
 */
package org.xbig.test.t2_4;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.base.*;

/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void callMethodsWithReferences() {
		A a = new A();
		IntegerPointer iPtr;
		FloatPointer fPtr = new FloatPointer(7.3f);

		int b = a.a(fPtr);
		Assert.assertEquals(fPtr.intValue(), b);

		iPtr = a.b(fPtr.floatValue());
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());

		iPtr = a.c(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());

		fPtr.delete();
		a.delete();
	}
}
