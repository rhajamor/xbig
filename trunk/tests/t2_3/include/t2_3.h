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

#include <string>
#include <iostream>
#include <time.h>


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
        std::string getString(std::string v);
        char* getCharStar(char * v);
        const char * getConstCharStar(const char* v);
        signed char* getSignedCharStar(signed char * v);
        unsigned char* getUnsignedCharStar(unsigned char * v);
        size_t getSize_t(size_t v);
        wchar_t getWchar_t(wchar_t v);
};

class EXPORT Time {
public:
	Time():t(0){}
	void setTime(time_t t) {std::cout << "time in c++: " << t << std::endl; this->t = t;}
	time_t getTime() {std::cout << "returning: " << t << std::endl; return t;}

	void setTimePtr(time_t* t) {std::cout << "time in c++ (via ptr):" << *t << ", adr: " << (int)t << ", as long: " << (long)*t << ", prev adr as long: " << (long)(*(t-4)) << ", next adr as long: " << (long)(*(t+4)) << std::endl; this->t = *t;}
	time_t* getTimePtr() {return &t;}

	void setTimeRef(time_t& t) {this->t = t;}
	time_t& getTimeRef() {return t;}

private:
	time_t t;
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

