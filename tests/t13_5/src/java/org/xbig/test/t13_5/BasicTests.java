/**
 * 
 */
package org.xbig.test.t13_5;

import java.util.Vector;
import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.IntegerPointer;
//import org.xbig.std.Imap;
import org.xbig.IA;
import org.xbig.IAptrMap;
import org.xbig.ITester;
import org.xbig.A;
import org.xbig.AptrMap;
import org.xbig.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useStdMapWithAPointerAsTypeParameter() {
		Tester t = new Tester();

		// create test data
		Vector<IntegerPointer> keyVec = new Vector<IntegerPointer>();
		keyVec.add(new IntegerPointer(0));
		keyVec.add(new IntegerPointer(1));
		keyVec.add(new IntegerPointer(2));
		keyVec.add(new IntegerPointer(3));
		keyVec.add(new IntegerPointer(4));

		Vector<IA> valVec = new Vector<IA>();
		valVec.add(new A());
		valVec.add(new A());
		valVec.add(new A());
		valVec.add(new A());
		valVec.add(new A());

		for (int i=0; i<valVec.size(); ++i) {
			valVec.get(i).set(i);
		}

		// create native map
		AptrMap nativeMap = new AptrMap();

		// copy test data to native map
		for (int i=0; i<keyVec.size(); i++) {
			nativeMap.insert(keyVec.get(i), valVec.get(i));
		}

		// set and get map with two calls
		t.a(nativeMap);
		IAptrMap map = t.b();
		Assert.assertEquals(valVec.get(0).get(), map.get(keyVec.get(0)).get());
		map.delete();

		// set and get Iterator with one call
		IAptrMap map2 = t.c(nativeMap);
		Assert.assertEquals(nativeMap.get(keyVec.get(0)).get(), map2.get(keyVec.get(0)).get());
		map2.delete();

		// test all values
		for (int i=0; i<keyVec.size(); i++) {
			Assert.assertEquals(valVec.get(i).get(), nativeMap.get(keyVec.get(i)).get());
		}

		// delete native objects
		nativeMap.delete();
		while (!valVec.isEmpty()) {
			valVec.get(0).delete();
			valVec.remove(0);
		}
		while (!keyVec.isEmpty()) {
			keyVec.get(0).delete();
			keyVec.remove(0);
		}
		t.delete();
	}
}
