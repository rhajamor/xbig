

#include "t08.h"
#include <iostream>

Root::Root(const String& pluginFileName, const String& configFileName, const String& logFileName) {
	std::cout << "t08: Root::Root(const String& pluginFileName, const String& configFileName, const String& logFileName)" << std::endl;
}

Root::~Root() {
	std::cout << "t08: Root::~Root()" << std::endl;
}

void Root::saveConfig(void) {
	std::cout << "t08: Root::saveConfig()" << std::endl;
}
