/**
 * 
 */
package org.xbig.test.t52;

import org.junit.Assert;
import org.junit.Test;
import org.xbig.Ogre.AliasTextureNamePairList;
import org.xbig.Ogre.SceneNode.ObjectMap;
import org.xbig.Ogre.Root.MovableObjectFactoryMap;
import org.xbig.Ogre.RibbonTrail.NodeList;
import org.xbig.Ogre.SceneManagerEnumerator.MetaDataList;
import org.xbig.Ogre.SubMesh.AliasTextureIterator;
import org.xbig.Ogre.SkeletonInstance;
import org.xbig.Ogre.SceneNode.ConstObjectIterator;
import org.xbig.Ogre.Root.MovableObjectFactoryIterator;
import org.xbig.Ogre.RibbonTrail.NodeIterator;
import org.xbig.Ogre.SceneManagerEnumerator.MetaDataIterator;
/**
 * @author nenning
 *
 */
public class BasicTests {

	@Test
	public void test() {
        AliasTextureNamePairList atnpl = new AliasTextureNamePairList();
        ObjectMap om = new ObjectMap();
        MovableObjectFactoryMap mofm = new MovableObjectFactoryMap();
        NodeList nl = new NodeList();
        MetaDataList mdl = new MetaDataList();

        AliasTextureIterator ati = new AliasTextureIterator(atnpl);
        SkeletonInstance si = new SkeletonInstance();
        ConstObjectIterator coi = new ConstObjectIterator(om);
        MovableObjectFactoryIterator mofi = new MovableObjectFactoryIterator(mofm);
        NodeIterator ni = new NodeIterator(nl);
        MetaDataIterator mdi = new MetaDataIterator(mdl);

        mdi.delete();
        ni.delete();
        mofi.delete();
        coi.delete();
        si.delete();
        ati.delete();

        mdl.delete();
        nl.delete();
        mofm.delete();
        om.delete();
        atnpl.delete();
    }
}
