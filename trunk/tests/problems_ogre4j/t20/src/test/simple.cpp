
#include "t20.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   Math a;

   Ray r;
   std::vector< Plane > b;
   std::list< Plane > c;

   a.intersects(r, b, true);
   a.intersects(r, c, true);

   std::cout << "done" << std::endl;
}
