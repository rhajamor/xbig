/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles const references
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

class EXPORT A {
public:
	A();

	const int a(float& b);
	int const b(float& b);
	int c(const float& b);
	int a(float& b) const;

	//const int& a(float b);
	//int& c(const float b);
	int& d(float const b);
	//int& a(float b) const;

	const int& e(float& b);
	int& g(const float& b);
	int& e(float& b) const;

	// overloading
	const int a(const float& b);
	int const b(const float& b);
	int c(float& b);
	int a(const float& b) const;

	const int& e(const float& b);
	int& g(float& b);
	int& e(const float& b) const;

	// more than one const per line
	const int& h(float& b) const;
	int& g(const float& b) const;

	const int& i(const float& b) const;

private:
	int z;
};

// needed because of ambiguity
class EXPORT B {
public:
	B();

	const int& a(float b);
	int& c(const float b);
	int& a(float b) const;

private:
	int z;
};
