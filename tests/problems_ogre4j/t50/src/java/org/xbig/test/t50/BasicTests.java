/**
 * 
 */
package org.xbig.test.t50;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.ShortPointer;
import org.xbig.base.StringPointer;
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
        short s = 'A';
        ShortPointer sPtr = new ShortPointer((short)0);

        oFile.open(filename);
        oFile.put(s);
        oFile.close();

        iFile.open(filename);
        iFile.get(sPtr);
        iFile.close();

        System.out.println("got from file: " + sPtr.get());
        File javaFile = new File(filename);
        javaFile.delete();
        Assert.assertEquals(s, sPtr.get());

        sPtr.delete();
        iFile.delete();
        oFile.delete();
    }

    @Test
    public void wstring() {
        A a = new A();
        String string = "Bulldozer Frenzy";
        StringPointer strPtr = new StringPointer(string);

        Assert.assertEquals(string, a.wstringValue(string));
        Assert.assertEquals(string, a.wstringPointer(strPtr).get());
        Assert.assertEquals(string, a.wstringReference(strPtr).get());
        Assert.assertEquals(string, a.wstringConstValue(string));
        Assert.assertEquals(string, a.wstringConstPointer(strPtr).get());
        Assert.assertEquals(string, a.wstringConstReference(string));

        a.delete();
    }
}
