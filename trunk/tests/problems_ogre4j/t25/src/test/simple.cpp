
#include "t25.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   SceneQuery::WorldFragment a;
   RaySceneQueryResultEntry b;

   b.worldFragment = &a;

   std::cout << "done" << std::endl;
}
