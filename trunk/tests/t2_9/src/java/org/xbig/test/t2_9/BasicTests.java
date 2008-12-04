/**
 * 
 */
package org.xbig.test.t2_9;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.B;
import org.xbig.base.ULongLong;
import org.xbig.IWideString;
import org.xbig.WideString;
import org.xbig.base.WideStringPointer;

/**
 * @author nenning
 * 
 */
public class BasicTests {
	
    @Test
    public void callMethodWithSameNameDifferentParameters() {
        B b = new B();
        
		short charValue = 127;
        byte  signedCharValue = -128;
        short shortValue = 22513;
        int intValue = 2147483647;
        long longValue = 1000000000L;
        long longLongValue = -9223372036854775808L;
        Assert.assertEquals((b.getSigned(charValue)==charValue), true);
        Assert.assertEquals((b.getSigned(signedCharValue)==signedCharValue), true);        
        Assert.assertEquals((b.getSigned__hv(shortValue)==shortValue), true);
        Assert.assertEquals((b.getSigned(intValue)==intValue), true);
        Assert.assertEquals((b.getSigned(longValue)==longValue), true);
        Assert.assertEquals((b.getSigned__ov(longLongValue)==longLongValue), true);

        short unsignedCharValue = 234;
        int unsignedShortValue = 50000;
        long unsignedIntValue = 4294967295L;
        long unsignedLongValue = 3000000000L;
        ULongLong unsignedLongLongValue = new ULongLong("18446744073709551615");
        Assert.assertEquals(b.getUnsigned(unsignedCharValue).equals(new ULongLong(String.valueOf(unsignedCharValue))), true);
        Assert.assertEquals(b.getUnsigned(unsignedShortValue).equals(new ULongLong(String.valueOf(unsignedShortValue))), true);
        Assert.assertEquals(b.getUnsigned(unsignedIntValue).equals(new ULongLong(String.valueOf(unsignedIntValue))), true);
        Assert.assertEquals(b.getUnsigned__Lv(unsignedLongValue).equals(new ULongLong(String.valueOf(unsignedLongValue))), true);
        Assert.assertEquals(b.getUnsigned(unsignedLongLongValue).equals(unsignedLongLongValue), true);

        b.delete();
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
	public void unicode() {
		// german characters in html: &auml; &ouml; &uuml;
		String javaString = "ä ö ü";

		IWideString ws = new WideString();

		Assert.assertEquals(javaString, ws.c(javaString));

		ws.delete();
	}

}
