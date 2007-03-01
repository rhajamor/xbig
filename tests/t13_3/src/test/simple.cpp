#include "t13_3.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
    AMap map;    
    map["eins"] = A(1);
    map["zwei"] = A(2);
    map["drei"] = A(3);
    Tester tester;
    tester.setMap(map);    
    AMapIterator it = tester.getMapIterator();
    
    std::cout << "--------------------------------" << std::endl;
    while(it.hasMoreElements())
    {        
        std::cout << it.peekNextKey() << ", " << it.peekNextValue().get() << std::endl;
        it.getNext();
    }
    std::cout << "--------------------------------" << std::endl;

    AMapIterator c = tester.c(it);
    std::cout << "done" << std::endl;
}
