
#include <iostream>
#include "t9_4.h"

using namespace std;

bool n::Tester::isN(Vocals1 z) {
	cout << "t9_4 n::Tester::isN(Vocals1) para:" << z << "\n";
	return z == n::a | z == n::e | z == n::i | z == n::o | z == n::u;
}

bool n::Tester::isA(A::Vocals2 z) {
	cout << "t9_4 n::Tester::isA(A::Vocals2) para:" << z << "\n";
	return z == A::a | z == A::e | z == A::i | z == A::o | z == A::u;
}

bool n::Tester::isB(B::Vocals3 z) {
	cout << "t9_4 n::Tester::isB(B::Vocals3) para:" << z << "\n";
	return z == B::a | z == B::e | z == B::i | z == B::o | z == B::u;
}

bool n::Tester::isObject(::Vocals1 a) {
	cout << "t9_4 n::Tester::isObject(::Vocals1)\n";
	return a.get5() == 5;
}

bool Tester::isN(n::Vocals1 z) {
	cout << "t9_4 Tester::isN(n::Vocals1) para:" << z << "\n";
	return z == n::a | z == n::e | z == n::i | z == n::o | z == n::u;
}

bool Tester::isA(A::Vocals2 z) {
	cout << "t9_4 Tester::isA(A::Vocals2) para:" << z << "\n";
	return z == A::a | z == A::e | z == A::i | z == A::o | z == A::u;
}

bool Tester::isB(B::Vocals3 z) {
	cout << "t9_4 Tester::isB(B::Vocals3) para:" << z << "\n";
	return z == B::a | z == B::e | z == B::i | z == B::o | z == B::u;
}

bool Tester::isObject(Vocals1 a) {
	cout << "t9_4 Tester::isObject(Vocals1)\n";
	return a.get5() == 5;
}


Vocals1* v_ptr = 0;

Vocals1 Returner::getObject() {
	if (v_ptr == 0)
		v_ptr = new ::Vocals1;
	return *v_ptr;
}

Returner::~Returner() {
	if (v_ptr != 0) {
		delete v_ptr;
		v_ptr = 0;
	}
}

Vocals1 n::Returner::getObject() {
	if (v_ptr == 0)
		v_ptr = new ::Vocals1;
	return *v_ptr;
}

n::Returner::~Returner() {
	if (v_ptr != 0) {
		delete v_ptr;
		v_ptr = 0;
	}
}

Vocals1 B::Returner::getObject() {
	if (v_ptr == 0)
		v_ptr = new ::Vocals1;
	return *v_ptr;
}

B::Returner::~Returner() {
	if (v_ptr != 0) {
		delete v_ptr;
		v_ptr = 0;
	}
}
