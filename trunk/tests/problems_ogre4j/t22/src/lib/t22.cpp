

#include "t22.h"
#include <iostream>

String t22_global_helper = "A";

const String& RenderSystemA::getName() const {
	std::cout << "t22: RenderSystemA::getName() const" << std::endl;
	return t22_global_helper;
}
