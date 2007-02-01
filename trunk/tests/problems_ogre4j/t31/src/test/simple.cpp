
#include "t31.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   CompositorChain::InstanceIterator a;

   a.peekNextPtr();

   std::cout << "done" << std::endl;
}
