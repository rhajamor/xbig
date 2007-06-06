
#ifndef __T52_H__
#define __T52_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * pointer and const as type parameter for templates 
 * using inner stuff of their type parameters and
 * const pointer pointers, see bug 1728998
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <list>
#include <vector>
#include <map>
#include <hash_map>
#include <string>
#include "OgreIteratorWrappers.h"


#define HashMap ::std::hash_map


namespace Ogre {

	typedef std::string String;
	typedef std::map<String, String> AliasTextureNamePairList;

	class EXPORT SubMesh {
	public:
		typedef ConstMapIterator<AliasTextureNamePairList> AliasTextureIterator;
	};


	class EXPORT Animation {};
	struct EXPORT LinkedSkeletonAnimationSource {};
	class EXPORT SkeletonInstance {
	public:
		Animation* _getAnimationImpl(const String &name, const LinkedSkeletonAnimationSource **linker=0) const {return NULL;}
	};

	class EXPORT MovableObject {};
	class EXPORT SceneNode {
	public:
		typedef HashMap<String, MovableObject*> ObjectMap;
		typedef ConstMapIterator<ObjectMap> ConstObjectIterator;
	};

	class EXPORT MovableObjectFactory {};
	class EXPORT Root {
	public:
		typedef std::map<String, MovableObjectFactory*> MovableObjectFactoryMap;
		typedef ConstMapIterator<MovableObjectFactoryMap> MovableObjectFactoryIterator;
	};

	class EXPORT Node {};
	class EXPORT RibbonTrail {
	public:
		typedef std::vector<Node*> NodeList;
		typedef ConstVectorIterator<NodeList> NodeIterator;
	};

	class EXPORT SceneManagerMetaData {};
	class EXPORT SceneManagerEnumerator {
	public:
		typedef std::vector<const SceneManagerMetaData*> MetaDataList;
		typedef ConstVectorIterator<MetaDataList> MetaDataIterator;
	};

	class EXPORT A {};
	typedef std::vector<A> AVec;
	typedef VectorIterator<AVec> AIterator;
	typedef std::vector<A*> APtrVec;
	typedef VectorIterator<APtrVec> APtrIterator;
}

#endif
