
#include "t15.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   Matrix3 a;

   float b[3] = {0.1, 0.2, 0.3};

   Vector3 d;
   Vector3 e;
   Vector3 f;
   Vector3 c[3] = {d, e, f};

   a.EigenSolveSymmetric(b, c);

   std::cout << "done" << std::endl;
}
