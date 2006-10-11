/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a class with an inner class
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
	class EXPORT B {
	public:
		B();
		float x (int y);
	};

	int a(float b);
};
