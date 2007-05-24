

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * overloaded method, once with ptr the other time with reference
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>

class EXPORT TextureUnitState {
public:
	void setCubicTextureName (const std::string &name, bool forUVW=false);
	void setCubicTextureName (const std::string *const names, bool forUVW=false);
};
