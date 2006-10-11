/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a multiple inheritance
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

class EXPORT A {
public:
	A();
	int a(float b);
};

class EXPORT B {
public:
	B();
	float c(int d);
};

class EXPORT C : public A, public B {
public:
	C();
	double e(long f);
};
