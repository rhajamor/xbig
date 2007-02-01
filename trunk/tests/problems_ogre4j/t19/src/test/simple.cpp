
#include "t19.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   Matrix3 a;
   Matrix3 b;

   a.Inverse(b);
   a.Inverse();

   std::cout << "done" << std::endl;
}
