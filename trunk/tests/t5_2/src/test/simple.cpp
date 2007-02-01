
#include "t5_2.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   A a;
   B b;
   C c;

   int f = a.a(7.3);
   if (f == 7)
      std::cout << "OK, f == 7\n";
   else
      std::cout << "ERROR: f != 7\n";

   float d = b.c(7);
   if (d == 7.0)
      std::cout << "OK, d == 7\n";
   else
      std::cout << "ERROR: d != 7\n";

   double g = c.e(123456);
   if (g == 123456.0)
      std::cout << "OK, g == 123456\n";
   else
      std::cout << "ERROR: g != 123456\n";

   int e = c.a(7.3);
   if (e == 7)
      std::cout << "OK, e == 7\n";
   else
      std::cout << "ERROR: e != 7\n";

   float h = c.c(7);
   if (h == 7.0)
      std::cout << "OK, h == 7\n";
   else
      std::cout << "ERROR: h != 7\n";

   std::cout << "done" << std::endl;
}
