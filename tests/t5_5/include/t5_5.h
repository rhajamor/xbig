/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles an inheritance tree with three levels,
 * an indirect abstract class (not implemented pure virtual method)
 * and a method that is overridden in more classes
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

class EXPORT A {
public:
	virtual void a() =0;
	virtual void b();
	virtual void c() =0;
};

class EXPORT B : public A {
public:
	virtual void b();
	virtual void c();
};

class EXPORT C : public B {
public:
	virtual void a();
	virtual void b();
};
