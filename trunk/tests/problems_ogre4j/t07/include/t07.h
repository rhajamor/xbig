

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * inner typedef for std vector
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <vector>

class EXPORT IndexData{};

class EXPORT ProgressiveMesh {
public:
	typedef std::vector<IndexData*> LODFaceList;
};
