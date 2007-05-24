

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * class with getter and setter for public fields
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


class EXPORT Radian {};

class EXPORT Particle {
public:
	void setRotation (const Radian &rad);
	const Radian & getRotation (void) const;

	Radian rotation;
};
