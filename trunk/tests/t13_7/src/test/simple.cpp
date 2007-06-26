#include "t13_7.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
    Tester tester;	 
	//std::map<std::string, A> gaga = tester.getMap();
    Tester::AMapIterator* it = tester.getMapIterator();
    
    std::cout << "--------------------------------" << std::endl;
    while(it->hasMoreElements())
    {        
        std::cout << it->peekNextKey() << std::endl;
        it->getNext();
    }
    std::cout << "--------------------------------" << std::endl;
    
    std::cout << "done" << std::endl;
}
