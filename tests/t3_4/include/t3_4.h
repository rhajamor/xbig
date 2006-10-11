/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a struct with references as method parameters and return values
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

struct EXPORT B {
	B();
	int a(float& b);
	int& b(float c);
	int& c(float& d);

	double& z;

private:
	int d;
};
