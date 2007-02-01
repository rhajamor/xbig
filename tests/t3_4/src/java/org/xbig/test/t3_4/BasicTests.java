/**
 * 
 */
package org.xbig.test.t3_4;

import org.junit.Assert;
import org.junit.Before;
import org.junit.After;
import org.junit.Test;
import org.xbig.B;
import org.xbig.base.*;
/**
 * @author nenning
 *
 */
public class BasicTests {

	B a;

	@Before
	public void setUp() {
		a = new B();
	}

	@After
	public void tearDown() {
		a.delete();
	}

	@Test
	public void callStructMethodsWithReferences() {
		IntegerPointer iPtr;
		FloatPointer fPtr = new FloatPointer(7.3f);

		int b = a.a(fPtr);
		Assert.assertEquals(fPtr.intValue(), b);

		iPtr = a.b(fPtr.floatValue());
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());

		iPtr = a.c(fPtr);
		Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
		
		fPtr.delete();
	}

	@Test
	public void accessStructReferenceAttribute() {
		DoublePointer sPtr = new DoublePointer(7.3);

		a.setz(sPtr);
		DoublePointer gPtr = a.getz();
		Assert.assertEquals(sPtr.doubleValue(), gPtr.doubleValue());
		
		sPtr.delete();
	}
}
