
#include "t8_3.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   A a;
   const A b;

   float c = 7.3;
   const float d = 7.3;

   float& e = c;
   const float& f = d;

   B g;
   const B h;

   a.a(e);
   a.b(e);
   a.c(f);
   b.a(e);

   g.a(c);
   g.c(d);
   a.d(d);
   h.a(c);

   a.e(c);
   a.g(d);
   b.e(c);

   a.a(f);
   a.b(f);
   a.c(e);
   b.a(f);

   a.e(f);
   a.g(e);
   b.e(f);

   b.h(e);
   b.g(f);

   b.i(f);

   std::cout << "done" << std::endl;
}
