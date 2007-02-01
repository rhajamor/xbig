
#include <iostream>
#include "t9_1.h"

using namespace std;

bool A::isA(Vocals b) {
	cout << "t9_1 A::isA(Vocals) para:" << b << "\n";
	return b == a;
}

bool A::isE(Vocals a) {
	cout << "t9_1 A::isE(Vocals) para:" << a << "\n";
	return a == e;
}

bool A::isI(Vocals a) {
	cout << "t9_1 A::isI(Vocals) para:" << a << "\n";
	return a == i;
}

bool A::isO(Vocals a) {
	cout << "t9_1 A::isO(Vocals) para:" << a << "\n";
	return a == o;
}

bool A::isU(Vocals a) {
	cout << "t9_1 A::isU(Vocals) para:" << a << "\n";
	return a == u;
}
