

#include "t5_1.h"
#include <iostream>

A::A() {
	std::cout << "t5_1: A::A()" << std::endl;
}

int A::a(float b) {
	std::cout << "t5_1: A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

B::B() {
	std::cout << "t5_1: B::B()" << std::endl;
}

float B::c(int d) {
	std::cout << "t5_1: B::c(float d)" << std::endl;
	std::cout << "d: " << d << std::endl;
	return (float)d;
}
