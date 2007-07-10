/**
 * 
 */
package org.xbig.test.t55;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.NativeObjectPointer;
import org.xbig.base.ShortPointer;
import org.xbig.base.VoidPointer;
import org.xbig.Ogre.VertexElement;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
	    final short correctionValueForUnsigned = -256;
        VertexElement ve = new VertexElement();

        short value = (short)5;
        ve.setChar(value);
        NativeObjectPointer<ShortPointer> ptrPtr = ve.getPointerPointer();
        ShortPointer shortPtr = new ShortPointer((short)0);
        ptrPtr.getObject(shortPtr);
        System.out.println("shortPtr: " + shortPtr.get());
        Assert.assertEquals(value, (short)(shortPtr.get() + correctionValueForUnsigned));

        VoidPointer voidPtr = ve.getVoidPointer();
        Assert.assertEquals(voidPtr.getInstancePointer(), shortPtr.getInstancePointer());

        ve.baseVertexPointerToElement(voidPtr, ptrPtr);

        ve.delete();
    }
}
