/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles inherited inner types
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

class EXPORT A {	
public:
	typedef unsigned short ushort;
	typedef unsigned int uint;	
	typedef unsigned long ulong;
	virtual ushort a() =0;
	virtual uint b();
	virtual ulong c() =0;
};

class EXPORT B : public A {
public:
	virtual uint b();
	virtual ulong c();
};

class EXPORT C : public B {
public:
	virtual ushort a();
	virtual uint b();
};
