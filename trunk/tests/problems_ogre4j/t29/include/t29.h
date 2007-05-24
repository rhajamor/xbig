

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * template typedef for inner type
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <vector>

class EXPORT CompositorInstance {};

template <class T>
class EXPORT VectorIterator {};

class EXPORT CompositorChain {
public:
	typedef std::vector<CompositorInstance*> Instances;
	typedef VectorIterator<Instances> InstanceIterator;
};
