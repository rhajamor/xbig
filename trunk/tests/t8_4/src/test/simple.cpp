
#include "t8_4.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   A a;
   const A b;

   float c = 7.3;
   const float d = c;

   float* e = &c;
   const float* f = &d;

   float* const g = e;
   const float* const h = e;
   float const i = c;
/*
   B g;
   const B h;
*/
   a.a(e);
   a.b(e);
   a.c(f);
   b.a(e);

   a.a(c);
   a.c(d);
   a.d(i);
   b.a(c);

   a.e(e);
   a.g(f);
   b.e(e);

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

   a.z(e);
   a.y(g);
   a.x(g);

   b.z(e);
   b.y(g);
   b.x(g);

   b.g(g);
   b.i(g);

   a.w(e);
   a.y(h);
   a.x(h);

   b.w(e);
   b.y(h);
   b.x(h);

   std::cout << "done" << std::endl;
}
