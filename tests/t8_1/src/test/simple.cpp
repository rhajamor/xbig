
#include "t8_1.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   A a;

   float g = 7.3;
   int b = a.a(g);
   if (b == 7)
      std::cout << "OK, b == 7\n";
   else
      std::cout << "ERROR: b != 7\n";

   int c = a.b(7.3);
   if (c == 7)
      std::cout << "OK, c == 7\n";
   else
      std::cout << "ERROR: c != 7\n";

   int d = a.c(7.3);
   if (d == 7)
      std::cout << "OK, d == 7\n";
   else
      std::cout << "ERROR: d != 7\n";

   int e = a.d(7.3);
   if (e == 7)
      std::cout << "OK, e == 7\n";
   else
      std::cout << "ERROR: e != 7\n";

   const A h;
   int f = h.a(7.3);
   if (f == 7)
      std::cout << "OK, f == 7\n";
   else
      std::cout << "ERROR: f != 7\n";

   std::cout << "done" << std::endl;
}
