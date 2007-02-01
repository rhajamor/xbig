

#include "t2_8.h"
#include <iostream>

B global;

int B::get1() {
	return 1;
}

A::A() : b_ref(global) {
}

void A::a(B* b) {
	std::cout << "t2_8: A::a(B*)" << std::endl;
	b_ptr = b;
}

B* A::b() {
	std::cout << "t2_8: A::b()" << std::endl;
	return b_ptr;
}

bool A::c(B& b) {
	std::cout << "t2_8: A::c(B&)" << std::endl;
	return b.get1() == 1;
}

B& A::d() {
	std::cout << "t2_8: A::d()" << std::endl;
	return b_ref;
}
