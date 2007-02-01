
#include "t5_1.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   n::A a;
   B b;

   int c = a.a(7.3);
   if (c == 7)
      std::cout << "OK, c == 7\n";
   else
      std::cout << "ERROR: c != 7\n";

   float d = b.c(7);
   if (d == 7.0)
      std::cout << "OK, d == 7\n";
   else
      std::cout << "ERROR: d != 7\n";

   int e = b.a(7.3);
   if (e == 7)
      std::cout << "OK, e == 7\n";
   else
      std::cout << "ERROR: e != 7\n";

   std::cout << "done" << std::endl;
}
