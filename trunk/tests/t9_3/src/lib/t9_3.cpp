
#include <iostream>
#include "t9_3.h"

using namespace std;

bool Tester::isN(n::Vocals z) {
	cout << "t9_3 Tester::isN(n::Vocals) para:" << z << "\n";
	return z == n::a | z == n::e | z == n::i | z == n::o | z == n::u;
}

bool Tester::isA(A::Vocals z) {
	cout << "t9_3 Tester::isA(A::Vocals) para:" << z << "\n";
	return z == A::a | z == A::e | z == A::i | z == A::o | z == A::u;
}

bool Tester::isB(B::Vocals z) {
	cout << "t9_3 Tester::isB(B::Vocals) para:" << z << "\n";
	return z == B::a | z == B::e | z == B::i | z == B::o | z == B::u;
}
