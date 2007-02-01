
#include "t4_1.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   n::A a;

   int b = a.a(7.3);
   if (b == 7)
      std::cout << "OK, b == 7\n";
   else
      std::cout << "ERROR: b != 7\n";

   std::cout << "done" << std::endl;
}
