

#include "t02.h"
#include <iostream>

Radian t02_global_helper;

void Particle::setRotation (const Radian &rad) {
	std::cout << "t02: Particle::setRotation (const Radian &rad)" << std::endl;
}

const Radian & Particle::getRotation (void) const {
	std::cout << "t02: Particle::getRotation (void) const" << std::endl;
	return t02_global_helper;
}
