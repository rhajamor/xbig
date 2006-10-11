
#include "t3_4.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   B a;

   float f = 7.3f;
   float& g = f;

   int b = a.a(g);
   if (b == 7)
      std::cout << "OK, b == 7\n";
   else
      std::cout << "ERROR: b != 7\n";

   int& c = a.b(f);
   if (c == 7)
      std::cout << "OK, c == 7\n";
   else
      std::cout << "ERROR: c != 7\n";

   int& d = a.c(g);
   if (d == 7)
      std::cout << "OK, d == 7\n";
   else
      std::cout << "ERROR: d != 7\n";

   std::cout << "setting public member 'z' to 4.2\n";
   a.z = 4.2;
   std::cout << "reading public member 'z'\n";
   if (a.z == 4.2)
      std::cout << "OK, z == 4.2\n";
   else
      std::cout << "ERROR: z != 4.2\n";

   std::cout << "done" << std::endl;
}
