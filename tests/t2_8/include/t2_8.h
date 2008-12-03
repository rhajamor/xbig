/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a class with pointers and references to objects
 * as parameters and return values
 * and
 * strings
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
private:
	std::wstring ms;
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
