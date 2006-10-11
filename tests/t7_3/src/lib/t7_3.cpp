

#include "t7_3.h"
#include <iostream>

float B::x(int y) {
	std::cout << "t7_3: B::x(int y)" << std::endl;
	std::cout << "y: " << y << std::endl;
	return (int)y;
}
