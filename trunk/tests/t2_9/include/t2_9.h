/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles method overloading.
 *
 * wstrings are handled here because mixing of cout and wcout
 * is not supported on every platform (see t2_8).
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>
#include <iostream>


class EXPORT B {
public:
	B();

        long long getSigned(char v);
        long long getSigned(signed char v);
        long long getSigned(short v);
        long long getSigned(int v);
        long long getSigned(long v);
        long long getSigned(long long v);

        unsigned long long getUnsigned(unsigned char v);
        unsigned long long getUnsigned(unsigned short v);
        unsigned long long getUnsigned(unsigned int v);
        unsigned long long getUnsigned(unsigned long v);
        unsigned long long getUnsigned(unsigned long long v);
};


class EXPORT WideString {
public:
	void a(std::wstring s) {ms = s;}
	std::wstring b() {return ms;}
	std::wstring c(std::wstring s) {std::wcout << "str in c++: " << s << std::endl; return s;}

	void d(std::wstring& s) {ms = s;}
	std::wstring& e() {return ms;}
	std::wstring& f(std::wstring& s) {std::wcout << "str in c++: " << s << std::endl; return s;}

	void g(std::wstring* s) {ms = *s;}
	std::wstring* h() {return &ms;}
	std::wstring* i(std::wstring* s) {std::wcout << "str in c++: " << *s << std::endl; return s;}

	const std::wstring wstringConstValue(const std::wstring str) {return str;}
	const std::wstring* wstringConstPointer(const std::wstring* str) {return str;}
	const std::wstring& wstringConstReference(const std::wstring& str) {return str;}

private:
	std::wstring ms;
};
