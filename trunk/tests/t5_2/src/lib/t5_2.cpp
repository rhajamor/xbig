

#include "t5_2.h"
#include <iostream>

A::A() {
	std::cout << "t5_2: A::A()" << std::endl;
}

int A::a(float b) {
	std::cout << "t5_2: A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

B::B() {
	std::cout << "t5_2: B::B()" << std::endl;
}

float B::c(int d) {
	std::cout << "t5_2: B::c(float d)" << std::endl;
	std::cout << "d: " << d << std::endl;
	return (float)d;
}

C::C() {
	std::cout << "t5_2: C::C()" << std::endl;
}

double C::e(long f) {
	std::cout << "t5_2: C::e(long f)" << std::endl;
	std::cout << "f: " << f << std::endl;
	return (double)f;
}
