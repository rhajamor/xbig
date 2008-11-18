/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a template class with two parameters
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#include <iostream>
#include <typeinfo>

template <class T, typename U>
class EXPORT A {
public:
	A();
	T a();
	void b(U c);
	U c(T a);
	~A();
private:
	T t;
	U u;
};


class EXPORT C {
public:
	int get5() { return 5;}
};
class EXPORT D {
public:
	int get6() { return 6;}
};

class EXPORT Tester {
public:
	bool a(A< C, D > a) {return (5 == a.a().get5()) && (a.c(a.a()).get6() == 6);}
	A< C, D > b() {return m;}
private:
	A< C, D > m;
};


/********************************************************************************************************/

template <class T, class U>
A<T, U>::A() {
	std::cout << "t6_3: A::A()" << std::endl;
}

template <class T, class U>
T A<T, U>::a() {
	std::cout << "t6_3: A::a()" << std::endl;
	std::cout << "T: " << typeid(t).name() << std::endl;
	return t;
}

template <class T, typename U>
void A<T, U>::b(U c) {
	std::cout << "t6_3: A::b(T c)" << std::endl;
	std::cout << "c of type: " << typeid(c).name() << std::endl;
}

template <class T, class U>
U A<T, U>::c(T a) {
	std::cout << "t6_3: A::c(T a)" << std::endl;
	std::cout << "a of type: " << typeid(a).name() << std::endl;
	std::cout << "U: " << typeid(u).name() << std::endl;
	return u;
}

template <class T, class U>
A<T, U>::~A() {
	std::cout << "t6_3: A::~A()" << std::endl;
}
