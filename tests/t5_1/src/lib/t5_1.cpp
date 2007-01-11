

#include "t5_1.h"
#include <iostream>

n::A::A() {
	std::cout << "t5_1: n::A::A()" << std::endl;
}

int n::A::a(float b) {
	std::cout << "t5_1: n::A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int n::A::get() {
	std::cout << "t5_1: n::A::get()" << std::endl;
	return val;
}

B::B() {
	std::cout << "t5_1: B::B()" << std::endl;
}

float B::c(int d) {
	std::cout << "t5_1: B::c(float d)" << std::endl;
	std::cout << "d: " << d << std::endl;
	return (float)d;
}

void B::set(int val) {
	std::cout << "t5_1: A::set(int val)" << std::endl;
	std::cout << "val: " << val << std::endl;
	this->val = val;
}
