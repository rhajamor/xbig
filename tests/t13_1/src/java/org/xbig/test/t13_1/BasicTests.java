/**
 * 
 */
package org.xbig.test.t13_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.StringPointer;
//import org.xbig.std.Ivector;
import org.xbig.IStringVector;
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
		StringPointer sPtr = new StringPointer("Bulldozer Frenzy");
		StringVector sv = new StringVector();

		Assert.assertTrue(sv.empty());
		sv.push_back(sPtr.get());
		Assert.assertFalse(sv.empty());
		Assert.assertEquals(sPtr.get(), sv.at(0));

		t.a(sv);
		IStringVector vec = t.b();
		Assert.assertEquals(sv.size(), vec.size());
		vec.delete();
		vec = t.c(sv);
		Assert.assertEquals(sv.size(), vec.size());
		vec.delete();

		sv.delete();
		sPtr.delete();
		t.delete();
	}
}
