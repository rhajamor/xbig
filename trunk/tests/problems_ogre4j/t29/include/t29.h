

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


#include <vector>

class CompositorInstance {};

template <class T>
class VectorIterator {};

class CompositorChain {
public:
	typedef std::vector<CompositorInstance*> Instances;
	typedef VectorIterator<Instances> InstanceIterator;
};
