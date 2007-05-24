

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
#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <bitset>


enum EXPORT RenderQueueGroupID {
	RENDER_QUEUE_OVERLAY = 100
};

const size_t RENDER_QUEUE_COUNT = RENDER_QUEUE_OVERLAY+1;

class EXPORT CompositorInstance {
public:
	class EXPORT TargetOperation {
	public:
		typedef std::bitset<RENDER_QUEUE_COUNT> RenderQueueBitSet;
	};
};
