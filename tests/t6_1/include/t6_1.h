/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a template class
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#include <iostream>

template <class T>
class EXPORT A {
public:
	A();
	T a();
	void b(T c);
	T c(T a);
	~A();
private:
	T t;
};

class EXPORT C {
public:
	int get5() { return 5;}
	C(){std::cout << "t6_1: C::C()" << std::endl;}
	C(const C& c){std::cout << "t6_1: C::C(const C&)" << std::endl;}
	~C(){std::cout << "t6_1: C::~C()" << std::endl;}
};

class EXPORT Tester {
public:
	Tester();
	bool a(A<C> a);
	A<C> b();
	~Tester();
private:
	A<C> m;
};


/********************************************************************************************************/
template <class T>
A<T>::A() {
	std::cout << "t6_1: A::A()" << std::endl;
}

template <class T>
T A<T>::a() {
	std::cout << "t6_1: A::a()" << std::endl;
	std::cout << "T is of type: " << typeid(t).name() << std::endl;
	return t;
}

template <class T>
void A<T>::b(T c) {
	std::cout << "t6_1: A::b(T c)" << std::endl;
	std::cout << "c of type: " << typeid(c).name() << std::endl;
}

template <class T>
T A<T>::c(T a) {
	std::cout << "t6_1: A::c(T a)" << std::endl;
	std::cout << "a of type: " << typeid(a).name() << std::endl;
	return a;
}

template <class T>
A<T>::~A() {
	std::cout << "t6_1: A::~A()" << std::endl;
}
