/**
 * 
 */
package org.xbig.test.t2_3;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
/**
 * @author nenning
 * 
 */
public class BasicTests {
	
	@Test
	public void callMethodWithDifferentNamesDifferentParameters() {
		A a = new A();
        
        byte  byteValue = 13;
        short smallShortValue = 234;
        short shortValue = 22513;
        int  intValue = 103455;
        long longValue = 32424567;
        float floatValue = 123.234f;
        double doubleValue = 12314.563456;
        
        Assert.assertEquals(a.getChar('c'),'c');
        Assert.assertEquals(a.getUnsignedChar(smallByteValue), smallByteValue);
        Assert.assertEquals(a.getSignedChar(byteValue), byteValue);
        
        Assert.assertEquals(a.getShort(shortValue), shortValue);
        Assert.assertEquals(a.getUnsignedShort(intValue), intValue);

        Assert.assertEquals(a.getInt(intValue), intValue);
        Assert.assertEquals(a.getUnsignedInt(longValue), longValue);

        Assert.assertEquals(a.getLong(longValue), longValue);
        Assert.assertEquals(a.getUnsignedLong(longValue), longValue);
        
        Assert.assertEquals(a.getFloat(floatValue), floatValue);
        Assert.assertEquals(a.getDouble(doubleValue), doubleValue);
        
		a.delete();
	}
    
    @Test
    public void callMethodWithSameNameDifferentParameters() {
        A a = new A();
        
        byte  byteValue = 13;
        short smallShortValue = 234;
        short shortValue = 22513;
        int  intValue = 103455;
        long longValue = 32424567;
        float floatValue = 123.234f;
        double doubleValue = 12314.563456;
        
        
        a.delete();
    }
    
}
