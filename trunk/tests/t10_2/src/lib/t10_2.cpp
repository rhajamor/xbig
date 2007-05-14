

#include "t10_2.h"
#include <iostream>

void a(int b) {
	std::cout << "t10_2: a(int b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
int a(void) {
	std::cout << "t10_2: a(void)" << std::endl;
	return 4000000;
}
void b(unsigned b) {
	std::cout << "t10_2: b(unsigned b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
unsigned b(void) {
	std::cout << "t10_2: b(void)" << std::endl;
	return 4000000;
}
void c(signed b) {
	std::cout << "t10_2: c(signed b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
signed c(void) {
	std::cout << "t10_2: c(void)" << std::endl;
	return -4000000;
}
void d(unsigned int b) {
	std::cout << "t10_2: d(unsigned int b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
unsigned int d(void) {
	std::cout << "t10_2: d(void)" << std::endl;
	return 4000000;
}
void e(signed int b) {
	std::cout << "t10_2: e(signed int b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
signed int e(void) {
	std::cout << "t10_2: int e(void)" << std::endl;
	return -4000000;
}

void f(short b) {
	std::cout << "t10_2: f(short b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
short f(void) {
	std::cout << "t10_2: f(void)" << std::endl;
	return 32000;
}
void g(unsigned short b) {
	std::cout << "t10_2: g(unsigned short b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
unsigned short g(void) {
	std::cout << "t10_2: g(void)" << std::endl;
	return 64000;
}
void h(signed short b) {
	std::cout << "t10_2: h(signed short b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
signed short h(void) {
	std::cout << "t10_2: h(void)" << std::endl;
	return -32000;
}

void i(long b) {
	std::cout << "t10_2: i(long b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
long i(void) {
	std::cout << "t10_2: i(void)" << std::endl;
	return 5000000;
}
void j(unsigned long b) {
	std::cout << "t10_2: j(unsigned long b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
unsigned long j(void) {
	std::cout << "t10_2: j(void))" << std::endl;
	return 5000000;
}
void k(signed long b) {
	std::cout << "t10_2: k(signed long b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
signed long k(void) {
	std::cout << "t10_2: k(void)" << std::endl;
	return -5000000;
}

void l(char b) {
	std::cout << "t10_2: l(char b)" << std::endl;
	std::cout << "b: " << (short)b << std::endl;
}
char l(void) {
	std::cout << "t10_2: l(void)" << std::endl;
	return 127;
}
void m(unsigned char b) {
	std::cout << "t10_2: m(unsigned char b)" << std::endl;
	std::cout << "b: " << (unsigned short)b << std::endl;
}
unsigned char m(void) {
	std::cout << "t10_2: m(void)" << std::endl;
	return 255;
}
void n(signed char b) {
	std::cout << "t10_2: n(signed char b)" << std::endl;
	std::cout << "b: " << (signed short)b << std::endl;
}
signed char n(void) {
	std::cout << "t10_2: n(void)" << std::endl;
	return -128;
}

void o(float b) {
	std::cout << "t10_2: o(float b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
float o(void) {
	std::cout << "t10_2: o(void)" << std::endl;
	return 7.3;
}

void p(double b) {
	std::cout << "t10_2: p(double b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
double p(void) {
	std::cout << "t10_2: p(void)" << std::endl;
	return 8.261e-65;
}

/*
 * the data type long double is not supported
void q(long double b) {
	std::cout << "t10_2: q(long double b)" << std::endl;
	std::cout << "b: " << b << std::endl;
}
long double q(void) {
	std::cout << "t10_2: q(void)" << std::endl;
	return -4.387e83;
}*/

void r(void) {
	std::cout << "t10_2: r(void)" << std::endl;
}
void s() {
	std::cout << "t10_2: s()" << std::endl;
}

A::A() {
	std::cout << "t10_2: A::A()" << std::endl;
}

void t(A b) {
	std::cout << "t10_2: s(A b)" << std::endl;
}
A t(void) {
	std::cout << "t10_2: s(void)" << std::endl;
	A a;
	return a;
}

/*the array is not handled correctly
void u(int b[]) {
	std::cout << "t10_2: s(A b)" << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;
}*/
int t10_2_global_helper[5] = {1, 2, 3, 4, 5};
int* u(void) {
	std::cout << "t10_2: s(A b)" << std::endl;
	return t10_2_global_helper;
}
