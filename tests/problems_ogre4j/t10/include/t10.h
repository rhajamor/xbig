

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * jlong is not always a pointer
 ******************************************************************/


#include <map>
#include <string>

class RenderWindow {};
class SceneManager {};

typedef std::string _StringBase;
typedef _StringBase String;
typedef std::map<String, String> NameValuePairList;

typedef unsigned short uint16;
typedef uint16 SceneTypeMask;

class StringUtil {
public:
	static const String BLANK;
};

class Root {
public:
	RenderWindow* createRenderWindow  	(   	const String &   	 name,
		unsigned int  	width,
		unsigned int  	height,
		bool  	fullScreen,
		const NameValuePairList *  	miscParams = 0
	);

	SceneManager* createSceneManager  	(   	SceneTypeMask   	 typeMask,
		const String &  	instanceName = StringUtil::BLANK
	);
};
