/**
 * 
 */
package org.xbig.test.t13_5;

import java.util.Vector;
import org.junit.Assert;
import org.junit.Test;
import org.junit.After;
import org.junit.Before;
import org.xbig.base.IntegerPointer;
//import org.xbig.std.Imap;
import org.xbig.n.IA;
import org.xbig.n.IOuterClass.IAptrMap;
import org.xbig.n.ITester;
import org.xbig.n.A;
import org.xbig.n.OuterClass.AptrMap;
import org.xbig.n.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {
    
    final int size = 5;
    Tester t = null;
    Vector<Integer> keyVec = null;
    Vector<IA> valVec = null;
    AptrMap nativeMap = null;
	
    @Before
    public void setup(){
        t = new Tester();
        
        // create test data
        keyVec = new Vector<Integer>();
        for (int i=0; i<size; i++){
            keyVec.add(new Integer(i));
        }

        valVec = new Vector<IA>();        
        for(int i=0; i<size; i++){
            valVec.add(new A());
            valVec.get(i).set(i);
        }
        
        //      create native map
        nativeMap = new AptrMap();

        // copy test data to native map
        for (int i=0; i<size; i++) {
            nativeMap.insert(keyVec.get(i), valVec.get(i));
        }
    }
    
    @After
    public void teardown(){
        // delete native objects
        nativeMap.delete();
        
        while (!valVec.isEmpty()) {
            valVec.get(0).delete();
            valVec.remove(0);
        }

        t.delete();
    }
    
	@Test
	public void setAndGetMapWithTwoCalls() {
		// set and get map with two calls
		t.a(nativeMap);
		IAptrMap map = new AptrMap();
        t.b(map);
		Assert.assertEquals(valVec.get(0).get(), map.get(keyVec.get(0)).get());
		map.delete();			
	}
    
    @Test
    public void setAndGetMapWithOneCall(){
        IAptrMap map2 = new AptrMap();
        t.c(map2, nativeMap);
        Assert.assertEquals(nativeMap.get(keyVec.get(0)).get(), map2.get(keyVec.get(0)).get());
        map2.delete();
    }
    
    @Test
    public void testAllValues()
    {
        for (int i=0; i<size; i++) {
            Assert.assertEquals(valVec.get(i).get(), nativeMap.get(keyVec.get(i)).get());
        }
    }
}
