

#include "t4_2.h"
#include <iostream>

n::m::A::A() {
	std::cout << "t4_2: n::m::A::A()" << std::endl;
}

int n::m::A::a(float b) {
	std::cout << "t4_2: n::m::A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}
