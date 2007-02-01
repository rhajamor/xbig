

#include "t3_3.h"
#include <iostream>

float B::x(int y) {
	std::cout << "t3_3: B::x(int y)" << std::endl;
	std::cout << "y: " << y << std::endl;
	return (int)y;
}
