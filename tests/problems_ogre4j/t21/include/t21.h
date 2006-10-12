

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * public method requires protected type as parameter
 ****************************************************************************************************************/


#include <string>

class ResourceGroupManager {
protected:
	struct ResourceGroup {};

public:
	bool resourceExists(ResourceGroup group, const std::string& filename);
};
