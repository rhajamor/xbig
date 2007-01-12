/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles basic const
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

	const int a(float b);
	int const b(float b);
	int c(const float b);
	int d(float const b);
	int a(float b) const;
	void e() const;
};
