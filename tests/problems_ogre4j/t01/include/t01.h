

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * c functions for inherited methods are not generated
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <vector>
#include <string>

typedef std::vector<std::string> StringVector;

class EXPORT ShadowCaster {};

class EXPORT AnimableObject {
public:
	const StringVector& getAnimableValueNames(void) const;
};

class EXPORT MoveableObject : public ShadowCaster, public AnimableObject {};
