/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a class with pointers and references to objects
 * as parameters and return values
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

class EXPORT B {
public:
	int get1();
};

class EXPORT A {
public:
	A();
	void a(B* a);
	B* b();
	bool c(B& a);
	B& d();
private:
	B* b_ptr;
	B& b_ref;
};
