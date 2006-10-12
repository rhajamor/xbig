

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * pure virtual method
 ****************************************************************************************************************/


#include <string>

typedef std::string _StringBase;
typedef _StringBase String;

class RenderSystem {
public:
	virtual const String& getName  	(   	void   	  	 )   	 const =0;
};

class RenderSystemA : public RenderSystem {
public:
	virtual const String& getName  	(   	void   	  	 )   	 const;
};
