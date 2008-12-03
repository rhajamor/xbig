/**
 * 
 */
package org.xbig.test.t50;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.BytePointer;
import org.xbig.base.WideStringPointer;
import org.xbig.Ogre.A;
import org.xbig.std.ofstream;
import org.xbig.std.ifstream;
import org.xbig.std.ios.fmtflags;
import java.io.File;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void passCppIOstreams() {
        A a = new A();
        ofstream oFile = new ofstream();
        ifstream iFile = new ifstream();

        a.dump(oFile);
        a.a(iFile);
        a.b(fmtflags.dec);

        iFile.delete();
        oFile.delete();
        a.delete();
	}

    @Test
    public void useCppFileIO() {
        ofstream oFile = new ofstream();
        ifstream iFile = new ifstream();

        String filename = "test.txt";
        short s = 'A'; // = 65 in ascii
        BytePointer bytePtr = new BytePointer((byte)0);

        oFile.open(filename);
        oFile.put(s);
        oFile.close();

        iFile.open(filename);
        iFile.get(bytePtr);
        iFile.close();

        System.out.println("got from file: " + bytePtr.get() + ", as char: " + (char)(bytePtr.get().byteValue()));
        File javaFile = new File(filename);
        javaFile.delete();
        Assert.assertEquals(s, (short)bytePtr.get());

        bytePtr.delete();
        iFile.delete();
        oFile.delete();
    }

    @Test
    public void wstring() {
        A a = new A();
        String string = "Bulldozer Frenzy";
        WideStringPointer wstrPtr = new WideStringPointer(string);

        Assert.assertEquals(string, a.wstringValue(string));
        Assert.assertEquals(string, a.wstringPointer(wstrPtr).get());
        Assert.assertEquals(string, a.wstringReference(wstrPtr).get());
        Assert.assertEquals(string, a.wstringConstValue(string));
        Assert.assertEquals(string, a.wstringConstPointer(wstrPtr).get());
        Assert.assertEquals(string, a.wstringConstReference(string));

        wstrPtr.delete();
        a.delete();
    }
}
