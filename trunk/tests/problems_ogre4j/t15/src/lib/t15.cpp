

#include "t15.h"
#include <iostream>

void Matrix3::EigenSolveSymmetric(float afEigenvalue[3], Vector3 akEigenvector[3]) const {
	std::cout << "t2_1: Matrix3::EigenSolveSymmetric(float afEigenvalue[3], Vector3 akEigenvector[3]) const" << std::endl;
	std::cout << "afEigenvalue:" << std::endl;
	for (int i=0; i<3; ++i) {
		std::cout << afEigenvalue[i] << " ";
	}
	std::cout << "\nakEigenvector:" << std::endl;
	for (int i=0; i<3; ++i) {
		std::cout << typeid(akEigenvector[i]).name() << " ";
	}
	std::cout << std::endl;
}
