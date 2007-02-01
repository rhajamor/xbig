
#include "t18.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   float a = 0.0;

   Vector2 b(a);
   Vector2 c(&a);

   std::cout << "done" << std::endl;
}
