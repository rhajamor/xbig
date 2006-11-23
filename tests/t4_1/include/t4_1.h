/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a namespace
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

namespace n {
	class EXPORT A {
	public:
		A();
		~A();
		int a(float b);
	};
};
