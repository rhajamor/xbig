

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * struct defined during typedef
 ******************************************************************/


#include <string>
#include <vector>

typedef std::string _StringBase;
typedef _StringBase String;
typedef std::vector<String> StringVector;

typedef struct _ConfigOption
{
	String name;
	String currentValue;
	StringVector possibleValues;
	bool immutable;
} ConfigOption;

class Tester {
public:
	void a(ConfigOption co) {}
};
