

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * template typedef returning ptr (2)
 ****************************************************************************************************************/


#include <vector>
#include <iostream>

template <class T>
class VectorIterator
{
public:
	typename T::pointer peekNextPtr(void);
};

class CompositorInstance {};

class CompositorChain {
public:
	typedef std::vector<CompositorInstance*> Instances;
	typedef VectorIterator<Instances> InstanceIterator;
};


template <class T>
typename T::pointer VectorIterator<T>::peekNextPtr() {
	std::cout << "t31: VectorIterator<T>::peekNextPtr()" << std::endl;
}
