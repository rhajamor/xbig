

#include "t3_9.h"
#include <iostream>

float n::B::x(int y) {
	std::cout << "t3_9: A::B::x(float y)" << std::endl;
	std::cout << "y: " << y << std::endl;
	return (float)y;
}
