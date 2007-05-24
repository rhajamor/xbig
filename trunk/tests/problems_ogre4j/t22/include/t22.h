

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * pure virtual method
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>

typedef std::string _StringBase;
typedef _StringBase String;

class EXPORT RenderSystem {
public:
	virtual const String& getName  	(   	void   	  	 )   	 const =0;
};

class EXPORT RenderSystemA : public RenderSystem {
public:
	virtual const String& getName  	(   	void   	  	 )   	 const;
};
