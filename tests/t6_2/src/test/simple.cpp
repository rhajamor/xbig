
#include "t6_2.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) 
{
   B<int> a;
   int b = a.a();
   a.b(b);

   std::cout << "setting public member 'x' to 42\n";
   a.x = 42;
   std::cout << "reading public member 'x'\n";
   if (a.x == 42)
      std::cout << "OK, x == 42\n";
   else
      std::cout << "ERROR: x != 42\n";

   std::cout << "setting public member 'y' to 42\n";
   a.y = 42;
   std::cout << "reading public member 'x'\n";
   if (a.y == 42)
      std::cout << "OK, y == 42\n";
   else
      std::cout << "ERROR: y != 42\n";

   B<std::string> s;
   std::string str = s.a();
   s.b(str);

   std::cout << "setting public member 'x' to 42\n";
   s.x = 42;
   std::cout << "reading public member 'x'\n";
   if (s.x == 42)
      std::cout << "OK, x == 42\n";
   else
      std::cout << "ERROR: x != 42\n";

   std::cout << "setting public member 'y' to 42\n";
   s.y = "42";
   std::cout << "reading public member 'x'\n";
   if (s.y == "42")
      std::cout << "OK, y == 42\n";
   else
      std::cout << "ERROR: y != 42\n";

   std::cout << "done" << std::endl;
}
