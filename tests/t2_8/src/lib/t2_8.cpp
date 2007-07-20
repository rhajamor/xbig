

#include "t2_8.h"
#include <iostream>

B::B() {
	std::cout << "t2_8: B::B(), adress: " << long(this) << std::endl;
}

B::B(const B& rhs) {
	std::cout << "t2_8: B::B(const B&), adress: " << long(this) << std::endl;
	i = rhs.i;
}

B::~B() {
	std::cout << "t2_8: B::~B(), adress: " << long(this) 
			  << ", value: " << i << std::endl;
}

int B::get1() {
	return 1;
}

int B::geti() {
	return i;
}

void B::seti(int i) {
	this->i = i;
}

A::A() : b_ref(b_val) {
	b_ptr = &b_val;
	b_val.seti(0);
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

B A::e() {
	std::cout << "t2_8: A::e()" << std::endl;
	return b_val;
}

void A::f(B para) {
	std::cout << "t2_8: A::f(B)" << std::endl;
	b_val = para;
}

B A::g(B para) {
	std::cout << "t2_8: A::g(B)" << std::endl;
	b_val = para;
	return b_val;
}

B A::h;
