

#include "t17.h"
#include <iostream>

void TextureUnitState::setCubicTextureName(const std::string &name, bool forUVW) {
	std::cout << "t17: TextureUnitState::setCubicTextureName(const std::string &name, bool forUVW)" << std::endl;
}

void TextureUnitState::setCubicTextureName(const std::string *const names, bool forUVW) {
	std::cout << "t17: TextureUnitState::setCubicTextureName(const std::string *const names, bool forUVW)" << std::endl;
}
