
#ifndef __T40_H__
#define __T40_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * - std::hash_map
 * - :: at beginning of typedef basetype
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif



#include <string>
#include <hash_map>


#define HashMap ::std::hash_map


namespace Ogre {


    template <class T>
    class MapIterator
    {
    private:
        typename T::iterator mCurrent;
        typename T::iterator mEnd;
        /// Private constructor since only the parameterised constructor should be used
        MapIterator() {};
    public:/*
        typedef typename T::mapped_type MappedType;
        typedef typename T::key_type KeyType;
        MapIterator(typename T::iterator start, typename T::iterator end)
            : mCurrent(start), mEnd(end)
        {
        }
        explicit MapIterator(T& c)
            : mCurrent(c.begin()), mEnd(c.end())
        {
        }*/
        bool hasMoreElements(void) const
        {
            return mCurrent != mEnd;
        }
        typename T::mapped_type getNext(void)
        {
            return (mCurrent++)->second;
        }/*
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
        }*/
    };



	typedef std::string _StringBase;
	typedef _StringBase String;

	class Node{};

	typedef HashMap< String, Node * > 	ChildNodeMap;
	typedef MapIterator< ChildNodeMap > ChildNodeIterator;
}


#endif
