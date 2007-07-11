

#include "t23.h"
#include <iostream>

Vector::Vector(int x, int y, int z) {
	std::cout << "t23: Vector::Vector(int x, int y, int z)" << std::endl;
	i[0] = x;
	i[1] = y;
	i[2] = z;
}

Vector::Vector(const Vector& rhs) {
	std::cout << "t23: Vector::Vector(const Vector&)" << std::endl;
	i[0] = rhs.i[0];
	i[1] = rhs.i[1];
	i[2] = rhs.i[2];
}

Vector::~Vector() {
	std::cout << "t23: Vector::~Vector()" << std::endl;
}

Vector Vector::operator+(const Vector& rkVector) const {
	std::cout << "t23: Vector::operator+(const Vector& rkVector) const" << std::endl;
	Vector v(i[0] + rkVector.i[0], i[1] + rkVector.i[1], i[2] + rkVector.i[2]);
	return v;
}

Vector Vector::operator-(const Vector& rkVector) const {
	std::cout << "t23: Vector::operator-(const Vector& rkVector) const" << std::endl;
	Vector v(i[0] - rkVector.i[0], i[1] - rkVector.i[1], i[2] - rkVector.i[2]);
	return v;
}

Vector Vector::operator*(const Vector& rkVector) const {
	std::cout << "t23: Vector::operator*(const Vector& rkVector) const" << std::endl;
	Vector v(i[0] * rkVector.i[0], i[1] * rkVector.i[1], i[2] * rkVector.i[2]);
	return v;
}

Vector Vector::operator/(const Vector& rkVector) const {
	std::cout << "t23: Vector::operator/(const Vector& rkVector) const" << std::endl;
	Vector v(i[0] / rkVector.i[0], i[1] / rkVector.i[1], i[2] / rkVector.i[2]);
	return v;
}

const Vector Vector::operator+() const {
	std::cout << "t23: Vector::operator+() const" << std::endl;
	Vector v(+i[0], +i[1], +i[2]);
	return v;
}

const Vector Vector::operator-() const {
	std::cout << "t23: Vector::operator-() const" << std::endl;
	Vector v(-i[0], -i[1], -i[2]);
	return v;
}

const Vector& Vector::operator++() {
	std::cout << "t23: Vector::operator++()" << std::endl;
	++i[0];
	++i[1];
	++i[2];
	return *this;
}

const Vector Vector::operator++(int) {
	std::cout << "t23: Vector::operator++(int)" << std::endl;
	Vector v = *this;
	++i[0];
	++i[1];
	++i[2];
	return v;
}

int Vector::operator[](unsigned index) {
	std::cout << "t23: Vector::operator[](unsigned index)" << std::endl;
	if(index < 3)
		return i[index];
	else
		return -1;
}

int Vector::operator[](unsigned index) const {
	std::cout << "t23: Vector::operator[](unsigned index)" << std::endl;
	if(index < 3)
		return i[index];
	else
		return -1;
}

void Vector::operator-> () const {
}
