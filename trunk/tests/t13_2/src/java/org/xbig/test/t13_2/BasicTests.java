/**
 * 
 */
package org.xbig.test.t13_2;

import java.util.Vector;
import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.StringPointer;
import org.xbig.IStringIterator;
import org.xbig.IStringVector;
import org.xbig.StringIterator;
import org.xbig.StringVector;
import org.xbig.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useTypedefForExternalType() {
		Tester t = new Tester();

		// create test data
		Vector<String> javaVec = new Vector<String>();
		javaVec.add("Bulldozer Frenzy");
		javaVec.add("Bulldozer");
		javaVec.add("Frenzy");
		javaVec.add("One Man Army");
		javaVec.add("The Undead Quartet");

		// create native vector
		StringVector nativeStringVector = new StringVector();

		// copy test data to native vector
		for (int i=0; i<javaVec.size(); i++) {
			nativeStringVector.push_back(javaVec.get(i));
		}

		// set filled vector to test VectorIterators
		t.setVector(nativeStringVector);

		// set and get Iterator with two calls
		IStringIterator stringIterator = new StringIterator(nativeStringVector);
        t.b(stringIterator);
		t.a(stringIterator);
		Assert.assertEquals(javaVec.get(0), stringIterator.peekNext());
		stringIterator.delete();

		// set and get Iterator with one call
		stringIterator = new StringIterator(nativeStringVector);
		IStringIterator stringIterator2 = new StringIterator(nativeStringVector);
        t.c(stringIterator2, stringIterator);
		Assert.assertEquals(stringIterator.peekNext(), stringIterator2.peekNext());
		stringIterator.delete();
		stringIterator2.delete();

		// test Iterator methods
		t.b(stringIterator);
		Assert.assertTrue(stringIterator.hasMoreElements());
		for (int i=0; i<javaVec.size(); i++) {
			Assert.assertEquals(javaVec.get(i), stringIterator.getNext());
		}
		Assert.assertFalse(stringIterator.hasMoreElements());
		stringIterator.delete();

		// test more Iterator methods
		t.b(stringIterator);
		for (int i=0; i<javaVec.size(); i++) {
			Assert.assertEquals(javaVec.get(i), stringIterator.peekNext());
			Assert.assertEquals(javaVec.get(i), stringIterator.peekNextPtr().get());
			stringIterator.moveNext();
		}
		stringIterator.delete();

		// delete native objects
		nativeStringVector.delete();
		t.delete();
	}
}
