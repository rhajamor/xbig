/**
 * 
 */
package org.xbig.test.t13_3;

import java.util.HashMap;
import java.util.Map;
import java.util.Vector;
import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.StringPointer;
//import org.xbig.std.Imap;
import org.xbig.IA;
import org.xbig.IAMap;
import org.xbig.IAMapIterator;
import org.xbig.ITester;
import org.xbig.A;
import org.xbig.AMap;
import org.xbig.AMapIterator;
import org.xbig.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useStdMapAndOgreMapIterator() {
		Tester t = new Tester();

		// create test data
		Vector<StringPointer> keyVec = new Vector<StringPointer>();
		keyVec.add(new StringPointer("A"));
		keyVec.add(new StringPointer("B"));
		keyVec.add(new StringPointer("C"));
		keyVec.add(new StringPointer("D"));
		keyVec.add(new StringPointer("E"));

		Map<String, A> javaMap = new HashMap<String, A>();
		for (int i=0; i<keyVec.size(); ++i) {
			A a = new A();
			a.set(i);
			javaMap.put(keyVec.get(i).get(), a);
		}

		// create native map
		AMap nativeMap = new AMap();

		// copy test data to native map
		for (int i=0; i<javaMap.size(); i++) {
			String currentKey = (String)javaMap.keySet().toArray()[i];
			StringPointer nativeKey = new StringPointer(currentKey);
			nativeMap.insert(nativeKey.get(), javaMap.get(currentKey));
			nativeKey.delete();
		}

		// set filled map to test MapIterators
		t.setMap(nativeMap);

		// set and get Iterator with two calls
		IAMapIterator mapIterator = new AMapIterator(nativeMap);
		t.getMapIterator(mapIterator);
		t.a(mapIterator);
		IA aReturned = new A();
		mapIterator.peekNextValue(aReturned);
		Assert.assertEquals(javaMap.get(keyVec.get(0).get()).get(), aReturned.get());
		aReturned.delete();
		mapIterator.delete();

		// set and get Iterator with one call
		mapIterator = new AMapIterator(nativeMap);
		IAMapIterator mapIterator2 = new AMapIterator(nativeMap);
		t.c(mapIterator2, mapIterator);
		aReturned = new A();
		mapIterator2.peekNextValue(aReturned);
		IA aReturned2 = new A();
		mapIterator.peekNextValue(aReturned2);
		Assert.assertEquals(aReturned2.get(), aReturned.get());
		aReturned2.delete();
		aReturned.delete();
		mapIterator.delete();
		mapIterator2.delete();

		// test Iterator methods
		mapIterator = new AMapIterator(nativeMap);
		t.getMapIterator(mapIterator);
		Assert.assertTrue(mapIterator.hasMoreElements());
		for (int i=0; i<javaMap.size(); i++) {
			String currentKey = keyVec.get(i).get();
			aReturned = new A();
			mapIterator.getNext(aReturned);
			Assert.assertEquals(javaMap.get(currentKey).get(), aReturned.get());
			aReturned.delete();
		}
		Assert.assertFalse(mapIterator.hasMoreElements());
		mapIterator.delete();

		// test more Iterator methods
		mapIterator = new AMapIterator(nativeMap);
		for (int i=0; i<javaMap.size(); i++) {
			String nextKey = mapIterator.peekNextKey();
			aReturned = new A();
			mapIterator.peekNextValue(aReturned);
			Assert.assertEquals(javaMap.get(nextKey).get(), aReturned.get());
			aReturned.delete();
			Assert.assertEquals(javaMap.get(nextKey).get(), mapIterator.peekNextValuePtr().get());
			mapIterator.moveNext();
		}
		mapIterator.delete();

		// delete native objects
		nativeMap.delete();
		while (!javaMap.isEmpty()) {
			String currentKey = (String)javaMap.keySet().toArray()[0];
			javaMap.get(currentKey).delete();
			javaMap.remove(currentKey);
		}
		while (!keyVec.isEmpty()) {
			keyVec.get(0).delete();
			keyVec.remove(0);
		}
		t.delete();
	}
}
