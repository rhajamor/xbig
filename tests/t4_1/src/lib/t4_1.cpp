

#include "t4_1.h"
#include <iostream>

n::A::A() {
	std::cout << "t4_1: n::A::A()" << std::endl;
}

int n::A::a(float b) {
	std::cout << "t2_3: n::A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}
