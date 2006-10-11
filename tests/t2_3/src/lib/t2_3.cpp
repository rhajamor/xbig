

#include "t2_3.h"
#include <iostream>

A::A() {
	std::cout << "t2_3: A::A()" << std::endl;
}

int A::a(float b) {
	std::cout << "t2_3: A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}
