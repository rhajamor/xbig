

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * overloaded method, once with ptr the other time with reference
 ****************************************************************************************************************/


#include <string>

class TextureUnitState {
public:
	void setCubicTextureName (const std::string &name, bool forUVW=false);
	void setCubicTextureName (const std::string *const names, bool forUVW=false);
};
