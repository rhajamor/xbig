/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a simple class
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
};

class EXPORT B {
public:
	
};

class EXPORT C {
private:
	C();
};

class EXPORT D {
protected:
	D();
};
