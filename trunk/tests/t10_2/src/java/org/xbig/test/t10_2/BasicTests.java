/**
 * 
 */
package org.xbig.test.t10_2;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.*;
import org.xbig.GlobalUtility;
import org.xbig.A;
import org.xbig.IA;

/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void print() {
		int intValue=1234;
		GlobalUtility.a(intValue);
		Assert.assertEquals((GlobalUtility.a()==4000000), true);
		
		int unsignedValue=2345;
		GlobalUtility.b(unsignedValue);
		Assert.assertEquals((GlobalUtility.b()==4000000), true);
		
		int signedValue=3456;
		GlobalUtility.c(signedValue);
		Assert.assertEquals((GlobalUtility.c()==-4000000), true);
		
		int unsignedIntValue=4567;
		GlobalUtility.d(unsignedIntValue);
		Assert.assertEquals((GlobalUtility.d()==4000000), true);
		
		int signedIntValue=5678;
		GlobalUtility.e(signedIntValue);
		Assert.assertEquals((GlobalUtility.e()==-4000000), true);

		short shortValue=12;
		GlobalUtility.f(shortValue);
		Assert.assertEquals((GlobalUtility.f()==32000), true);
		
		int unsignedShortValue=23;
		GlobalUtility.g(unsignedShortValue);
		unsignedShortValue=GlobalUtility.g();
		Assert.assertEquals((GlobalUtility.g()==64000), true);
		
		short signedShortValue=34;
		GlobalUtility.h(signedShortValue);
		signedShortValue=GlobalUtility.h();
		Assert.assertEquals((GlobalUtility.h()==-32000), true);
		
		long longValue=1234567l;
		GlobalUtility.i(longValue);
		Assert.assertEquals((GlobalUtility.i()==5000000), true);
		
		long unsignedLongValue=2345678l;
		GlobalUtility.j(unsignedLongValue);
		Assert.assertEquals((GlobalUtility.j()==5000000), true);
		
		long signedLongValue=3456789l;
		GlobalUtility.k(signedLongValue);
		Assert.assertEquals((GlobalUtility.k()==-5000000), true);
		
		short charValue=45;
		GlobalUtility.l(charValue);
		Assert.assertEquals((GlobalUtility.l()==127), true);
		
		short unsignedCharValue=56;
		GlobalUtility.m(unsignedCharValue);
		Assert.assertEquals((GlobalUtility.m()==255), true);
		
		byte signedCharValue=67;
		GlobalUtility.n(signedCharValue);
		Assert.assertEquals((GlobalUtility.n()==-128), true);
		
		float floatValue=123.456f;
		org.xbig.l1.GlobalUtility.o(floatValue);
		Assert.assertEquals((org.xbig.l1.GlobalUtility.o()==7.3f), true);

		double doubleValue=12345.6789d;
		org.xbig.l1.l2.GlobalUtility.p(doubleValue);
		doubleValue=org.xbig.l1.l2.GlobalUtility.p();
		Assert.assertEquals((org.xbig.l1.l2.GlobalUtility.p()==8.261e-65), true);

		GlobalUtility.r();
		GlobalUtility.s();

		IA aValue=new A();
		GlobalUtility.t(aValue);
		aValue=GlobalUtility.t();
		aValue.delete();

		IntegerPointer intPointer;
		Assert.assertEquals(GlobalUtility.u().intValue(), 1);
	}
}
