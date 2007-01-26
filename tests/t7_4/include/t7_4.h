/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a typedef for a template class
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
private:
	T t;
};

class B {
public:
	int get3() {return 3;}
};

//typedef A<int> C;
typedef A<B> D;


class Tester {
public:
	bool a(D a) {return a.a().get3() == 3;}
	D b() {return d;}
private:
	D d;
};


/********************************************************************************************************/
template <class T>
A<T>::A() {
	std::cout << "t7_4: A::A()" << std::endl;
}

template <class T>
T A<T>::a() {
	std::cout << "t7_4: A::a()" << std::endl;
	std::cout << "T: " << typeid(t).name() << std::endl;
	return t;
}

template <class T>
void A<T>::b(T c) {
	std::cout << "t7_4: A::b(T c)" << std::endl;
	std::cout << "c of type: " << typeid(c).name() << std::endl;
}
