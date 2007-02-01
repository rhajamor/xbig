

#include "t5_4.h"
#include <iostream>

void A::notAbstract() {
	std::cout << "t5_4: A::notAbstract()" << std::endl;
}

void C::abstractA() {
	std::cout << "t5_4: C::abstractA()" << std::endl;
}

void D::abstractA() {
	std::cout << "t5_4: D::abstractA()" << std::endl;
}

void D::abstractB() {
	std::cout << "t5_4: D::abstractB()" << std::endl;
}
