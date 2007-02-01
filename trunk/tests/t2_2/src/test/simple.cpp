
#include "t2_2.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   A a;

   std::cout << "setting public member 'a' to 42\n";
   a.a = 42;
   std::cout << "reading public member 'a'\n";
   if (a.a == 42)
      std::cout << "OK, a == 42\n";
   else
      std::cout << "ERROR: a != 42\n";

   std::cout << "done" << std::endl;
}
