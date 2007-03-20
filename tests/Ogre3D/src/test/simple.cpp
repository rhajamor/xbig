
#include "Ogre.h"
#include <iostream>

#define CHECK(test) \
   if(test) { std::cout << #test << " OK" << std::endl; } \
   else { std::cout << #test << " failed" << std::endl; }


int main(int argc, char* argv[]) 
{
   CHECK(1);
	//TODO c test
}
