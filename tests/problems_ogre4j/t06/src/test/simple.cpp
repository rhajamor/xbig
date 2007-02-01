
#include "t06.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   TextureUnitState::TextureEffect a;

   Controller<Real>* con = a.controller;
   a.controller = con;

   std::cout << "done" << std::endl;
}
