
#include "t11_1.h"
#include <iostream>

#define CHECK(test) \
   if(test) { std::cout << #test << " OK" << std::endl; } \
   else { std::cout << #test << " failed" << std::endl; }


int main(int argc, char* argv[]) 
{
   a = 42;
   l1::a = 43;
   l1::l2::a = 44;

   CHECK(a == 42);
   CHECK(l1::a == 43);
   CHECK(l1::l2::a == 44);
   
   std::cout << "done" << std::endl;
}
