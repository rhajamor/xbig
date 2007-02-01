/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a struct with an inner class
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

struct EXPORT A {
	A();

	class EXPORT B {
	public:
		float x (int y);
		double z;
	};

	int a(float b);
};
