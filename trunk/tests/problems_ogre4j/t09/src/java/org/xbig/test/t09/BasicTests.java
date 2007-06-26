/**
 * 
 */
package org.xbig.test.t09;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.ConfigFile;
import org.xbig.IConfigFile;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
		ConfigFile cf = new ConfigFile();
		ConfigFile.SettingsMultiMap smm = new ConfigFile.SettingsMultiMap();
		ConfigFile.SettingsBySection sbs = new ConfigFile.SettingsBySection();

		IConfigFile.ISectionIterator si = new ConfigFile.SectionIterator();
        cf.getSectionIterator(si);

		si.delete();
		sbs.delete();
		smm.delete();
		cf.delete();
	}
}
