/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles single inheritance
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
	int a(float b);

	int get();

	double attribute;

protected:
	int val;
};

}

class EXPORT B : public n::A {
public:
	B();
	float c(int d);

	void set(int val);
};
