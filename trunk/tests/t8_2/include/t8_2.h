/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles const overloading and more than one const per line
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

	int const b(float b) const;
	int c(const float b) const;
	int d(float const b) const;
	const int e(float b) const;

	const int f(const float b) const;
	const int g(float const b) const;
	int const h(const float b) const;
	int const i(float const b) const;
};
