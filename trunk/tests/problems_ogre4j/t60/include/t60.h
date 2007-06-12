
#ifndef __T60_H__
#define __T60_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * method does not exist in original lib, see bug 1729000
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <vector>


namespace Ogre {


	class EXPORT Light {};
	typedef std::vector<Light*> LightList;

	class EXPORT MovableObject {
		LightList mLights;
	public:
		virtual LightList& queryLights (void) /*const*/ {return mLights;}

		class EXPORT Listener {
			LightList mLights;
		public:
			virtual const LightList* objectQueryLights(const MovableObject *) {return &mLights;}
		};
	};

	class EXPORT RibbonTrail : public MovableObject {};
}

#endif
