

#include <iostream>
#include "t8_4.h"

int t8_4_global_helper;

A::A() {
	std::cout << "t8_4: A::A()" << std::endl;
}

const int A::a(float* b) {
	std::cout << "t8_4: A::a(float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int const A::b(float* b) {
	std::cout << "t8_4: A::b(float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::c(const float* b) {
	std::cout << "t8_4: A::c(const float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::a(float* b) const {
	std::cout << "t8_4: A::a(float* b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

const int* A::a(float b) {
	std::cout << "t8_4: A::a(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	helper = (int)b;
	return &helper;
}

int* A::c(const float b) {
	std::cout << "t8_4: A::c(const float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	helper = (int)b;
	return &helper;
}

int* A::d(float const b) {
	std::cout << "t8_4: A::d(float const b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	helper = (int)b;
	return &helper;
}

int* A::a(float b) const {
	std::cout << "t8_4: A::a(float b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	t8_4_global_helper = (int)b;
	return &t8_4_global_helper;
}

const int* A::e(float* b) {
	std::cout << "t8_4: A::e(float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}

int* A::g(const float* b) {
	std::cout << "t8_4: A::g(const float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}

int* A::e(float* b) const {
	std::cout << "t8_4: A::e(float* b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}

const int A::a(const float* b) {
	std::cout << "t8_4: A::a(const float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int const A::b(const float* b) {
	std::cout << "t8_4: A::b(const float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::c(float* b) {
	std::cout << "t8_4: A::c(float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

int A::a(const float* b) const {
	std::cout << "t8_4: A::a(const float* b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int)b;
}

const int* A::e(const float* b) {
	std::cout << "t8_4: A::e(const float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}

int* A::g(float* b) {
	std::cout << "t8_4: A::g(float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}

int* A::e(const float* b) const {
	std::cout << "t8_4: A::e(const float* b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}

const int* A::h(float* b) const {
	std::cout << "t8_4: A::h(float* b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}

int* A::g(const float* b) const {
	std::cout << "t8_4: A::g(const float* b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}

const int* A::i(const float* b) const {
	std::cout << "t8_4: A::i(const float* b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}

int* const A::z(float* b) {
	std::cout << "t8_4: A::z(float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
int* A::y(float* const b) {
	std::cout << "t8_4: A::y(float* const b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
int* const A::x(float* const b) {
	std::cout << "t8_4: A::x(float* const b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
int* const A::z(float* b) const {
	std::cout << "t8_4: A::z(float* b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
int* A::y(float* const b) const {
	std::cout << "t8_4: A::y(float* const b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
int* const A::x(float* const b) const {
	std::cout << "t8_4: A::x(float* const b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
int* A::g(float* const b) const {
	std::cout << "t8_4: A::g(float* const b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
const int* A::i(float* const b) const {
	std::cout << "t8_4: A::i(float* const b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
const int* const A::w(float* b) {
	std::cout << "t8_4: A::w(float* b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
int* A::y(const float* const b) {
	std::cout << "t8_4: A::y(const float* const b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
const int* const A::x(const float* const b) {
	std::cout << "t8_4: A::x(const float* const b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
const int* const A::w(float* b) const {
	std::cout << "t8_4: A::w(float* b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
int* A::y(const float* const b) const {
	std::cout << "t8_4: A::y(const float* const b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
const int* const A::x(const float* const b) const {
	std::cout << "t8_4: A::x(const float* const b) const" << std::endl;
	std::cout << "b: " << b << std::endl;
	return (int*)b;
}
