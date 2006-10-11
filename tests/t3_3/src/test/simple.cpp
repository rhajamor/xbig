
#include "t3_3.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   B b;

   float c = b.x(7);
   if (c == 7.0)
      std::cout << "OK, c == 7\n";
   else
      std::cout << "ERROR: c != 7\n";

   std::cout << "done" << std::endl;
}
