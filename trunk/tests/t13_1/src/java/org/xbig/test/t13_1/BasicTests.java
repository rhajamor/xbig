/**
 * 
 */
package org.xbig.test.t13_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.std.Ivector;
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
		StringVector sv = new StringVector();

		t.a(sv);
		Ivector vec = t.b();
		vec = t.c(sv);
		Assert.assertEquals();
		Assert.assertTrue();

		sv.delete();
		t.delete();
	}
}
