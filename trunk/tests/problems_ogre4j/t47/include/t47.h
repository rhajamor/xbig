
#ifndef __T47_H__
#define __T47_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * remaining template problems as of May 2007, see bug 1723314
 * - pointers and references to parametrized templates as method parameters or return types
 * - templates with primitve types as parameters as public attributes
 * - paratetrized templates as type parameters
 * - templates with a typedef for a primitive type as parameter
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>
#include <vector>


namespace Ogre {

	typedef float Real;
	typedef std::string String;
	//typedef const String const_string;
	typedef std::vector<Real> FloatVec;
	typedef std::vector<String> StrVec;
	typedef std::vector<std::pair<String, String> > StrStrVec;

	class A {
	public:
		void a(const std::vector<String>* vec) {}
		//void a2(const_string str) {}
		void a3(std::vector<Real>* vec) {}
		std::vector<String>* mVec;
		void b(std::vector<std::pair<String, String> > vec) {}
		void c(std::vector<Real> vec) {}
	};
}

#endif
