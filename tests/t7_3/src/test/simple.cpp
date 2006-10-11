
#include "t7_3.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   A b;

   std::cout << "setting public member 'z' to 4.2\n";
   b.z = 4.2;
   std::cout << "reading public member 'z'\n";
   if (b.z == 4.2)
      std::cout << "OK, z == 4.2\n";
   else
      std::cout << "ERROR: z != 4.2\n";

   float c = b.x(7);
   if (c == 7.0)
      std::cout << "OK, c == 7\n";
   else
      std::cout << "ERROR: c != 7\n";

   std::cout << "done" << std::endl;
}
