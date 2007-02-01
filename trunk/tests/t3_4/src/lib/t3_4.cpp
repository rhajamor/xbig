

#include "t3_4.h"
#include <iostream>

int B::a(float& b) {
	std::cout << "t3_4: B::a(float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int& B::b(float c) {
	std::cout << "t3_4: B::b(float c)" << std::endl;
	std::cout << "c: " << c << std::endl;
	e = (int)c;
	return e;
}

int& B::c(float& d) {
	std::cout << "t3_4: B::c(float& d)" << std::endl;
	std::cout << "d: " << d << std::endl;
	e = int(d);
	return e;
}

double t3_4_hlp = 100000.8;
B::B() : z(t3_4_hlp) {
	std::cout << "t3_4: B::B" << std::endl;
}
