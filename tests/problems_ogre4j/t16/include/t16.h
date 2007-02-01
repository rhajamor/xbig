

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


class OverlayElement {};

class OverlayManager {
public:
	void destroyOverlayElement(OverlayElement* pInstance, bool isTemplate = false);
};
