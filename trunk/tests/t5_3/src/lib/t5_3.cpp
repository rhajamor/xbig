

#include "t5_3.h"
#include <iostream>

A::A() {
	std::cout << "t5_3: A::A()" << std::endl;
}

void A::b() {
	std::cout << "t5_3: A::b()" << std::endl;
}

B::B() {
	std::cout << "t5_3: B::B()" << std::endl;
}

int B::a(float b) {
	std::cout << "t5_3: B::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

float B::c(int d) {
	std::cout << "t5_3: B::c(float d)" << std::endl;
	std::cout << "d: " << d << std::endl;
	return (float)d;
}

A* B::getA(){ 
	std::cout << "t5_3: B::getA()" << std::endl;
	return this; 
}
