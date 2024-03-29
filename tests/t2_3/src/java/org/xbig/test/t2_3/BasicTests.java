/**
 *
 */
package org.xbig.test.t2_3;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.A;
import org.xbig.ITime;
import org.xbig.Time;
import org.xbig.base.*;

/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void callMethodWithDifferentNamesDifferentParameters() {
		A a = new A();

		short charValue = 127;
        byte  signedCharValue = -128;
        short unsignedCharValue = 234;
        Assert.assertEquals(a.getChar(charValue),charValue);
        Assert.assertEquals(a.getUnsignedChar(unsignedCharValue), unsignedCharValue);
        Assert.assertEquals(a.getSignedChar(signedCharValue), signedCharValue);

        short shortValue = 22513;
        short shortIntValue = -22513;
        short signedShortValue = 32767;
        short signedShortIntValue = -32768;
        int unsignedShortValue = 50000;
        int unsignedShortIntValue = 65535;
        Assert.assertEquals(a.getShort(shortValue), shortValue);
        Assert.assertEquals(a.getShortInt(shortIntValue), shortIntValue);
        Assert.assertEquals(a.getSignedShort(signedShortValue), signedShortValue);
        Assert.assertEquals(a.getSignedShortInt(signedShortIntValue), signedShortIntValue);
        Assert.assertEquals(a.getUnsignedShort(unsignedShortValue), unsignedShortValue);
        Assert.assertEquals(a.getUnsignedShortInt(unsignedShortIntValue), unsignedShortIntValue);

        int intValue = 2147483647;
        int signedValue = -2147483648;
        int signedIntValue = 2000000000;
        long unsignedValue = 3000000000L;
        long unsignedIntValue = 4294967295L;
        Assert.assertEquals(a.getInt(intValue), intValue);
        Assert.assertEquals(a.getSigned(signedValue), signedValue);
        Assert.assertEquals(a.getSignedInt(signedIntValue), signedIntValue);
        Assert.assertEquals(a.getUnsigned(unsignedValue), unsignedValue);
        Assert.assertEquals(a.getUnsignedInt(unsignedIntValue), unsignedIntValue);

        long longValue = 1000000000L;
        long longIntValue = 2147483647L;
        long signedLongValue = -1000000000L;
        long signedLongIntValue = -2147483648L;
        long unsignedLongValue = 3000000000L;
        long unsignedLongIntValue = 4294967295L;
        Assert.assertEquals(a.getLong(longValue), longValue);
        Assert.assertEquals(a.getLongInt(longIntValue), longIntValue);
        Assert.assertEquals(a.getSignedLong(signedLongValue), signedLongValue);
        Assert.assertEquals(a.getSignedLongInt(signedLongIntValue), signedLongIntValue);
        Assert.assertEquals(a.getUnsignedLong(unsignedLongValue), unsignedLongValue);
        Assert.assertEquals(a.getUnsignedLongInt(unsignedLongIntValue), unsignedLongIntValue);

        long longLongValue = -9223372036854775808L;
        long signedLongLongValue = 9223372036854775807L;
        ULongLong unsignedLongLongValue = new ULongLong("18446744073709551615");
        Assert.assertEquals(a.getLongLong(longLongValue), longLongValue);
        Assert.assertEquals(a.getSignedLongLong(signedLongLongValue), signedLongLongValue);
        Assert.assertEquals(a.getUnsignedLongLong(unsignedLongLongValue).equals(unsignedLongLongValue), true);

        float floatValue = 123.234f;
        double doubleValue = 12314.563456;
        Assert.assertEquals(a.getFloat(floatValue), floatValue);
        Assert.assertEquals(a.getDouble(doubleValue), doubleValue);

        String stringValue = "12345";
        Assert.assertEquals(a.getString(stringValue), stringValue);

        // char* is not mapped to String anymore
        //String charStarValue = "23456";
        NativeByteBuffer pseudoCString = new NativeByteBuffer(3);
        pseudoCString.setIndex(0, (byte)65); // 65 is 'A' in ASCII
        pseudoCString.setIndex(1, (byte)66);
        pseudoCString.setIndex(2, (byte)0);
        BytePointer charStar = new BytePointer(pseudoCString.getInstancePointer()); // pseudo cast
        //Assert.assertEquals(a.getCharStar(charStarValue), charStarValue);
        Assert.assertEquals(a.getCharStar(charStar).get(), charStar.get());
        pseudoCString.delete();

        // const char* is mapped to String
        String constCharStarValue = "34567";
        Assert.assertEquals(a.getConstCharStar(constCharStarValue), constCharStarValue);

        short unsignedChar = 300;
        byte signedChar = -128;
        ShortPointer shortPtr = new ShortPointer(unsignedChar);
        BytePointer bytePtr = new BytePointer(signedChar);
        Assert.assertEquals(unsignedChar, a.getUnsignedCharStar(shortPtr).get());
        Assert.assertEquals(signedChar, a.getSignedCharStar(bytePtr).get());
        shortPtr.delete();
        bytePtr.delete();

        int size_tValue = 12345;
        char wchar_tValue = 'a';
        Assert.assertEquals(a.getWchar_t(wchar_tValue), wchar_tValue);

		a.delete();
	}

	@Test
	public void testTime() {
		ITime time = new Time();

		// on my linux test machine, time_t was 4 bytes unsigned
		//long currentTime = System.currentTimeMillis();
		long currentTime = 2147483647L;
		time.setTime(currentTime);

		Assert.assertEquals(currentTime, time.getTime());
		Assert.assertEquals(currentTime, time.getTimePtr().get());
		Assert.assertEquals(currentTime, time.getTimeRef().get());

		// on my windows test machine, time_t was 8 bytes but
		// long was just 4 bytes.
		//LongPointer currentTimePtr = new LongPointer(currentTime);
		NativeLongBuffer buf = new NativeLongBuffer(2);
		buf.setIndex(0, currentTime); // is this endian related?
		buf.setIndex(1, 0L);
		LongPointer currentTimePtr = new LongPointer(buf.getInstancePointer());
		time.setTimePtr(currentTimePtr);

		Assert.assertEquals(currentTime, time.getTime());
		Assert.assertEquals(currentTime, time.getTimePtr().get());
		Assert.assertEquals(currentTime, time.getTimeRef().get());

		time.setTimeRef(currentTimePtr);

		Assert.assertEquals(currentTime, time.getTime());
		Assert.assertEquals(currentTime, time.getTimePtr().get());
		Assert.assertEquals(currentTime, time.getTimeRef().get());

		//currentTimePtr.delete();
		buf.delete();
		time.delete();
	}

	/*
	 Move B to t2_9

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
    }*/

}
