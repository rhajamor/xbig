
#ifndef __T50_H__
#define __T50_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * further extension of STL wrapper, see bug 1666895
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>


namespace Ogre {

	class EXPORT A {
	public:
		void dump(std::ofstream&){}
		void a(std::ifstream&){}
		void b(std::ios::fmtflags){}

		std::wstring wstringValue(std::wstring str) {return str;}
		std::wstring* wstringPointer(std::wstring* str) {return str;}
		std::wstring& wstringReference(std::wstring& str) {return str;}

		const std::wstring wstringConstValue(const std::wstring str) {return str;}
		const std::wstring* wstringConstPointer(const std::wstring* str) {return str;}
		const std::wstring& wstringConstReference(const std::wstring& str) {return str;}
	};
}

#endif
