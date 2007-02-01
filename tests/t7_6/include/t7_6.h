/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a typedef inside a namespace / class / struct
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

namespace n {
	typedef int Int;
}

class EXPORT A {
public:
	typedef int Int;
};

struct EXPORT B {
	typedef int Int;
};

class EXPORT C {
public:
	bool isN(n::Int i) {return true;}
	bool isA(A::Int i) {return true;}
	bool isB(B::Int i) {return true;}
};
