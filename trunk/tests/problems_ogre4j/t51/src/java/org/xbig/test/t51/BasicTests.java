/**
 * 
 */
package org.xbig.test.t51;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.IntegerPointer;
import org.xbig.Ogre.BillboardParticleRenderer;
import org.xbig.Ogre.IntPtrList;
import org.xbig.Ogre.ParticlePtrList;
import org.xbig.Ogre.RenderQueue;
/**
 * @author nenning
 *
 */
public class BasicTests {
	
	@Test
	public void test() {
        BillboardParticleRenderer bpr = new BillboardParticleRenderer();
        ParticlePtrList ppl = new ParticlePtrList();
        RenderQueue rq = new RenderQueue();
        IntPtrList ipl = new IntPtrList();
        IntegerPointer intPtr = new IntegerPointer(5);

        ipl.push_back(intPtr);
        Assert.assertEquals(intPtr.get(), ipl.back().get());

        bpr._updateRenderQueue(rq, ppl, false);
        bpr.primitiveTypePtrAsTypeParameter(ipl);

        ipl.delete();
        rq.delete();
        ppl.delete();
        bpr.delete();
	}
}
