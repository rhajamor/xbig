/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a pointer as type parameter
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#include <map>


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
	typedef std::map<unsigned short, A * > AptrMap;
};


class Tester {
public:
	void a(OuterClass::AptrMap a) {m = a;}
	OuterClass::AptrMap b() {return m;}
	OuterClass::AptrMap c(OuterClass::AptrMap a) {return a;}

private:
	OuterClass::AptrMap m;
};
}
