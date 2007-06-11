
#ifndef __T59_H__
#define __T59_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * missing parameter, see bug 1728995
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>


namespace Ogre {

	typedef std::string String;
	typedef float Real;


	class EXPORT Vector3 {};
	class EXPORT Quaternion {};


	class EXPORT Renderable {};

	class EXPORT Node : public Renderable {
	public:
		virtual Node* createChild(const String name, const Vector3 translate, const Quaternion rotate) {return NULL;}
		virtual Node* createChild(const Vector3 translate, const Quaternion rotate) {return NULL;}
	};

	class EXPORT Bone : public Node {
	public:
		Bone* createChild(unsigned short handle, const Vector3 translate, const Quaternion rotate) {return NULL;}
	};

	class EXPORT TagPoint : public Bone {};
}

#endif
