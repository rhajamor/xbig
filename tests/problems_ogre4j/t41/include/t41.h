
#ifndef __T41_H__
#define __T41_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * VectorIterator with std::list
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif



#include <list>



namespace Ogre {


    template <class T>
    class VectorIterator
    {
    private:
        typename T::iterator mCurrent;
        typename T::iterator mEnd;
        VectorIterator() {};
    public:
        typedef typename T::value_type ValueType;
        VectorIterator(typename T::iterator start, typename T::iterator end)
            : mCurrent(start), mEnd(end)
        {
        }
        explicit VectorIterator(T& c)
            : mCurrent(c.begin()), mEnd(c.end())
        {
        }
        bool hasMoreElements(void) const
        {
            return mCurrent != mEnd;
        }
        typename T::value_type getNext(void)
        {
            return *mCurrent++;
        }
        typename T::value_type peekNext(void)
        {
            return *mCurrent;
        }
        typename T::pointer peekNextPtr(void)
        {
            return &(*mCurrent);
        }
        void moveNext(void)
        {
            ++mCurrent;
        }
    };


	class OverlayContainer{};


	typedef std::list< OverlayContainer * > OverlayContainerList;
	typedef VectorIterator< OverlayContainerList > Overlay2DElementsIterator;
}


#endif
