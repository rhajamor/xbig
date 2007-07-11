/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a typedef for a template struct
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
	typedef int BLA;
private:
	T t;
};

class EXPORT Z {
public:
	int get7() {return 7;}
};

class EXPORT A {
public:
	int get3() {return 3;}
	typedef B<Z> Y;
};

typedef B<int> C;
typedef B<A> D;

class Tester {
public:
	bool a(D a) {return a.a().get3() == 3;}
	D b() {return md;}

	void c(C a) {mc = a;}
	C d() {return mc;}

	bool x(A::Y a) {return a.a().get7() == 7;}
	A::Y z() {return y;}
private:
	D md;
	C mc;
	A::Y y;
};


/********************************************************************************************************/
template <class T>
T B<T>::a() {
	std::cout << "t7_5: B::a()" << std::endl;
	std::cout << "T: " << typeid(t).name() << std::endl;
	return t;
}

template <class T>
void B<T>::b(T c) {
	std::cout << "t7_5: B::b(T c)" << std::endl;
	std::cout << "c of type: " << typeid(c).name() << std::endl;
}
