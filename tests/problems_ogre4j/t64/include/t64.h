
#ifndef __T64_H__
#define __T64_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * renaming of namespaces in java
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif



namespace Ogre {

	class EXPORT A {
	public:
		int get1(){return 1;}
	};

	namespace EmitterCommands {
		class EXPORT A {
		public:
			int a(::Ogre::A para) {return para.get1();}
		};
	}

	namespace OverlayElementCommands {
		class EXPORT A {
		};
	}
/* not supported (unrenamed namespaces inside a renamed one)
	namespace FOO {
		class EXPORT A {
		};
	}
*/
}

namespace OverlayElementCommands {
	class EXPORT A {
	};

	namespace EmitterCommands {
		class EXPORT A {
		public:
			int a(::Ogre::A para) {return para.get1();}
		};
	}
}

namespace FOO {
	class EXPORT A {
	};
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//
// inheritance
//
//////////////////////////////////////////////////////////////////////////////////////////////////

// unrenamed derived from renamed
class EXPORT B : public Ogre::A {
};

namespace Ogre {

	// renamed derived from unrenamed
	class EXPORT B : public ::FOO::A {
	};

	// renamed derived from renamed
	class EXPORT C : public Ogre::A {
	};
}

#endif
