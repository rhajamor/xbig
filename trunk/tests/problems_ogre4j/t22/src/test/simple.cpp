
#include "t22.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   RenderSystemA a;
   RenderSystem* b = &a;

   std::cout << b->getName() << std::endl;

   std::cout << "done" << std::endl;
}
