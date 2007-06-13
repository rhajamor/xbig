
#ifndef __T61_H__
#define __T61_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * ignore_list for single methods
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif





namespace Ogre {


	class EXPORT RibbonTrail {
	public:
		void doNotIgnore() {}
		void objectDestroyed(int a[5]) {}
	};
	
}

#endif
