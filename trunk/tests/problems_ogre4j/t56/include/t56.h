
#ifndef __T56_H__
#define __T56_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * const wrong for public attributes, see bug 1728986
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>


#define OGRE_NUM_SHADOW_EXTRUDER_PROGRAMS 8


namespace Ogre {

	typedef std::string String;


	class EXPORT Frustum {};

	class EXPORT TextureUnitState {
	public:
		class EXPORT TextureEffect {
		public:
			const Frustum * frustum;
		};
	};

	class EXPORT ShadowVolumeExtrudeProgram {
	public:
		static const String programNames[OGRE_NUM_SHADOW_EXTRUDER_PROGRAMS];
	};
}

#endif
