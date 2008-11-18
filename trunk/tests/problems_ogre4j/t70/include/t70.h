
#ifndef __T70_H__
#define __T70_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * typdef structs
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#include <map>

namespace Ogre
{
	typedef float Real;

    template <class T>
    class MapIterator
    {
    private:
        typename T::iterator mCurrent;
        typename T::iterator mEnd;
        MapIterator() {};
    public:
        typedef typename T::mapped_type MappedType;
        typedef typename T::key_type KeyType;
        MapIterator(typename T::iterator start, typename T::iterator end)
            : mCurrent(start), mEnd(end)
        {
        }
        explicit MapIterator(T& c)
            : mCurrent(c.begin()), mEnd(c.end())
        {
        }
        bool hasMoreElements(void) const
        {
            return mCurrent != mEnd;
        }
        typename T::mapped_type getNext(void)
        {
            return (mCurrent++)->second;
        }
        typename T::mapped_type peekNextValue(void)
        {
            return mCurrent->second;
        }
        typename T::key_type peekNextKey(void)
        {
            return mCurrent->first;
        }
 	    MapIterator<T> & operator=( MapIterator<T> &rhs )
 	    {
 		    mCurrent = rhs.mCurrent;
 		    mEnd = rhs.mEnd;
 		    return *this;
 	    }
        typename T::mapped_type* peekNextValuePtr(void)
        {
            return &(mCurrent->second);
        }
        void moveNext(void)
        {
            ++mCurrent;
        }
    };

    typedef struct VertexBoneAssignment_s
    {
        unsigned int vertexIndex;
        unsigned short boneIndex;
        Real weight;

    } VertexBoneAssignment;

    class EXPORT Mesh
    {
    public:
        typedef std::multimap<size_t, VertexBoneAssignment> VertexBoneAssignmentList;
        typedef MapIterator<VertexBoneAssignmentList> BoneAssignmentIterator;

        void addVertexBoneAssignment(size_t a, VertexBoneAssignment b)
        {
        	list.insert(std::make_pair<size_t, VertexBoneAssignment>(a, b));
        }

        BoneAssignmentIterator getBoneAssignmentIterator()
        {
        	return BoneAssignmentIterator(list);
        }

    private:
    	VertexBoneAssignmentList list;
    };
}

#endif
