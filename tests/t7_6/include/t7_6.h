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

class A {
public:
	A();
	typedef int Int;
};

struct B {
	B();
	typedef int Int;
};
