

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


#include <vector>
#include <string>

typedef std::vector<std::string> StringVector;

class ShadowCaster {};

class AnimableObject {
public:
	const StringVector& getAnimableValueNames(void) const;
};

class MoveableObject : public ShadowCaster, public AnimableObject {};
