
#include "t34.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   SceneQuery::WorldFragment a;
   int* b;

   a.geometry = (void*)b;
   b = (int*)a.geometry;

   std::cout << "done" << std::endl;
}
