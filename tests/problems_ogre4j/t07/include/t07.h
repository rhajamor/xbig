

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * inner typedef for std vector
 ****************************************************************************************************************/


#include <vector>

class IndexData{};

class ProgressiveMesh {
public:
	typedef std::vector<IndexData*> LODFaceList;
};
