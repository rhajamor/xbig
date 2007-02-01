/**
 * 
 */
package org.xbig.test.t6_2;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.InstancePointer;
import org.xbig.base.NativeObject;
import org.xbig.C;
import org.xbig.IB;
import org.xbig.IC;
import org.xbig.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {


	static class MyImpl extends NativeObject implements org.xbig.IB < org.xbig.IC > {
		public void delete() {
		}
		public IC a() {
			return null;
		}

		public void b(IC c) {
		}

		public IC c(IC a) {
			return null;
		}
		public void sety(IC value) {
		}
		public IC gety() {
			return null;
		}
		public void setx(int value) {
		}
		public int getx() {
			return 0;
		}
	}

	@Test
	public void useTemplateStruct() {
		// when the above code compiles, this test is passed
	}
}
