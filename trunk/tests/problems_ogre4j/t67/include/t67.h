
#ifndef __T67_H__
#define __T67_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * Enum as type parameter
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <vector>


namespace Ogre {

	class EXPORT HardwareBuffer {
	public:
		enum Usage {
			HBU_STATIC = 1,
			HBU_DYNAMIC = 2,
			HBU_WRITE_ONLY = 4
		};
	};

	typedef std::vector<HardwareBuffer::Usage> BufferUsageList;
}
#endif
