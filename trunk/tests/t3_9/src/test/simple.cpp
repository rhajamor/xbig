
#include "t3_9.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   n::B b;

   float d = b.x(7);
   if (d == 7.0)
      std::cout << "OK, d == 7\n";
   else
      std::cout << "ERROR: d != 7\n";

   double z = 3.5;
   std::cout << "setting public member 'z' to z\n";
   b.z = z;
   std::cout << "reading public member 'z'\n";
   if (b.z == 3.5)
      std::cout << "OK, z == z\n";
   else
      std::cout << "ERROR: z != z\n";

   std::cout << "done" << std::endl;
}
