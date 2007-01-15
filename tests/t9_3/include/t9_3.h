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
		a = 101,
		e = 102,
		i = 103,
		o = 104,
		u = 105
	};
}

class EXPORT A {
public:
	enum EXPORT Vocals {
		a = 201,
		e = 202,
		i = 203,
		o = 204,
		u = 205
	};
};

struct EXPORT B {
	enum EXPORT Vocals {
		a = 301,
		e = 302,
		i = 303,
		o = 304,
		u = 305
	};
};

class EXPORT Vocals {};

class EXPORT Tester {
public:
	bool isN(n::Vocals a);
	bool isA(A::Vocals a);
	bool isB(B::Vocals a);
};
