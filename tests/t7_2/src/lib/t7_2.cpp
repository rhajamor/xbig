

#include "t7_2.h"
#include <iostream>

A::A() {
	std::cout << "t7_2: A::A()" << std::endl;
}

int A::a(float b) {
	std::cout << "t7_2: A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}
