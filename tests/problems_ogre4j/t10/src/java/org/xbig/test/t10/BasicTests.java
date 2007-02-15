/**
 * 
 */
package org.xbig.test.t10;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.StringPointer;
import org.xbig.Root;
import org.xbig.NameValuePairList;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		NameValuePairList nvpl = new NameValuePairList();
		StringPointer sp = new StringPointer("");
		Root root = new Root();

		root.createRenderWindow(sp, 0L, 0L, false, nvpl);
		root.createSceneManager(0, sp);

		root.delete();
		sp.delete();
		nvpl.delete();
	}
}
