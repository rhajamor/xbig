
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

	enum EXPORT Vocals1 {
		a = 101,
		e = 102,
		i = 103,
		o = 104,
		u = 105
	};

	class EXPORT A {
	public:
		int get1(){return 1;}
	};

	namespace EmitterCommands {
		class EXPORT A {
		public:
			int a(::Ogre::A para) {return para.get1();}
			::Ogre::A& b(::Ogre::A& para) {return para;}
			Vocals1 c (Vocals1 para) {return para;}
		};
	}

	namespace OverlayElementCommands {
		class EXPORT A {
		public:
			::Ogre::EmitterCommands::A& b(::Ogre::EmitterCommands::A& para) {return para;}
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
