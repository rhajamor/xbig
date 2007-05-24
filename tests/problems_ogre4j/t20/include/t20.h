

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * overloaded method with std list and vector
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <vector>
#include <list>

class EXPORT Ray {};
class EXPORT Plane {};

class EXPORT Math {
public:
	static std::pair< bool, float > intersects (const Ray &ray, const std::vector< Plane > &planeList, bool normalIsOutside);
	static std::pair< bool, float > intersects (const Ray &ray, const std::list< Plane > &planeList, bool normalIsOutside);
};
