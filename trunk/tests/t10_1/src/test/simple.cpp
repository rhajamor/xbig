
#include "t10_1.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   int val = 42;

   int ret = a(val);
   if (val == ret)
      std::cout << "OK\n";
   else
      std::cout << "ERROR\n";

   std::cout << "done" << std::endl;
}
