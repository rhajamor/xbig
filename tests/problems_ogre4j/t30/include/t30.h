

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * template typedef returning ptr
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <map>
#include <string>
#include <iostream>

class EXPORT AnimationState {};

template <class T>
class EXPORT MapIterator
{
public:
	typedef typename T::mapped_type MappedType;
	typedef typename T::key_type KeyType;
	typename T::mapped_type* peekNextValuePtr(void);
};

typedef std::string _StringBase;
typedef _StringBase String;
typedef std::map<String, AnimationState*> AnimationStateMap;
typedef MapIterator<AnimationStateMap> AnimationStateIterator;


template <class T>
typename T::mapped_type* MapIterator<T>::peekNextValuePtr() {
	std::cout << "t30: MapIterator::peekNextValuePtr()" << std::endl;
	return NULL;
}
