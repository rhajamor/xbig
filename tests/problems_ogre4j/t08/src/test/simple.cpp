
#include "t08.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   Root* a = new Root;
   a->saveConfig();
   delete a;

   std::cout << "done" << std::endl;
}
