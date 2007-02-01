/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a typedef for an external type
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#include <vector>
#include <string>


typedef std::vector<std::string> StringVector;

class Tester {
public:
	void a(StringVector a) {m = a;}
	StringVector b() {return m;}
	StringVector c(StringVector a) {return a;}
private:
	StringVector m;
};
