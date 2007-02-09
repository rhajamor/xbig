/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles return values and parameters with pointer pointer.
 * Currently (Feb 2007) it is not stored in meta, how many '*'s are used.
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

namespace ns1 
{
	class EXPORT A {
	public:
		A(){mi = 0;}
		A(const A& a){mi = a.mi;}
		~A(){}

		int getM() const {return mi;}
		void setM(int i) {mi = i;}

	private:
		int mi;
	};

	class EXPORT Tester {
	public:
		Tester() {ma = new A;}
		Tester(const Tester& t) {ma = new A; ma->setM(t.ma->getM());}
		~Tester() {delete ma;}

		A* getPointer() { return ma; }
		A** getPointerPointer() { /*A* a = getPointer(); return &a;*/ return &ma; }
		//A*** getPointerPointerPointer() { A** a = getPointerPointer(); return &a; }

		void setValueOfPointer(A* a, int i) { a->setM(i); }
		void setValueOfPointerPointer(A** a, int i) { (*a)->setM(i); }
		//void setPointerPointerPointer(A*** a, int i) { (*(*a))->setM(i); }

	private:
		A* ma;
	};
}
