#ifndef __T13_7_H__
#define __T13_7_H__
/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * protected type as template parameter in public typedef.
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
	A() {std::cout << "t13_7 A::A()" << std::endl; }
	A(const A& rhs) {std::cout << "t13_7 A::A(const A&)" << std::endl; }
	virtual ~A() {std::cout << "t13_7 A::~A()" << std::endl; }
};

class EXPORT Tester {
protected:
	typedef A Alias;
	typedef std::map<std::string, A> AliasMap;

public:
	typedef MapIterator<AliasMap> AMapIterator;

private:
	AliasMap m;
	AMapIterator ami;

public:
	Tester() : ami(m) {m["eins"] = A(); m["zwei"] = A(); m["drei"] = A();}
	virtual ~Tester(){}
	
	AMapIterator* getMapIterator() {return &ami;}
	//virtual AliasMap& getMap(){ return AliasMap(); };	
};
#endif
