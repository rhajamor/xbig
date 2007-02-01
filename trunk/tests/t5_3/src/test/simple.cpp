
#include "t5_3.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   B b;

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

   A* ptr_a = &b;
   ptr_a->b();
   int c = ptr_a->a(7.3);
   if (c == 7)
      std::cout << "OK, c == 7\n";
   else
      std::cout << "ERROR: c != 7\n";

   std::cout << "done" << std::endl;
}
