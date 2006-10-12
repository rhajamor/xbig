

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * overloaded method which gets duplicated
 ****************************************************************************************************************/


typedef float Real;

class Matrix3 {
public:
	bool 	Inverse (Matrix3 &rkInverse, Real fTolerance=1e-06) const;
	Matrix3 	Inverse (Real fTolerance=1e-06) const;
};
