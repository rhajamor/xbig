

#include "t2_4.h"
#include <iostream>

A::A() {
	std::cout << "t2_4: A::A()" << std::endl;
}

int A::a(float& b) {
	std::cout << "t2_4: A::a(float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int& A::b(float c) {
	std::cout << "t2_4: A::b(float c)" << std::endl;
	std::cout << "c: " << c << std::endl;
	d = (int)c;
	return d;
}

int& A::c(float& d) {
	std::cout << "t2_4: A::c(float& d)" << std::endl;
	std::cout << "d: " << d << std::endl;
	return (int&)d;
}
