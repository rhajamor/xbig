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
		bool getBool(bool v);
        char getChar(char v);
        unsigned char getUnsignedChar(unsigned char v);
        signed char getSignedChar(signed char v);
        short getShort(short v);
        short int getShortInt(short int v);
        signed short getSignedShort(signed short v);
        signed short int getSignedShortInt(signed short int v);
        unsigned short getUnsignedShort(unsigned short v);
        unsigned short int getUnsignedShortInt(unsigned short int v);
        int getInt(int v);
        signed getSigned(signed v);
        signed int getSignedInt(signed int v);
        unsigned getUnsigned(unsigned v);
        unsigned int getUnsignedInt(unsigned int v);
        long getLong(long v);
        long int getLongInt(long int v);
        signed long getSignedLong(signed long v);
        signed long int getSignedLongInt(signed long int v);        
        unsigned long getUnsignedLong(unsigned long v);
        unsigned long int getUnsignedLongInt(unsigned long int v);
        long long getLongLong(long long v);
        signed long long getSignedLongLong(signed long long v);
        unsigned long long getUnsignedLongLong(unsigned long long v);
        float getFloat(float v);
        double getDouble(double v);
};

/*
Move B to t2_9

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
};*/

