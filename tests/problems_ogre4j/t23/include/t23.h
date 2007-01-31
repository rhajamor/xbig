

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * some C++ operator methods are needed in java
 ******************************************************************/


class Vector {
public:
	Vector operator+(const Vector& rkVector) const;

private:
	int i;
};
