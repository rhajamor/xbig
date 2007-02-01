
#include "t13.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   Root a;

   a.getSingleton();
   a.getSingletonPtr();

   std::cout << "done" << std::endl;
}
