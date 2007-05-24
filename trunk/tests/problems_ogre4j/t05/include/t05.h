

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * inheritance from an inner class
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


class EXPORT Node {
public:
	class EXPORT Listener {};
};

class EXPORT BillboardChain {};

class EXPORT RibbonTrail : public BillboardChain, public Node::Listener {};
