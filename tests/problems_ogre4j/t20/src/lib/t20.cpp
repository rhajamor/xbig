

#include "t20.h"
#include <iostream>

std::pair< bool, float > Math::intersects (const Ray &ray, const std::vector< Plane > &planeList, bool normalIsOutside) {
	std::cout << "t20: Math::intersects(const Ray &ray, const std::vector< Plane > &planeList, bool normalIsOutside)" << std::endl;
	return std::pair< bool, float >();
}

std::pair< bool, float > Math::intersects (const Ray &ray, const std::list< Plane > &planeList, bool normalIsOutside) {
	std::cout << "t20: Math::intersects(const Ray &ray, const std::list< Plane > &planeList, bool normalIsOutside)" << std::endl;
	return std::pair< bool, float >();
}
