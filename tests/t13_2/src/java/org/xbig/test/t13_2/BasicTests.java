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
		Vector<StringPointer> javaVec = new Vector<StringPointer>();
		javaVec.add(new StringPointer("Bulldozer Frenzy"));
		javaVec.add(new StringPointer("Bulldozer"));
		javaVec.add(new StringPointer("Frenzy"));
		javaVec.add(new StringPointer("One Man Army"));
		javaVec.add(new StringPointer("The Undead Quartet"));

		// create native vector
		StringVector nativeStringVector = new StringVector();

		// copy test data to native vector
		for (int i=0; i<javaVec.size(); i++) {
			nativeStringVector.push_back(javaVec.get(i));
		}

		// set filled vector to test VectorIterators
		t.setVector(nativeStringVector);

		// set and get Iterator with two calls
		IStringIterator stringIterator = t.b();
		t.a(stringIterator);
		Assert.assertEquals(javaVec.get(0).get(), stringIterator.peekNext());
		stringIterator.delete();

		// set and get Iterator with one call
		stringIterator = new StringIterator(nativeStringVector);
		IStringIterator stringIterator2 = t.c(stringIterator);
		Assert.assertEquals(stringIterator.peekNext(), stringIterator2.peekNext());
		stringIterator.delete();
		stringIterator2.delete();

		// test Iterator methods
		stringIterator = t.b();
		Assert.assertTrue(stringIterator.hasMoreElements());
		for (int i=0; i<javaVec.size(); i++) {
			Assert.assertEquals(javaVec.get(i).get(), stringIterator.getNext());
		}
		Assert.assertFalse(stringIterator.hasMoreElements());
		stringIterator.delete();

		// test more Iterator methods
		stringIterator = t.b();
		for (int i=0; i<javaVec.size(); i++) {
			Assert.assertEquals(javaVec.get(i).get(), stringIterator.peekNext());
			Assert.assertEquals(javaVec.get(i).get(), stringIterator.peekNextPtr().get());
			stringIterator.moveNext();
		}
		stringIterator.delete();

		// delete native objects
		nativeStringVector.delete();
		for (int i=0; i<javaVec.size(); i++) {
			javaVec.get(i).delete();
		}
		t.delete();
	}
}
