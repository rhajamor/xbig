

#include "t8_2.h"
#include <iostream>

A::A() {
	std::cout << "t8_2: A::A()" << std::endl;
}

const int A::a(float b) {
	std::cout << "t8_2: A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int const A::b(float b) {
	std::cout << "t8_2: A::b(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::c(const float b) {
	std::cout << "t8_2: A::c(const float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::d(float const b) {
	std::cout << "t8_2: A::d(float const b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::a(float b) const {
	std::cout << "t8_2: A::a(float b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int const A::b(float b) const {
	std::cout << "t8_2: A::b(float b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::c(const float b) const {
	std::cout << "t8_2: A::c(const float b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::d(float const b) const {
	std::cout << "t8_2: A::d(float const b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

const int A::e(float b) const {
	std::cout << "t8_2: A::e(float b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

const int A::f(const float b) const {
	std::cout << "t8_2: A::f(const float b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

const int A::g(float const b) const {
	std::cout << "t8_2: A::g(float const b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int const A::h(const float b) const {
	std::cout << "t8_2: A::h(const float b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int const A::i(float const b) const {
	std::cout << "t8_2: A::i(float const b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}
