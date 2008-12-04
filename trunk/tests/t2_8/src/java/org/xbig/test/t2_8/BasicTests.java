/**
 * 
 */
package org.xbig.test.t2_8;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.StringPointer;
import org.xbig.base.WideStringPointer;
import org.xbig.base.NativeByteBuffer;
import org.xbig.base.BytePointer;
import org.xbig.base.ShortPointer;
import org.xbig.A;
import org.xbig.B;
import org.xbig.IB;
import org.xbig.S;
import org.xbig.IWideString;
import org.xbig.WideString;
import org.xbig.ICharPtr;
import org.xbig.CharPtr;
import org.xbig.ICharPtr2;
import org.xbig.CharPtr2;

/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void useObjectPointersAndReferences() {
		A a = new A();
		B b = new B();
		b.seti(100);
		IB b2;

		a.a(b);
		b2 = a.b();
		Assert.assertEquals(1, b2.get1());
		Assert.assertTrue(a.c(b));
		b2 = a.d();
		Assert.assertEquals(1, b2.get1());

        final int value = 5;
        b.seti(value);
        a.f(b);

        // wether or not objects returned by value are passed as parameters
        IB result = new B();
        a.e(result);
        //IB result = a.e();

        Assert.assertEquals(value, result.geti());
        final int value2 = 7;
        b.seti(value2);
        a.f(b);

        // wether or not objects returned by value are passed as parameters
        //result.delete();
        a.g(result, b);
        //result = a.g(b);

        result.delete();

		a.delete();
		b.delete();

		final int value3 = 17;
		IB staticB = A.geth();
		staticB.seti(value3);
		Assert.assertEquals(value3, A.geth().geti());

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

	@Test
	public void useWideStrings() {
		IWideString s = new WideString();
		String javaString = "Wide String";
		WideStringPointer wsPtr = new WideStringPointer(javaString);

		// short test for WideStringPointer
		Assert.assertTrue(wsPtr.equals(javaString));

		s.a(javaString);
		Assert.assertEquals(javaString, s.b());
		Assert.assertEquals(javaString, s.c(javaString));

		s.d(wsPtr);
		Assert.assertEquals(wsPtr.get(), s.e().get());
		Assert.assertEquals(wsPtr.get(), s.f(wsPtr).get());

		s.g(wsPtr);
		Assert.assertEquals(wsPtr.get(), s.h().get());
		Assert.assertEquals(wsPtr.get(), s.i(wsPtr).get());

		wsPtr.delete();
		s.delete();
	}

	@Test
	public void useCharPtr() {
		ICharPtr s = new CharPtr();
		String javaString = "Bulldozer Frenzy";
		StringPointer sPtr = new StringPointer(javaString);

		s.a(javaString);
		Assert.assertEquals(javaString, s.b());
		Assert.assertEquals(javaString, s.c(javaString));

		sPtr.delete();
		s.delete();
	}

	@Test
	public void unicode() {
		// german characters in html: &auml; &ouml; &uuml;
		String javaString = "ä ö ü";

		S s = new S();
		IWideString ws = new WideString();
		ICharPtr cp = new CharPtr();

		Assert.assertEquals(javaString, s.c(javaString));
		Assert.assertEquals(javaString, ws.c(javaString));
		Assert.assertEquals(javaString, cp.c(javaString));

		s.delete();
		ws.delete();
		cp.delete();
	}

	@Test
	public void charInManyDifferentFlavours() {
		ICharPtr2 charPtr2 = new CharPtr2();

		String string = "foo";
		NativeByteBuffer pseudoCString = new NativeByteBuffer(3);
        pseudoCString.setIndex(0, (byte)65); // 65 is 'A' in ASCII
        pseudoCString.setIndex(1, (byte)66);
        pseudoCString.setIndex(2, (byte)0);
        BytePointer bytePtr = new BytePointer(pseudoCString.getInstancePointer()); // pseudo cast
		short shortValue = (short) 1000;
		ShortPointer shortPtr = new ShortPointer(shortValue);
		byte byteValue = (byte)127;

		Assert.assertEquals(string,     charPtr2.constCharPtr(string));
		Assert.assertEquals(bytePtr,    charPtr2.charPtr(bytePtr));
		Assert.assertEquals((byte)shortValue, (byte)charPtr2.charValue(shortValue));
		Assert.assertEquals((byte)shortValue, (byte)charPtr2.constCharValue(shortValue));
		Assert.assertEquals(bytePtr,    charPtr2.charRef(bytePtr));
		Assert.assertEquals((byte)shortValue, (byte)charPtr2.constCharRef(shortValue));
		Assert.assertEquals(shortPtr,   charPtr2.constCharPtrUnsigned(shortPtr));
		Assert.assertEquals(shortPtr,   charPtr2.charPtrUnsigned(shortPtr));
		Assert.assertEquals((byte)shortValue, (byte)charPtr2.charValueUnsigned(shortValue));
		Assert.assertEquals((byte)shortValue, (byte)charPtr2.constCharValueUnsigned(shortValue));
		Assert.assertEquals(shortPtr,   charPtr2.charRefUnsigned(shortPtr));
		Assert.assertEquals((byte)shortValue, (byte)charPtr2.constCharRefUnsigned(shortValue));
		Assert.assertEquals(bytePtr,    charPtr2.constCharPtrSigned(bytePtr));
		Assert.assertEquals(bytePtr,    charPtr2.charPtrSigned(bytePtr));
		Assert.assertEquals(byteValue,  charPtr2.charValueSigned(byteValue));
		Assert.assertEquals(byteValue,  charPtr2.constCharValueSigned(byteValue));
		Assert.assertEquals(bytePtr,    charPtr2.charRefSigned(bytePtr));
		Assert.assertEquals(byteValue,  charPtr2.constCharRefSigned(byteValue));

		pseudoCString.delete();
		shortPtr.delete();
		charPtr2.delete();
	}
}
