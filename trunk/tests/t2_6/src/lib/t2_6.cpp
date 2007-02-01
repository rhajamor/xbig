

#include "t2_6.h"
#include <iostream>

A::A() {
	std::cout << "t2_6: A::A()" << std::endl;
}

int A::a(float b) {
	std::cout << "t2_6: A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

A::B::B() {
	std::cout << "t2_6: A::B::B()" << std::endl;
}

float A::B::x(int y) {
	std::cout << "t2_6: A::B::x(float y)" << std::endl;
	std::cout << "y: " << y << std::endl;
	return (float)y;
}
