
#include "t16.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   OverlayManager a;

   OverlayElement* oePtr;
   a.destroyOverlayElement(oePtr);

   std::cout << "done" << std::endl;
}
