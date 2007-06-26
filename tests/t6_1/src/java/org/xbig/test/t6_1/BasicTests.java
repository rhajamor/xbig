/**
 * 
 */
package org.xbig.test.t6_1;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.InstancePointer;
import org.xbig.base.NativeObject;
import org.xbig.base.ParametrizedTemplateReturnPlaceHolder;
import org.xbig.C;
import org.xbig.IA;
import org.xbig.IC;
import org.xbig.Tester;
/**
 * @author nenning
 *
 */
public class BasicTests {


	/**
	 * This own implementation is necessary,
	 * as we cannot generate classes for templates
	 */
	static class MyImpl extends NativeObject implements org.xbig.IA < org.xbig.IC > {
		static {System.loadLibrary("myimpl");}
		public MyImpl(org.xbig.base.InstancePointer p, boolean remote) {
			super(p, remote);
		}
		public void delete() {
			if (this.remote)
		       throw new RuntimeException("can't dispose object not created by native library");

		    __delete(object.pointer);
		    this.deleted = true;
		}
		public void finalize() {
			if(!this.remote && !this.deleted)
				delete();
		}
		private final native void __delete(long _pointer_);	

		public MyImpl(){ super( new org.xbig.base.InstancePointer(MyImpl()), false);}
		private native static final long MyImpl();

		public void a(IC retVal) {
            retVal.delete();
            retVal.setInstancePointer(new InstancePointer(a(this.object.pointer)), false);
		}
		private native final long a(long _pointer_);

		public void b(IC c) {
			b(this.object.pointer, c.getInstancePointer().pointer);
		}
		private native final void b(long _pointer_, long c);

		public void c(IC retVal, IC a) {
            retVal.delete();
            retVal.setInstancePointer(new InstancePointer(
					c(this.object.pointer, a.getInstancePointer().pointer)), false);
		}
		private native final long c(long _pointer_, long a);
	}


	@Test
	public void useTemplate() {
		Tester t = new Tester();
		MyImpl myi;
		myi = new MyImpl();

		t.b(myi);

		Assert.assertTrue(t.a(myi));

		IC c = new C();
        myi.a(c);
		Assert.assertEquals(5, c.get5());
		c.delete();

		myi.b(c);

        c = new C();
        IC c2 = new C();
        myi.c(c2, c);
        c2.delete();
		c.delete();

		myi.delete();
		t.delete();
	}
}
