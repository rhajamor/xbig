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

class EXPORT B {
public:
	int get1();
};

class EXPORT A {
public:
	A();
	void a(B* a);
	B* b();
	bool c(B& a);
	B& d();
private:
	B* b_ptr;
	B& b_ref;
};

class EXPORT S {
public:
	void a(std::string s) {ms = s;}
	std::string b() {return ms;}
	std::string c(std::string s) {return s;}

	void d(std::string& s) {ms = s;}
	std::string& e() {return ms;}
	std::string& f(std::string& s) {return s;}

	void g(std::string* s) {ms = *s;}
	std::string* h() {return &ms;}
	std::string* i(std::string* s) {return s;}
private:
	std::string ms;
};
