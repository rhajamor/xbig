

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

float A::B::x(int y) {
	std::cout << "t3_6: A::B::x(float y)" << std::endl;
	std::cout << "y: " << y << std::endl;
	return (float)y;
}
