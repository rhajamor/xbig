/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a class with pointers and references to objects
 * as parameters and return values
 * and
 * strings.
 * wstrings are moved to t2_9 because mixing of cout and wcout
 * is not supported on every platform.
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
	B(const B&);
	~B();

	int get1();

	int geti();
	void seti(int i);

private:
	int i;
};

class EXPORT A {
public:
	A();
	void a(B* a);
	B* b();
	bool c(B& a);
	B& d();

	B e();
	void f(B);
	B g(B);

	static B h;

private:
	B* b_ptr;
	B& b_ref;
	B b_val;
};

class EXPORT S {
public:
	void a(std::string s) {ms = s;}
	std::string b() {return ms;}
	std::string c(std::string s) {std::cout << "str in c++: " << s << std::endl; return s;}

	void d(std::string& s) {ms = s;}
	std::string& e() {return ms;}
	std::string& f(std::string& s) {std::cout << "str in c++: " << s << std::endl; return s;}

	void g(std::string* s) {ms = *s;}
	std::string* h() {return &ms;}
	std::string* i(std::string* s) {std::cout << "str in c++: " << *s << std::endl; return s;}
private:
	std::string ms;
};

class EXPORT CharPtr {
public:
	void a(const char* s) {ms = s;}
	const char* b() {return ms;}
	const char* c(const char* s) {std::cout << "str in c++: " << s << std::endl; return s;}

private:
	const char* ms;
};

class EXPORT Const {
public:
	const std::string a(const std::string s) {std::cout << "str in c++: " << s << std::endl; return s;}
	const std::string* b(const std::string* s) {std::cout << "str in c++: " << s << std::endl; return s;}
	const std::string& c(const std::string& s) {std::cout << "str in c++: " << s << std::endl; return s;}
};

class EXPORT CharPtr2 {
public:
	const char* constCharPtr(const char* s) {std::cout << "[constCharPtr] str in c++: " << s << ", as int: " << (int)*s << std::endl; return s;}
	char* charPtr(char* s) {std::cout << "[charPtr] str in c++: " << s << ", as int: " << (int)*s << std::endl; return s;}

	char charValue(char s) {std::cout << "[charValue] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}
	const char constCharValue(const char s) {std::cout << "[constCharValue] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}

	char& charRef(char& s) {std::cout << "[charRef] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}
	const char& constCharRef(const char& s) {std::cout << "[constCharRef] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}


	const unsigned char* constCharPtrUnsigned(const unsigned char* s) {std::cout << "[constCharPtrUnsigned] str in c++: " << s << ", as int: " << (int)*s << std::endl; return s;}
	unsigned char* charPtrUnsigned(unsigned char* s) {std::cout << "[charPtrUnsigned] str in c++: " << s << ", as int: " << (int)*s << std::endl; return s;}

	unsigned char charValueUnsigned(unsigned char s) {std::cout << "[charValueUnsigned] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}
	const unsigned char constCharValueUnsigned(const unsigned char s) {std::cout << "[constCharValueUnsigned] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}

	unsigned char& charRefUnsigned(unsigned char& s) {std::cout << "[charRefUnsigned] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}
	const unsigned char& constCharRefUnsigned(const unsigned char& s) {std::cout << "[constCharRefUnsigned] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}


	const signed char* constCharPtrSigned(const signed char* s) {std::cout << "[constCharPtrSigned] str in c++: " << s << ", as int: " << (int)*s << std::endl; return s;}
	signed char* charPtrSigned(signed char* s) {std::cout << "[charPtrSigned] str in c++: " << s << ", as int: " << (int)*s << std::endl; return s;}

	signed char charValueSigned(signed char s) {std::cout << "[charValueSigned] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}
	const signed char constCharValueSigned(const signed char s) {std::cout << "[constCharValueSigned] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}

	signed char& charRefSigned(signed char& s) {std::cout << "[charRefSigned] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}
	const signed char& constCharRefSigned(const signed char& s) {std::cout << "[constCharRefSigned] str in c++: " << s << ", as int: " << (int)s << std::endl; return s;}
};
