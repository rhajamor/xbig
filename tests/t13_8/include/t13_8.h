#ifndef __T13_8_H__
#define __T13_8_H__
/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * long as default mapping for unresolved types in native methods.
 * (fails but is considered successful)
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


class EXPORT A {
private:
	typedef int Int;
public:
	Int a(Int);
};

#endif
