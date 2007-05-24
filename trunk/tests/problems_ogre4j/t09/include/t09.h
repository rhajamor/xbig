

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * it is not possible to get XxxIterator
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <map>
#include <string>


template <class T>
class EXPORT MapIterator {};

typedef std::string _StringBase;
typedef _StringBase String;


class EXPORT ConfigFile {
public:
	typedef std::multimap<String, String> SettingsMultiMap;
	typedef std::map<String, SettingsMultiMap*> SettingsBySection;
	typedef MapIterator<SettingsBySection> SectionIterator;

	SectionIterator getSectionIterator();
};
