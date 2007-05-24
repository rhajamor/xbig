/**
 * 
 */
package org.xbig.test.t45;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.CompositorScriptCompiler;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        CompositorScriptCompiler csc = new CompositorScriptCompiler();
        csc.delete();
	}
}
