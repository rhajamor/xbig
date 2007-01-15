/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles an enum
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

enum EXPORT Vocals {
	a,
	e,
	i,
	o,
	u
};

class EXPORT A {
public:
	bool isA(Vocals b);
	bool isE(Vocals a);
	bool isI(Vocals a);
	bool isO(Vocals a);
	bool isU(Vocals a);
};
