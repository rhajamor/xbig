
#ifndef __T66_H__
#define __T66_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * optional type parameters
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <map>
#include <vector>
#include <string>


namespace Ogre {

	class EXPORT A{};

	typedef std::string String;
	typedef std::vector< String, std::allocator< String > > Vector;
	typedef std::map< String, A, std::less< String >, std::allocator< std::pair< String, A > > > Map;

}
#endif
