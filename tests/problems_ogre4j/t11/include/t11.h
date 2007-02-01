

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * simple type as type parameter
 ******************************************************************/


#include <map>
#include <string>

typedef std::string _StringBase;
typedef _StringBase String;

typedef std::map<String, bool> UnaryOptionList;
