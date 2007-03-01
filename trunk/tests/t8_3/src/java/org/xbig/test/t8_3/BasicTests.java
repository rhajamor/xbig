/**
 * 
 */
package org.xbig.test.t8_3;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.B;
import org.xbig.base.*;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useMethodsWithManyConst() {
		IntegerPointer iPtr;
		FloatPointer fPtr = new FloatPointer(7.3f);
		int i;
		float f = fPtr.floatValue();

		A a = new A();

        // const int a(float& b);
		i = a.a(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
        
        // int a(float& b) const;
        i = a.a_const(fPtr);
        Assert.assertEquals(fPtr.intValue(), i);
        
        // int const b(float& b);
		i = a.b(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
        
        // int c(const float& b);
		i = a.c(f);        
		Assert.assertEquals((int)f, i);
        
        // int& d(float const b);
		iPtr = a.d(f);
		Assert.assertEquals((int)f, iPtr.intValue());
        
        // const int& e(float& b);
		i = a.e(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
        
        // int& e(float& b) const;
        iPtr = a.e_const(fPtr);
        Assert.assertEquals(fPtr.intValue(), iPtr.intValue());
        
        // int& g(const float& b);
		iPtr = a.g(f);
		Assert.assertEquals((int)f, iPtr.intValue());
        
        // int& g(const float& b) const;
        iPtr = a.g_const(f);
        Assert.assertEquals((int)f, iPtr.intValue());
        
        // const int& h(float& b) const;
		i = a.h(fPtr);
		Assert.assertEquals(fPtr.intValue(), i);
		
        // const int& i(const float& b) const;
		i = a.i(f);
		Assert.assertEquals((int)f, i);

		a.delete();


		B b = new B();

        // const int& a(float b);
		i = b.a(f);
		Assert.assertEquals((int)f, i);
        
        // int& c(const float b);
		iPtr = b.c(f);
		Assert.assertEquals((int)f, iPtr.intValue());
        
        // int& a(float b) const;
		iPtr = b.a_const(f);
		Assert.assertEquals((int)f, iPtr.intValue());

		b.delete();

		fPtr.delete();
	}
}
