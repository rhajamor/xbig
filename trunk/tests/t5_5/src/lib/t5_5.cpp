

#include "t5_5.h"
#include <iostream>

void A::b() {
	std::cout << "t5_5: A::b()" << std::endl;
}

void B::b() {
	std::cout << "t5_5: B::b()" << std::endl;
}

void B::c() {
	std::cout << "t5_5: B::c()" << std::endl;
}

void C::a() {
	std::cout << "t5_5: C::a()" << std::endl;
}

void C::b() {
	std::cout << "t5_5: C::b()" << std::endl;
}
