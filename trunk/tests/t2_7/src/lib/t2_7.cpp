

#include "t2_7.h"
#include <iostream>

int A::b;

int A::a(float b) {
	std::cout << "t2_7: A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}
