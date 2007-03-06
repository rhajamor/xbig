/**
 * 
 */
package org.xbig.test.t13_6;

import java.util.Vector;
import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.IntegerPointer;
//import org.xbig.std.Imap;
import org.xbig.n.IA;
import org.xbig.n.IOuterClass.IAptrVector;
import org.xbig.n.ITester;
import org.xbig.n.A;
import org.xbig.n.OuterClass.AptrVector;
import org.xbig.n.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void useStdMapWithAPointerAsTypeParameter() {
		Tester t = new Tester();

		// create test data
		Vector<IA> valVec = new Vector<IA>();
		valVec.add(new A());
		valVec.add(new A());
		valVec.add(new A());
		valVec.add(new A());
		valVec.add(new A());

		for (int i=0; i<valVec.size(); ++i) {
			valVec.get(i).set(i);
		}

		// create native vector
        AptrVector nativeVector = new AptrVector();

		// copy test data to native vector
		for (int i=0; i<valVec.size(); i++) {
			nativeVector.push_back(valVec.get(i));
		}

		// set and get map with two calls
		t.a(nativeVector);
		IAptrVector vector = t.b();
		Assert.assertEquals(valVec.get(0).get(), vector.at(0).get());
		vector.delete();

		// set and get Iterator with one call
		IAptrVector vector2 = t.c(nativeVector);
		Assert.assertEquals(nativeVector.at(0).get(), vector2.at(0).get());
		vector2.delete();

		// test all values
		for (int i=0; i<valVec.size(); i++) {
			Assert.assertEquals(valVec.get(i).get(), nativeVector.at(i).get());
		}

		// delete native objects
		nativeVector.delete();
		while (!valVec.isEmpty()) {
			valVec.get(0).delete();
			valVec.remove(0);
		}

		t.delete();
	}
}
