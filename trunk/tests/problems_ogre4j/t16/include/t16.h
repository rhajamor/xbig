

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * original code uses same parameter name as generator
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


class EXPORT OverlayElement {};

class EXPORT OverlayManager {
public:
	void destroyOverlayElement(OverlayElement* pInstance, bool isTemplate = false);
};
