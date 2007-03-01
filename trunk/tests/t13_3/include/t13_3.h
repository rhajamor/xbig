#ifndef __t13_3_H__
#define __t13_3_H__
/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles the last two problems with a std::map
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#include <map>
#include <string>
#include <iostream>

template <class T>
class EXPORT MapIterator
{
private:
	typename T::iterator mCurrent;
	typename T::iterator mEnd;
	MapIterator() {};
public:
	typedef typename T::mapped_type MappedType;
	typedef typename T::key_type KeyType;

	MapIterator(typename T::iterator start, typename T::iterator end)
	: mCurrent(start), mEnd(end)
	{
	}
	explicit MapIterator(T& c)
	: mCurrent(c.begin()), mEnd(c.end())
	{
	}
	bool hasMoreElements(void) const
	{
		return mCurrent != mEnd;
	}
	typename T::mapped_type getNext(void)
	{
		return (mCurrent++)->second;
	}
	typename T::mapped_type peekNextValue(void)
	{
		return mCurrent->second;
	}
	typename T::key_type peekNextKey(void)
	{
		return mCurrent->first;
	}
	MapIterator<T> & operator=( MapIterator<T> &rhs )
	{
		mCurrent = rhs.mCurrent;
		mEnd = rhs.mEnd;
		return *this;
	}
	typename T::mapped_type* peekNextValuePtr(void)
	{
		return &(mCurrent->second);
	}
	void moveNext(void)
	{
		++mCurrent;
	}
};


class EXPORT A {
public:
	A() {std::cout << "t13_3 A::A(), Objects: " << ++objectCounter << "\n"; m = 0;}
    A(int m) {std::cout << "t13_3 A::A(int m), Objects: " << ++objectCounter << "\n"; this->m = m;}
	A(const A& a) {std::cout << "t13_3 A::A(const A& a), Objects: " << ++objectCounter << "\n"; m = a.m;}
	~A() {std::cout << "t13_3 A::~A(), Objects: " << --objectCounter << "\n";}
	void set(int i) {m = i;}
	int get() {return m;}
private:
	int m;
	static int objectCounter;
};

int A::objectCounter = 0;

typedef std::map<std::string, A> AMap;
typedef MapIterator<AMap> AMapIterator;

class EXPORT Tester {
public:
	void a(AMapIterator a) {a.peekNextKey();}
	AMapIterator getMapIterator() {return AMapIterator(m);}
	AMapIterator c(AMapIterator a) {return a;}

	void setMap(AMap a) {m = a;}
	AMap getMap() {return m;}
private:
	AMap m;
};
#endif