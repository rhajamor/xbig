
#include "t7_2.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   B a;

   if (a.get5() == 5)
      std::cout << "OK\n";
   else
      std::cout << "ERROR";

   std::cout << "done" << std::endl;
}
