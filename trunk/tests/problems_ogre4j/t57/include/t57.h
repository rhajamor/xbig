
#ifndef __T57_H__
#define __T57_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * getters and setters for private attribute (inside union), see bug 1728987
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>


namespace Ogre {

	typedef std::string String;


	class EXPORT UTFString {
	private:
		union {
			mutable void* mVoidBuffer;
			mutable std::string* mStrBuffer;
			mutable std::wstring* mWStrBuffer;
			//mutable utf32string* mUTF32StrBuffer;
		}
		m_buffer;
	};
}

#endif
