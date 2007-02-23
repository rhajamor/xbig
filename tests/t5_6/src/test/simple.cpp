
#include "t5_6.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
	C c;
	A* a = &c;
	B* b = &c;

	a->b();
	b->b();
	b->c();
	c.a();
	c.b();
	c.c();
}
