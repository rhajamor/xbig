
#include "t14.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   RenderSystemList a;

   RenderSystem* b;
   a.push_back(b);
   std::cout << typeid(a[0]).name() << std::endl;

   std::cout << "done" << std::endl;
}
