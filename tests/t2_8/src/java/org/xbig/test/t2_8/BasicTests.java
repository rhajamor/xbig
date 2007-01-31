/**
 * 
 */
package org.xbig.test.t2_8;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.StringPointer;
import org.xbig.A;
import org.xbig.B;
import org.xbig.IB;
import org.xbig.S;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void useObjectPointersAndReferences() {
		A a = new A();
		B b = new B();
		IB b2;

		a.a(b);
		b2 = a.b();
		Assert.assertEquals(1, b2.get1());
		Assert.assertTrue(a.c(b));
		b2 = a.d();
		Assert.assertEquals(1, b2.get1());

		a.delete();
		b.delete();
	}

	@Test
	public void useStrings() {
		S s = new S();
		String javaString = "Bulldozer Frenzy";
		StringPointer sPtr = new StringPointer(javaString);

		// short test for StringPointer
		Assert.assertTrue(sPtr.equals(javaString));

		s.a(javaString);
		Assert.assertEquals(javaString, s.b());
		Assert.assertEquals(javaString, s.c(javaString));

		s.d(sPtr);
		Assert.assertEquals(sPtr.get(), s.e().get());
		Assert.assertEquals(sPtr.get(), s.f(sPtr).get());

		s.g(sPtr);
		Assert.assertEquals(sPtr.get(), s.h().get());
		Assert.assertEquals(sPtr.get(), s.i(sPtr).get());

		sPtr.delete();
		s.delete();
	}
}
