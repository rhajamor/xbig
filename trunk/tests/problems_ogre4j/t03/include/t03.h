

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * const global variable as template parameter
 ******************************************************************/


#include <bitset>


enum RenderQueueGroupID {
	RENDER_QUEUE_OVERLAY = 100
};

const size_t RENDER_QUEUE_COUNT = RENDER_QUEUE_OVERLAY+1;

class CompositorInstance {
public:
	class TargetOperation {
	public:
		typedef std::bitset<RENDER_QUEUE_COUNT> RenderQueueBitSet;
	};
};
