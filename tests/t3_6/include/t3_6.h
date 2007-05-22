/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a class with an inner struct
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

	struct EXPORT B {
		float x (int y);
		double z;
	};

	int a(float b);
	int b(struct B b);
};
