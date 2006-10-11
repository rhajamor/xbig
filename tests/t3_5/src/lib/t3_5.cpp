

#include "t3_5.h"
#include <iostream>

int B::a(float* b) {
	std::cout << "t3_5: B::a(float* b)" << std::endl;
	std::cout << "b: " << *b << std::endl;
	return (int)*b;
}

int* B::b(float c) {
	std::cout << "t3_5: B::b(float c)" << std::endl;
	std::cout << "c: " << c << std::endl;
	d = c;
	return (int*) &d;
}

int* B::c(float* d) {
	std::cout << "t3_5: B::c(float* d)" << std::endl;
	std::cout << "d: " << *d << std::endl;
	return (int*)d;
}
