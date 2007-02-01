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


class EXPORT C {
public:
	int get5() { return 5;}
};

class EXPORT Tester {
public:
	bool a(B<C> a) { return 5 == a.a().get5();}
	B<C> b() {return m;}
private:
	B<C> m;
};


/********************************************************************************************************/
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
