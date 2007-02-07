/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles a template which makes assumptions
 * about it's type parameter
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#include <vector>
#include <string>



template <class T>
class VectorIterator {
private:
	typename T::iterator mCurrent;
	typename T::iterator mEnd;
	VectorIterator() {};
public:
	typedef typename T::value_type ValueType;

	VectorIterator(typename T::iterator start, typename T::iterator end)
	: mCurrent(start), mEnd(end)
	{
	}

	explicit VectorIterator(T& c)
	: mCurrent(c.begin()), mEnd(c.end())
	{
	}
	bool hasMoreElements(void) const
	{
		return mCurrent != mEnd;
	}
	typename T::value_type getNext(void)
	{
		return *mCurrent++;
	}
	typename T::value_type peekNext(void)
	{
		return *mCurrent;
	}
	typename T::pointer peekNextPtr(void)
	{
		return &(*mCurrent);
	}
	void moveNext(void)
	{
		++mCurrent;
	}
};



typedef std::vector<std::string> StringVector;
typedef VectorIterator<StringVector> StringIterator;

class Tester {
public:
	void a(StringIterator a) {a.peekNextPtr();}
	StringIterator b() {return StringIterator(m);}
	StringIterator c(StringIterator a) {return a;}

	void setVector(StringVector a) {m = a;}
	StringVector getVector() {return m;}
private:
	StringVector m;
};
