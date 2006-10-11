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
};

class B {};

typedef A<int> C;
typedef A<B> D;


std::ostream& operator << (std::ostream& output, B) {
	output << "B";
}

template <class T>
A<T>::A() {
	std::cout << "t7_4: A::A()" << std::endl;
}

template <class T>
T A<T>::a() {
	std::cout << "t7_4: A::a()" << std::endl;
	T x;
	std::cout << "T: " << typeid(x).name() << std::endl;
	return x;
}

template <class T>
void A<T>::b(T c) {
	std::cout << "t7_4: A::b(T c)" << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c of type: " << typeid(c).name() << std::endl;
}
