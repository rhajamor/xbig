
#include "t24.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   SceneQuery::WorldFragment a;

   std::list< Plane > b;
   a.planes = &b;
   std::cout << "Size: " << a.planes->size() << std::endl;

   std::cout << "done" << std::endl;
}
