
#include "t5_4.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
	D d;
	B* b = &d;
	C* c = &d;
	A* a = b;
	a = c;

	d.abstractA();
	d.B::notAbstract();
	d.abstractB();
}
