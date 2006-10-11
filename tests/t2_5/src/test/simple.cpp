
#include "t2_5.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   A a;

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

   std::cout << "done" << std::endl;
}
