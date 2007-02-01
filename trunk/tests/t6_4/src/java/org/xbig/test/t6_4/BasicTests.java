/**
 * 
 */
package org.xbig.test.t6_4;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.InstancePointer;
import org.xbig.base.NativeObject;
import org.xbig.o.IC;
import org.xbig.n.IA;
import org.xbig.p.ID;
import org.xbig.p.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {

	static class MyImpl extends NativeObject implements org.xbig.n.IA < org.xbig.o.IC, org.xbig.p.ID > {
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
	public void useTemplateWithTwoParametersInDifferentPackages() {
		// when the above code compiles, this test is passed
	}
}
