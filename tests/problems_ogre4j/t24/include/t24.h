

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * std list in struct
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <list>

class EXPORT Plane {};

class EXPORT SceneQuery {
public:
	struct EXPORT WorldFragment {
		WorldFragment() {planes = (std::list< Plane >*)1;}
		std::list< Plane >* planes;
	};
};
