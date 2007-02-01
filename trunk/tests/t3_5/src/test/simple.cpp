
#include "t3_5.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   B a;

   float f = 7.3f;
   float* g = &f;

   int b = a.a(g);
   if (b == 7)
      std::cout << "OK, b == 7\n";
   else
      std::cout << "ERROR: b != 7\n";

   int* c = a.b(f);
   int* d = a.c(g);

   if (*c == *d)
      std::cout << "OK, c == d\n";
   else
      std::cout << "ERROR: c != d\n";

   if (d == (int*)g)
      std::cout << "OK, d == g\n";
   else
      std::cout << "ERROR: d != g\n";

   double z = 3.5;
   std::cout << "setting public member 'z' to z\n";
   a.z = &z;
   std::cout << "reading public member 'z'\n";
   if (*a.z == 3.5)
      std::cout << "OK, z == z\n";
   else
      std::cout << "ERROR: z != z\n";

   std::cout << "done" << std::endl;
}
