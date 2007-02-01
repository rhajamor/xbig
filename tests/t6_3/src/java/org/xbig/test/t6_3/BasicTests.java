/**
 * 
 */
package org.xbig.test.t6_3;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.InstancePointer;
import org.xbig.base.NativeObject;
import org.xbig.C;
import org.xbig.IA;
import org.xbig.IC;
import org.xbig.ID;
import org.xbig.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {

	static class MyImpl extends NativeObject implements org.xbig.IA < org.xbig.IC, org.xbig.ID > {
		public void delete() {
		}
		public IC a() {
			return null;
		}

		public void b(ID c) {
		}

		public ID c(IC a) {
			return null;
		}
	}


	@Test
	public void useTemplateWithTwoParameters() {
		// when the above code compiles, this test is passed
	}
}
