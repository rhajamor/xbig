
#include "t17.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   TextureUnitState a;

   std::string str = "";

   a.setCubicTextureName(str);
   a.setCubicTextureName(&str);

   std::cout << "done" << std::endl;
}
