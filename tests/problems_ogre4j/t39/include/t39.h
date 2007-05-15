
#ifndef __T39_H__
#define __T39_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * ???
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif



//#include <string>
#include <vector>
//#include <map>



namespace Ogre {


	typedef float Real;


    template <class T>
    class ConstVectorIterator
    {
    private:
        mutable typename T::const_iterator mCurrent;
        typename T::const_iterator mEnd;
        ConstVectorIterator() {};
    public:/*
        typedef typename T::value_type ValueType;
        ConstVectorIterator(typename T::const_iterator start, typename T::const_iterator end)
            : mCurrent(start), mEnd(end)
        {
        }
        explicit ConstVectorIterator(const T& c)
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
        typename T::value_type peekNext(void) const
        {
            return *mCurrent;
        }*/
        typename T::const_pointer peekNextPtr(void) const
        {
            return &(*mCurrent);
        }
        void moveNext(void) const
        {
            ++mCurrent;
        }
    };


    class EXPORT GpuProgramParameters
    {
    public:
    
        class AutoConstantEntry
        {
        public:
//            AutoConstantType paramType;
            size_t physicalIndex;
			size_t elementCount;
			union{
				size_t data;
				Real fData;
			};
/*
            AutoConstantEntry(AutoConstantType theType, size_t theIndex, size_t theData, 
				size_t theElemCount = 4)
                : paramType(theType), physicalIndex(theIndex), elementCount(theElemCount), data(theData) {}

			AutoConstantEntry(AutoConstantType theType, size_t theIndex, Real theData, 
				size_t theElemCount = 4)
				: paramType(theType), physicalIndex(theIndex), elementCount(theElemCount), fData(theData) {}
*/
        };

		typedef std::vector<AutoConstantEntry> AutoConstantList;
		typedef ConstVectorIterator<AutoConstantList> AutoConstantIterator;
    };
}


#endif
