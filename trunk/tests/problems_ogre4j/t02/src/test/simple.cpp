
#include "t02.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   Particle a;
   Radian b;

   a.setRotation(b);
   b = a.getRotation();
   a.rotation = b;
   b = a.rotation;

   std::cout << "done" << std::endl;
}
