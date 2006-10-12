

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * inheritance from an inner class
 ****************************************************************************************************************/


class Node {
public:
	class Listener {};
};

class BillboardChain {};

class RibbonTrail : public BillboardChain, public Node::Listener {};
