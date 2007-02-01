

#include "t8_1.h"
#include <iostream>

A::A() {
	std::cout << "t8_1: A::A()" << std::endl;
}

const int A::a(float b) {
	std::cout << "t8_1: A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int const A::b(float b) {
	std::cout << "t8_1: A::b(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::c(const float b) {
	std::cout << "t8_1: A::c(const float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::d(float const b) {
	std::cout << "t8_1: A::d(float const b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::a(float b) const {
	std::cout << "t8_1: A::a(float b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return ((int)b) * 2;
}

void A::e() const {
	std::cout << "t8_1: A::e() const" << std::endl;
}
