/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a typedef for a primitive type
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

typedef int Int;

class EXPORT A {
public:
	Int a(Int b) {return b;}
};
