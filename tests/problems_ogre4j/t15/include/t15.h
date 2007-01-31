

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


class Vector3 {};

class Matrix3 {
public:
	void EigenSolveSymmetric (float afEigenvalue[3], Vector3 akEigenvector[3]) const;
};
