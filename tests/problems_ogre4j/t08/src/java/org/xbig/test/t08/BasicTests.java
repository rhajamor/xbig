/**
 * 
 */
package org.xbig.test.t08;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.StringPointer;
import org.xbig.Root;
import org.xbig.Animation;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		Animation.NumericTrackList ntl = new Animation.NumericTrackList();
		Animation.NumericTrackIterator nti = new Animation.NumericTrackIterator();
		nti.delete();
		ntl.delete();

		StringPointer plugin = new StringPointer("");
		StringPointer config = new StringPointer("");
		StringPointer log = new StringPointer("");
		Root root = new Root(plugin, config, log);
		root.saveConfig();
		root.delete();
		plugin.delete();
		config.delete();
		log.delete();
	}
}
