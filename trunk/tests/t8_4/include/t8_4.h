/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles const pointers
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

	// const data
	const int a(float* b);
	const int* a(float b);
	const int a(const float* b);	
	int a(float* b) const;	
	int* a(float b) const;
	int a(const float* b) const;
	
	int const b(float* b);
	int const b(const float* b);
	
	/** c1 */
	int c(const float* c1b);
	/** c2 */
	int* c(const float c2b);
	/** c3 */
	int c(float* c3b);
	
	int* d(float const b);
	
	const int* e(float* b);	
	const int* e(const float* b);
	int* e(float* b) const;
	int* e(const float* b) const;
	
	int* g(const float* b);
	

	// overloading
	


	int* g(float* b);

	// more than one const per line
	const int* h(float* b) const;
	int* g(const float* b) const;

	const int* i(const float* b) const;

	// const pointers
	int* const z(float* b);
	int* y(float* const b);
	int* const x(float* const b);

	int* const z(float* b) const;
	int* y(float* const b) const;
	int* const x(float* const b) const;

	int* g(float* const b) const;
	const int* i(float* const b) const;

	// const pointers & data
	const int* const w(float* b);
	int* y(const float* const b);
	const int* const x(const float* const b);

	const int* const w(float* b) const;
	int* y(const float* const b) const;
	const int* const x(const float* const b) const;

private:
	int helper;
};
