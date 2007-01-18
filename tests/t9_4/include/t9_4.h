/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles enums with different names in different namespaces
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

class EXPORT Vocals1 {
public:
	int get5() {return 5;}
};

class EXPORT A {
public:
	enum EXPORT Vocals2 {
		a = 201,
		e = 202,
		i = 203,
		o = 204,
		u = 205
	};
};

struct EXPORT B {
	enum EXPORT Vocals3 {
		a = 301,
		e = 302,
		i = 303,
		o = 304,
		u = 305
	};
};

namespace n {
	enum EXPORT Vocals1 {
		a = 101,
		e = 102,
		i = 103,
		o = 104,
		u = 105
	};

	class EXPORT Tester {
	public:
		bool isN(Vocals1 a);
		bool isA(A::Vocals2 a);
		bool isB(B::Vocals3 a);
		bool isObject(::Vocals1 a);
	};
}

class EXPORT Tester {
public:
	bool isN(n::Vocals1 a);
	bool isA(A::Vocals2 a);
	bool isB(B::Vocals3 a);
	bool isObject(Vocals1 a);
};
