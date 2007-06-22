
#ifndef __T63_H__
#define __T63_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * some methods of interfaces are missing in classes, see bug 1728975
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <set>
#include <vector>


namespace Ogre {

	typedef unsigned short int uint16;
	typedef unsigned int uint32;
	typedef float Real;

	class EXPORT SceneManager {};
	class EXPORT AxisAlignedBox {};
	class EXPORT SceneQueryResult {};
	class EXPORT MovableObject {};

	class EXPORT SceneQuery {
	public:
		class EXPORT WorldFragment {};
	};

	class EXPORT SceneQueryListener {};
	class EXPORT RegionSceneQuery : public SceneQueryListener, public SceneQuery {
	public:
		bool 	queryResult (WorldFragment *fragment) {return false;}
	};
	class EXPORT AxisAlignedBoxSceneQuery : public RegionSceneQuery {};

	class EXPORT DefaultAxisAlignedBoxSceneQuery : public AxisAlignedBoxSceneQuery {
			AxisAlignedBox mAxisAlignedBox;
			SceneQueryResult mSceneQueryResult;
	public:
		enum WorldFragmentType {
  			WFT_NONE,
  			WFT_PLANE_BOUNDED_REGION,
  			WFT_SINGLE_INTERSECTION,
  			WFT_CUSTOM_GEOMETRY,
  			WFT_RENDER_OPERATION
		};
		DefaultAxisAlignedBoxSceneQuery (SceneManager *creator) {}
		/*
		~DefaultAxisAlignedBoxSceneQuery () {}
		void 	execute (SceneQueryListener *listener) {}
		void 	setBox (const AxisAlignedBox &box) {}
		const AxisAlignedBox & 	getBox (void) const {return mAxisAlignedBox;}
		virtual SceneQueryResult & 	execute (void) {return mSceneQueryResult;}
		//virtual SceneQueryResult & 	getLastResults (void) const {return mSceneQueryResult;}
		virtual SceneQueryResult & 	getLastResults (void) {return mSceneQueryResult;}
		virtual void 	clearResults (void) {}
		*/
		bool 	queryResult (MovableObject *first) {return false;}
		bool 	queryResult (WorldFragment *fragment) {return false;}
		/*
		virtual void 	setQueryMask (uint32 mask) {}
		virtual uint32 	getQueryMask (void) const {return 0;}
		virtual void 	setQueryTypeMask (uint32 mask) {}
		virtual uint32 	getQueryTypeMask (void) const {return 0;}
		virtual void 	setWorldFragmentType (enum WorldFragmentType wft) {}
		virtual WorldFragmentType 	getWorldFragmentType (void) const {return WFT_NONE;}
		virtual const std::set< WorldFragmentType > * 	getSupportedWorldFragmentTypes (void) const {return NULL;}
		*/
	};



//////////////////////////////////////////////////////////////////////////////////////////////////////


	class EXPORT Animation {
	protected:
		typedef std::vector< Real > KeyFrameTimeList;
	};

}

#endif
