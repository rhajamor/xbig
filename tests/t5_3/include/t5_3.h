/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles inheritance with a pure virtual method
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
	virtual int a(float b) =0;
	void b();
};

class EXPORT B : public A {
public:
	B();
	int a(float b);
	float c(int d);
	A* getA();
};
