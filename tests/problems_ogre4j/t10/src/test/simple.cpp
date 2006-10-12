
#include "t10.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   Root a;
   a.createRenderWindow("name", 800, 600, false);
   a.createSceneManager(1);

   std::cout << "done" << std::endl;
}
