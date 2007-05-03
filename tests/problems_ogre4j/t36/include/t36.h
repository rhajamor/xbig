
#ifndef __T36_H__
#define __T36_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * "Duplicate field" Error of javac
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


//#include <list>
//#include <set>


namespace Ogre {

/*
typedef unsigned int uint32;

class Vector3 {};
class Plane {};
class RenderOperation {};
class SceneManager {};
class MovableObject {};*/
class SceneQueryResult {};
class AxisAlignedBox {};


class EXPORT SceneQuery
{/*
public:
	enum WorldFragmentType {
		WFT_NONE,
		WFT_PLANE_BOUNDED_REGION,
		WFT_SINGLE_INTERSECTION,
		WFT_CUSTOM_GEOMETRY,
		WFT_RENDER_OPERATION
	};

	struct WorldFragment {
		WorldFragmentType fragmentType;
		Vector3 singleIntersection;
		std::list<Plane>* planes;
		void* geometry;
		RenderOperation* renderOp;

	};
protected:
	SceneManager* mParentSceneMgr;
	uint32 mQueryMask;
	uint32 mQueryTypeMask;
	std::set<WorldFragmentType> mSupportedWorldFragments;
	WorldFragmentType mWorldFragmentType;

public:
	SceneQuery(SceneManager* mgr) {}
	virtual ~SceneQuery() {}

	virtual void setQueryMask(uint32 mask) {}
	virtual uint32 getQueryMask(void) const {return mQueryMask;}

	virtual void setQueryTypeMask(uint32 mask) {}
	virtual uint32 getQueryTypeMask(void) const {return mQueryTypeMask;}

	virtual void setWorldFragmentType(enum WorldFragmentType wft) {}

	virtual WorldFragmentType getWorldFragmentType(void) const {return mWorldFragmentType;}

	virtual const std::set<WorldFragmentType>* getSupportedWorldFragmentTypes(void) const
		{return &mSupportedWorldFragments;}
*/
};


class EXPORT SceneQueryListener
{/*
public:
	virtual ~SceneQueryListener() { }
	virtual bool queryResult(MovableObject* object) = 0;
	virtual bool queryResult(SceneQuery::WorldFragment* fragment) = 0;
*/
};


class EXPORT RegionSceneQuery
	: public SceneQuery, public SceneQueryListener
{
protected:
	SceneQueryResult* mLastResult;
public:/*
	RegionSceneQuery(SceneManager* mgr) :SceneQuery(mgr) {}
	virtual ~RegionSceneQuery() {}
	virtual SceneQueryResult& execute(void) {return *mLastResult;}

	virtual void execute(SceneQueryListener* listener) = 0;

	virtual SceneQueryResult& getLastResults(void) const {return *mLastResult;}
	virtual void clearResults(void) {}

	bool queryResult(MovableObject* first) {return false;}
	bool queryResult(SceneQuery::WorldFragment* fragment) {return false;}*/
};


class EXPORT AxisAlignedBoxSceneQuery : public RegionSceneQuery
{
protected:
    AxisAlignedBox mAABB;
public:
//	AxisAlignedBoxSceneQuery(SceneManager* mgr) :RegionSceneQuery(mgr) {}
//	virtual ~AxisAlignedBoxSceneQuery() {}

	void setBox(const AxisAlignedBox& box) {}

//	const AxisAlignedBox& getBox(void) const {return mAABB;}

};


} // namespace

#endif
