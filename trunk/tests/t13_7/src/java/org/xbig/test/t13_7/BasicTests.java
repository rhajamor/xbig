/**
 * 
 */
package org.xbig.test.t13_7;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.*;
import org.xbig.ITester.*;
import org.xbig.Tester.*;

/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useStdMapAndOgreMapIterator() {
		Tester tester = new Tester();
        ITester.IAMapIterator it = tester.getMapIterator();

        IA a = new A();
        while(it.hasMoreElements()){
            String key = it.peekNextKey();
            Assert.assertNotNull(key);
            System.out.println("key: "+key);
            
            it.getNext(a);
            Assert.assertNotNull(a);
            if(a.getInstancePointer().pointer == 0)
                throw new NullPointerException();
            a.delete();
        }

        tester.delete();
	}
}
