

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * overloaded method which gets duplicated
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


typedef float Real;

class EXPORT Matrix3 {
public:
	bool 	Inverse (Matrix3 &rkInverse, Real fTolerance=1e-06) const;
	Matrix3 	Inverse (Real fTolerance=1e-06) const;
};
