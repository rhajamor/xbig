
#include "t6_1.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) 
{
   A<int> a;
   int b = a.a();
   a.b(b);

   A<std::string> s;
   std::string str = s.a();
   s.b(str);

   std::cout << "done" << std::endl;
}
