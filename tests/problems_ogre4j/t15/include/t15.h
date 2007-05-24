

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * object array as parameter
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


class EXPORT Vector3 {};

class EXPORT Matrix3 {
public:
	void EigenSolveSymmetric (float afEigenvalue[3], Vector3 akEigenvector[3]) const;
};
