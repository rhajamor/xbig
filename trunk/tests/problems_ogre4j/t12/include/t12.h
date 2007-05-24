

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * no createInstance implementation for certain constructors
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


class EXPORT ColourValue {
public:
	ColourValue (float red=1.0f, float green=1.0f, float blue=1.0f, float alpha=1.0f);
};
