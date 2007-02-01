

#include "t01.h"
#include <iostream>

StringVector t01_global_helper;

const StringVector& AnimableObject::getAnimableValueNames(void) const {
	std::cout << "t01: AnimableObject::getAnimableValueNames(void) const()" << std::endl;
	return t01_global_helper;
}
