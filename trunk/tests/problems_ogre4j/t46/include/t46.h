
#ifndef __T46_H__
#define __T46_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * typeresolving does not work with inner types of base classes
 * see bug 1724323
 * see also bug 1711313 and t36
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif



namespace Ogre {

	class EXPORT ShadowCaster{};

	class EXPORT MovableObject {
	public:
		class EXPORT Listener {
		};
	};

	class RibbonTrail : public MovableObject, public ShadowCaster {
		Listener* mListener;
	public:
		void setListener(Listener* listener) {mListener = listener;}
		Listener* getListener() {return mListener;}
	};

}

#endif
