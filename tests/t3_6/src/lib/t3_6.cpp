

#include "t3_6.h"
#include <iostream>

A::A() {
	std::cout << "t3_6: A::A()" << std::endl;
}

int A::a(float b) {
	std::cout << "t3_6: A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::b(struct B b) {
	std::cout << "t3_6: A::b(struct B b)" << std::endl;
	return 10;
}

float A::B::x(int y) {
	std::cout << "t3_6: A::B::x(float y)" << std::endl;
	std::cout << "y: " << y << std::endl;
	return (float)y;
}
