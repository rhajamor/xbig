/**
 * 
 */
package org.xbig.test.t70;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.base.*;
import org.xbig.Ogre.*;
import org.xbig.std.*;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
		IMesh mesh = new Mesh();

		IVertexBoneAssignment_s assignment = new VertexBoneAssignment_s();

	    assignment.setvertexIndex(0);
	    assignment.setboneIndex(0);
	    assignment.setweight(0.0f);

	    mesh.addVertexBoneAssignment(0, assignment);
	    assignment.delete();

	    assignment = new VertexBoneAssignment_s();

	    assignment.setvertexIndex(1);
	    assignment.setboneIndex(1);
	    assignment.setweight(0.1f);

	    mesh.addVertexBoneAssignment(1, assignment);
	    assignment.delete();

	    IMesh.IBoneAssignmentIterator iterator = new Mesh.BoneAssignmentIterator(WithoutNativeObject.I_WILL_DELETE_THIS_OBJECT);
	    mesh.getBoneAssignmentIterator(iterator);

	    Assert.assertTrue(iterator.hasMoreElements());
	    iterator.getNext(assignment);
	    Assert.assertEquals(0, assignment.getvertexIndex());
	    Assert.assertEquals(0, assignment.getboneIndex());
	    Assert.assertEquals(0.0f, assignment.getweight());
	    assignment.delete();

	    iterator.moveNext();
	    Assert.assertTrue(iterator.hasMoreElements());
	    iterator.getNext(assignment);
	    Assert.assertEquals(1, assignment.getvertexIndex());
	    Assert.assertEquals(1, assignment.getboneIndex());
	    Assert.assertEquals(0.1f, assignment.getweight());
	    assignment.delete();

	    iterator.delete();

	    mesh.delete();
	}
}
