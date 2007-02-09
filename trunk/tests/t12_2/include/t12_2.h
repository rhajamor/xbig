/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles return values and parameters with pointer pointer and primitive types.
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
	class EXPORT Tester {
	public:
		Tester() {ma = new int;}
		Tester(const Tester& t) {ma = new int; *ma = *(t.ma);}
		~Tester() {delete ma;}

		int* getPointer() { return ma; }
		int** getPointerPointer() { return &ma; }

		void setValueOfPointer(int* a, int i) { *a = i; }
		void setValueOfPointerPointer(int** a, int i) { *(*a) = i; }

	private:
		int* ma;
	};
}
