

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * no handling of static methods in templates
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif



#include <iostream>
#include <assert.h>
#include <typeinfo>




template <typename T>
class EXPORT Singleton {
protected:
	static T* ms_Singleton;

public:
	Singleton( void ) {ms_Singleton = static_cast< T* >( this );}

	static T& getSingleton( void ) {
		std::cout << "Singleton::getSingleton. Type: " << typeid(ms_Singleton).name() << "\n";
		assert( ms_Singleton );  return ( *ms_Singleton );
	}
	static T* getSingletonPtr( void ) {
		std::cout << "Singleton::getSingletonPtr. Type: " << typeid(ms_Singleton).name() << "\n";
		return ms_Singleton;
	}
};

class EXPORT Root : public Singleton<Root> {};

template <typename T>
T* Singleton<T>::ms_Singleton = 0;
