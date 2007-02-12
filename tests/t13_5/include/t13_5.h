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


class EXPORT A {
public:
	void set(int i) {m = i;}
	int get() {return m;}
private:
	int m;
};


typedef std::map<unsigned short, A * > AptrMap;


class Tester {
public:
	void a(AptrMap a) {m = a;}
	AptrMap b() {return m;}
	AptrMap c(AptrMap a) {return a;}

private:
	AptrMap m;
};
