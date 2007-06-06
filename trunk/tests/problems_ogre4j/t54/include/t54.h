
#ifndef __T54_H__
#define __T54_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * Use of protected method, see bug 1728982
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif



namespace Ogre {

	class EXPORT Matrix4 {};

	class EXPORT ShadowCaster {};
	class EXPORT AnimableObject {};
	class EXPORT MovableObject : public ShadowCaster, public AnimableObject {};
	class EXPORT Renderable {};

	class EXPORT SimpleRenderable : public MovableObject, public Renderable {
	public:
		virtual void getWorldTransforms (Matrix4 *xform) const {}
	};

	class EXPORT WireBoundingBox : public SimpleRenderable {
	protected:
		virtual void getWorldTransforms (Matrix4 *xform) const {}
	};

}

#endif
