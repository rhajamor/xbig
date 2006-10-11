
#include "t2_4.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   A a;

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

   std::cout << "done" << std::endl;
}
