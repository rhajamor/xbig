

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * class with getter and setter for public fields
 ****************************************************************************************************************/


class Radian {};

class Particle {
public:
	void setRotation (const Radian &rad);
	const Radian & getRotation (void) const;

	Radian rotation;
};
