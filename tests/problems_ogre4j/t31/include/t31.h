

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * template typedef returning ptr (2)
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <vector>
#include <iostream>

template <class T>
class EXPORT VectorIterator
{
public:
	typename T::pointer peekNextPtr(void);
};

class EXPORT CompositorInstance {};

class EXPORT CompositorChain {
public:
	typedef std::vector<CompositorInstance*> Instances;
	typedef VectorIterator<Instances> InstanceIterator;
};


template <class T>
typename T::pointer VectorIterator<T>::peekNextPtr() {
	std::cout << "t31: VectorIterator<T>::peekNextPtr()" << std::endl;
	return NULL;
}
