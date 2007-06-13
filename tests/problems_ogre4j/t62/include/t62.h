
#ifndef __T62_H__
#define __T62_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * std::basic_string<T>
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>


namespace Ogre {

	typedef unsigned short int uint16;
	typedef unsigned int uint32;

	typedef uint16 code_point;
	typedef uint32 unicode_char;
	typedef std::basic_string<code_point> dstring;
	typedef std::basic_string<unicode_char> utf32string;
}

#endif
