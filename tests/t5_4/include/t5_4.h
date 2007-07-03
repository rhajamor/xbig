/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles multiple inheritance with one base class
 * 
 * NOTE:
 * If non-virtual inheritance is used we should let the library
 * user decide which ambigous method to use. Here it is:
 * A::notAbstract()
 * uncomment '#define USE_VIRTUAL_INHERITANCE' to test it
 * 
 * NOTE 2:
 * We cannot use the method name 'abstract' as in the
 * documenting diagramms, because it is a keyword in java
 * 
 * NOTE 3:
 * It would be a problem if class B and C would have a method
 * with the same name
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#define USE_VIRTUAL_INHERITANCE

#ifdef USE_VIRTUAL_INHERITANCE
	#define VIRT virtual 
#else
	#define VIRT
#endif

class EXPORT A {
public:
	virtual void abstractA() =0;
	virtual void notAbstract();
};

class EXPORT B : VIRT public A {
public:
	virtual void abstractB() =0;
};

class EXPORT C : VIRT public A {
public:
	virtual void abstractA();
};

class EXPORT D : VIRT public B, VIRT public C {
public:
	virtual void abstractA();
	virtual void abstractB();
};

class EXPORT E {
private:
	virtual void abstractE() = 0;
};
