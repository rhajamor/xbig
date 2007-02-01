
#include "t3_2.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   B b;

   std::cout << "setting public member 'z' to 4.2\n";
   b.z = 4.2;
   std::cout << "reading public member 'z'\n";
   if (b.z == 4.2)
      std::cout << "OK, z == 4.2\n";
   else
      std::cout << "ERROR: z != 4.2\n";

   std::cout << "done" << std::endl;
}
