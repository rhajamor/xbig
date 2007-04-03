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

class EXPORT A {
public:
	A();
        char getChar(char v);
        unsigned char getUnsignedChar(unsigned char v);
        signed char getSignedChar(signed char v);
        short getShort(short v);
        unsigned short getUnsignedShort(unsigned short v);
        int getInt(int v);
        unsigned int getUnsignedInt(unsigned int v);
        long getLong(long v);
        unsigned long getUnsignedLong(unsigned long v);
        float getFloat(float v);
        double getDouble(double v);   
};

class EXPORT B {
public:
	B();
	
        long getSigned(char v);
        long getSigned(signed char v);
        long getSigned(short v);
        long getSigned(int v);
        long getSigned(long v);
        
        unsigned long getUnsigned(unsigned char v);
        unsigned long getUnsigned(unsigned short v);
        unsigned long getUnsigned(unsigned int v);
        unsigned long getUnsigned(unsigned long v);                
};

