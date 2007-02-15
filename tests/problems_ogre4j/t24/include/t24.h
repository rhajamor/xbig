

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


#include <list>

class Plane {};

class SceneQuery {
public:
	struct WorldFragment {
		WorldFragment() {planes = (std::list< Plane >*)1;}
		std::list< Plane >* planes;
	};
};
