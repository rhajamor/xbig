/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a single inheritance
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
	int a(float b);

	int get();

protected:
	int val;
};

class EXPORT B : public A {
public:
	B();
	float c(int d);

	void set(int val);
};
