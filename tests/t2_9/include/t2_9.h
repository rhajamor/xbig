/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a class with a method
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

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

