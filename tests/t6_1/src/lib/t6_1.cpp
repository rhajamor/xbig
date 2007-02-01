

#include "t6_1.h"

Tester::Tester() {
	std::cout << "t6_1: Tester::Tester()" << std::endl;
}

bool Tester::a(A<C> a) {
	std::cout << "t6_1: Tester::a(A<C>)" << std::endl;
	return 5 == a.a().get5();
}

A<C> Tester::b() {
	std::cout << "t6_1: Tester::b()" << std::endl;
	return m;
}

Tester::~Tester() {
	std::cout << "t6_1: Tester::~Tester()" << std::endl;
}
