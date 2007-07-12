
#ifndef __T68_H__
#define __T68_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * resolving of inherited methods
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>


namespace Ogre {

	typedef std::string String;

	class EXPORT ResourcePtr {};

	class EXPORT ResourceManager {
	public:
		virtual ResourcePtr getByName (const String &name)
				{ResourcePtr r; return r;}
	};

	class EXPORT GpuProgramManager : public ResourceManager {
	public:
		ResourcePtr getByName(const String& name, bool preferHighLevelPrograms = true)
				{ResourcePtr r; return r;}
	};

}
#endif
