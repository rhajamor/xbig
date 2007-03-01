

#include <iostream>
#include "t8_3.h"

int t8_3_global_help_var;

A::A() {
	std::cout << "t8_3: A::A()" << std::endl;
}

const int A::a(float& b) {
	std::cout << "t8_3: A::a(float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	b=10;
	return (int)b;
}

int const A::b(float& b) {
	std::cout << "t8_3: A::b(float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;	
	return (int)b;
}

int A::c(const float& b) {
	std::cout << "t8_3: A::c(const float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::a(float& b) const {
	std::cout << "t8_3: A::a(float& b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}
/*
const int& A::a(float b) {
	std::cout << "t8_3: A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	z = (int)b;
	return z;
}
*/
/*
int A::c(const float* b) {
	std::cout << "t8_3: A::c(const float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	z = (int)b;
	return z;
}
*/
int& A::d(float const b) {
	std::cout << "t8_3: A::d(float const b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	z = (int)b;
	return z;
}
/*
int& A::a(float b) const {
	std::cout << "t8_3: A::a(float b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	t8_3_global_help_var = (int)b;
	return t8_3_global_help_var;
}
*/
const int& A::e(float& b) {
	std::cout << "t8_3: A::e(float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	z = (int)b;
	return z;
}

int& A::g(const float& b) {
	std::cout << "t8_3: A::g(const float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	z = (int)b;
	return z;
}

int& A::e(float& b) const {
	std::cout << "t8_3: A::e(float& b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	t8_3_global_help_var = (int)b;
	return t8_3_global_help_var;
}

const int A::a(const float& b) {
	std::cout << "t8_3: A::a(const float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int const A::b(const float& b) {
	std::cout << "t8_3: A::b(const float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::c(float& b) {
	std::cout << "t8_3: A::c(float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::a(const float& b) const {
	std::cout << "t8_3: A::a(const float& b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

const int& A::e(const float& b) {
	std::cout << "t8_3: A::e(const float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	z = (int)b;
	return z;
}

int& A::g(float& b) {
	std::cout << "t8_3: A::g(float& b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	z = (int)b;
	return z;
}

int& A::e(const float& b) const {
	std::cout << "t8_3: A::e(const float& b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	t8_3_global_help_var = (int)b;
	return t8_3_global_help_var;
}

const int& A::h(float& b) const {
	std::cout << "t8_3: A::h(float& b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	t8_3_global_help_var = (int)b;
	return t8_3_global_help_var;
}

int& A::g(const float& b) const {
	std::cout << "t8_3: A::g(const float& b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	t8_3_global_help_var = (int)b;
	return t8_3_global_help_var;
}

const int& A::i(const float& b) const {
	std::cout << "t8_3: A::i(const float& b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	t8_3_global_help_var = (int)b;
	return t8_3_global_help_var;
}

B::B() {
	std::cout << "t8_3: B::B()" << std::endl;
}

const int& B::a(float b) {
	std::cout << "t8_3: B::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	z = (int)b;
	return z;
}

int& B::c(const float b) {
	std::cout << "t8_3: B::c(const float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	z = (int)b;
	return z;
}

int& B::a(float b) const {
	std::cout << "t8_3: B::a(float b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	t8_3_global_help_var = (int)b;
	return t8_3_global_help_var;
}
