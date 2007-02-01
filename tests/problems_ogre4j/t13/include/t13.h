

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


#include <assert.h>

template <typename T>
class Singleton {
protected:
	static T* ms_Singleton;

public:
	Singleton( void ) {ms_Singleton = static_cast< T* >( this );}

	static T& getSingleton( void ) {   assert( ms_Singleton );  return ( *ms_Singleton ); }
	static T* getSingletonPtr( void ) { return ms_Singleton; }
};

class Root : public Singleton<Root> {};

template <typename T>
T* Singleton<T>::ms_Singleton = 0;
