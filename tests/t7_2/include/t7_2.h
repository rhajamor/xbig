/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a typedef for a class
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

class EXPORT A {
public:
	int get5() {return 5;}
};

typedef A B;

class EXPORT C {
public:
	int a(B b) {mb = b; return b.get5();}
	B getB() {return mb;}
private:
	B mb;
};
