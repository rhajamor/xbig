/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a const pointer as type parameter
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#include <vector>


namespace n {
class EXPORT A {
public:
	void set(int i) {m = i;}
	int get() {return m;}
private:
	int m;
};


class EXPORT OuterClass {
public:
	typedef std::vector< const A * > AptrVector;	
};


class Tester {
public:
	void a(OuterClass::AptrVector a) {m = a;}
	OuterClass::AptrVector b() {return m;}
	OuterClass::AptrVector c(OuterClass::AptrVector a) {return a;}

private:
	OuterClass::AptrVector m;
};
}
