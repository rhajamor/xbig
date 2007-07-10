/**
 * 
 */
package org.xbig.test.t5_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.n.A;
import org.xbig.n.IA;
import org.xbig.B;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useSubClass() {
		int i;
		float f = 4.8f;

		IA a = new A();
		i = a.a(f);
		Assert.assertEquals((int)f, i);

        final double attributeValue = 0.3;
        a.setattribute(attributeValue);
        Assert.assertEquals(attributeValue, a.getattribute());

		((A)a).delete();

		B b = new B();
		i = 2;
		f = b.c(i);
		Assert.assertEquals(i, (int)f);

		i = 0;
		f = 4.8f;
		i = b.a(f);
		Assert.assertEquals((int)f, i);

		a = b;
		i = a.a(f);
		Assert.assertEquals((int)f, i);

		i = 5;
		b.set(i);
		Assert.assertEquals(i, a.get());

        b.setattribute(attributeValue);
        Assert.assertEquals(attributeValue, b.getattribute());

		b.delete();
	}
}
