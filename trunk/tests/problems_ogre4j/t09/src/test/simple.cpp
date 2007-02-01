
#include "t09.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   ConfigFile a;
   ConfigFile::SectionIterator b;

   b = a.getSectionIterator();

   std::cout << "done" << std::endl;
}
