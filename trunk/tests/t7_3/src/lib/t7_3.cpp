

#include "t7_3.h"
#include <iostream>

B* b_ptr = 0;

B C::getB() {
	if (b_ptr == 0) b_ptr = new B;
	return *b_ptr;
}

C::~C() {
	if (b_ptr != 0) {
		delete b_ptr;
		b_ptr = 0;
	}
}
