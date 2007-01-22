/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a typedef for a struct
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

struct EXPORT A {
public:
	int get5() {return 5;}
	int i;
};

typedef A B;

struct EXPORT C {
public:
	int a(B b) {return b.get5();}
	B getB();
	virtual ~C();
};
