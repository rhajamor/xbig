

#include "t19.h"
#include <iostream>

bool Matrix3::Inverse (Matrix3 &rkInverse, Real fTolerance) const {
	std::cout << "t19: Matrix3::Inverse(Matrix3 &rkInverse, Real fTolerance) const" << std::endl;
	return false;
}

Matrix3 Matrix3::Inverse (Real fTolerance) const {
	std::cout << "t19: Matrix3::Inverse(Real fTolerance) const" << std::endl;
	return *this;
}
