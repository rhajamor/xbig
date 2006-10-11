/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a template struct
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#include <iostream>

template <class T>
struct EXPORT B {
	int x;
	T y;
	T a();
	void b(T c);
};

template <class T>
T B<T>::a() {
	std::cout << "t6_2: B::a()" << std::endl;
	T x;
	std::cout << "T: " << typeid(x).name() << std::endl;
	return x;
}

template <class T>
void B<T>::b(T c) {
	std::cout << "t6_2: B::b(T c)" << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c of type: " << typeid(c).name() << std::endl;
}
