

#include "t5_6.h"
#include <iostream>

A::uint A::b() {
	std::cout << "t5_6: A::b()" << std::endl;
	return 2;
}

A::uint B::b() {
	std::cout << "t5_6: B::b()" << std::endl;
	return 2;
}

A::ulong B::c() {
	std::cout << "t5_6: B::c()" << std::endl;
	return 3;
}

A::ushort C::a() {
	std::cout << "t5_6: C::a()" << std::endl;
	return 1;
}

A::uint C::b() {
	std::cout << "t5_6: C::b()" << std::endl;
	return 2;
}
