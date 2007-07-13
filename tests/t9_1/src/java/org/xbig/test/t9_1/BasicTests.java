/**
 * 
 */
package org.xbig.test.t9_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.Vocals;
import org.xbig.base.*;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useEnum() {
		A a = new A();

		Assert.assertTrue(a.isA(Vocals.a));
		Assert.assertTrue(a.isE(Vocals.e));
		Assert.assertTrue(a.isI(Vocals.i));
		Assert.assertTrue(a.isO(Vocals.o));
		Assert.assertTrue(a.isU(Vocals.u));

		Assert.assertFalse(a.isU(Vocals.a));

		a.delete();
	}

	@Test
    public void useEnumPointer() {
        A a = new A();

        EnumPointer<Vocals> enumPtr = new EnumPointer<Vocals>(Vocals.i);
        EnumPointer<Vocals> enumPtr2 = a.ptr(enumPtr);
        Assert.assertEquals(enumPtr.get(), enumPtr2.get());
        enumPtr2 = null;
        Assert.assertEquals(Vocals.u, enumPtr.get());
        enumPtr.set(Vocals.o);
        Assert.assertEquals(Vocals.o, enumPtr.get());
        enumPtr.delete();

        a.delete();
    }
}
