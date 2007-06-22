
#include "t23.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   Vector a(1, 2, 3), b(4, 5, 6);
   Vector c = a + b;

   if (c[0] == 5 && c[1] == 7 && c[2] == 9)
   	 std::cout << "right" << std::endl;
   else
   	 std::cout << "wrong" << std::endl;

   std::cout << "done" << std::endl;
}
