
#include <iostream>
#include "t9_2.h"

using namespace std;

bool A::isA(Vocals b) {
	cout << "t9_2 A::isA(Vocals) para:" << b << "\n";
	return b == a;
}

bool A::isE(Vocals a) {
	cout << "t9_2 A::isE(Vocals) para:" << a << "\n";
	return a == e;
}

bool A::isI(Vocals a) {
	cout << "t9_2 A::isI(Vocals) para:" << a << "\n";
	return a == i;
}

bool A::isO(Vocals a) {
	cout << "t9_2 A::isO(Vocals) para:" << a << "\n";
	return a == o;
}

bool A::isU(Vocals a) {
	cout << "t9_2 A::isU(Vocals) para:" << a << "\n";
	return a == u;
}
