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

EXPORT void o(float b);
EXPORT float o(void);

EXPORT void p(double b);
EXPORT double p(void);

EXPORT void q(long double b);
EXPORT long double q(void);

EXPORT void r(void);
EXPORT void s();

class EXPORT A {
public:
	A();
};

EXPORT void t(A b);
EXPORT A t(void);

EXPORT void u(int b[]);
EXPORT int* u(void);
