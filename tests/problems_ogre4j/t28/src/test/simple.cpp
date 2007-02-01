
#include "t28.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   RadixSort<char, int, double> a;

   char b = 'a';
   a.sort(b, 3000000000);

   std::cout << "done" << std::endl;
}
