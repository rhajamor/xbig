/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles an enum inside a namespace / class / struct
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

namespace n {
	enum EXPORT Vocals {
		a,
		e,
		i,
		o,
		u
	};
}

class A {
public:
	A();
	enum EXPORT Vocals {
		a,
		e,
		i,
		o,
		u
	};
};

struct B {
	B();
	enum EXPORT Vocals {
		a,
		e,
		i,
		o,
		u
	};
};
