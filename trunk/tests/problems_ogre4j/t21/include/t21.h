

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * public method requires protected type as parameter
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>

class EXPORT ResourceGroupManager {
protected:
	struct ResourceGroup {};

public:
	bool resourceExists(ResourceGroup group, const std::string& filename);
};
