/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles single functions with different types
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

EXPORT void a(int b);
EXPORT int a(void);
EXPORT void b(unsigned b);
EXPORT unsigned b(void);
EXPORT void c(signed b);
EXPORT signed c(void);
EXPORT void d(unsigned int b);
EXPORT unsigned int d(void);
EXPORT void e(signed int b);
EXPORT signed int e(void);

EXPORT void f(short b);
EXPORT short f(void);
EXPORT void g(unsigned short b);
EXPORT unsigned short g(void);
EXPORT void h(signed short b);
EXPORT signed short h(void);

EXPORT void i(long b);
EXPORT long i(void);
EXPORT void j(unsigned long b);
EXPORT unsigned long j(void);
EXPORT void k(signed long b);
EXPORT signed long k(void);

EXPORT void l(char b);
EXPORT char l(void);
EXPORT void m(unsigned char b);
EXPORT unsigned char m(void);
EXPORT void n(signed char b);
EXPORT signed char n(void);

namespace l1 {
	EXPORT void o(float b);
	EXPORT float o(void);
	
	namespace l2 {
		EXPORT void p(double b);
		EXPORT double p(void);
	}
}

//the data type long double is not supported
//EXPORT void q(long double b);
//EXPORT long double q(void);

EXPORT void r(void);
EXPORT void s();

class EXPORT A {
public:
	A();
};

EXPORT void t_set(A b);
EXPORT A t_get(void);

//the array is not handled correctly
//EXPORT void u(int b[]);
EXPORT int* u(void);
