
#ifndef __T49_H__
#define __T49_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * Interface for template gets methods, see bug 1724318
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>
#include <vector>
#include <string.h>


namespace Ogre {

	typedef float Real;
	typedef std::string String;

	template <class TContainer, class TContainerValueType, typename TCompValueType>
	class RadixSort
	{
	public:
		typedef typename TContainer::iterator ContainerIter;
	protected:
		int mCounters[4][256];
		int mOffsets[256];
		int mSortSize;
		int mNumPasses;
		struct SortEntry
		{
			TCompValueType key;
			ContainerIter iter;
			SortEntry() {}
			SortEntry(TCompValueType k, ContainerIter it)
				: key(k), iter(it) {}
		};
		std::vector<SortEntry> mSortArea1;
		std::vector<SortEntry> mSortArea2;
		std::vector<SortEntry>* mSrc;
		std::vector<SortEntry>* mDest;
		TContainer mTmpContainer; // initial copy
		void sortPass(int byteIndex)
		{
			mOffsets[0] = 0;
			for (int i = 1; i < 256; ++i)
			{
				mOffsets[i] = mOffsets[i-1] + mCounters[byteIndex][i-1];
			}
			for (int i = 0; i < mSortSize; ++i)
			{
				unsigned char byteVal = getByte(byteIndex, (*mSrc)[i].key);
				(*mDest)[mOffsets[byteVal]++] = (*mSrc)[i];
			}
		}
		template <typename T>
		void finalPass(int byteIndex, T val)
		{
			sortPass(byteIndex);
		}
		void finalPass(int byteIndex, int val)
		{
			int numNeg = 0;
			for (int i = 128; i < 256; ++i)
			{
				numNeg += mCounters[byteIndex][i];
			}
			mOffsets[0] = numNeg;
			for (int i = 1; i < 128; ++i)
			{
				mOffsets[i] = mOffsets[i-1] + mCounters[byteIndex][i-1];
			}
			mOffsets[128] = 0;
			for (int i = 129; i < 256; ++i)
			{
				mOffsets[i] = mOffsets[i-1] + mCounters[byteIndex][i-1];
			}
			for (int i = 0; i < mSortSize; ++i)
			{
				unsigned char byteVal = getByte(byteIndex, (*mSrc)[i].key);
				(*mDest)[mOffsets[byteVal]++] = (*mSrc)[i];
			}
		}
		void finalPass(int byteIndex, float val)
		{
			int numNeg = 0;
			for (int i = 128; i < 256; ++i)
			{
				numNeg += mCounters[byteIndex][i];
			}
			mOffsets[0] = numNeg;
			for (int i = 1; i < 128; ++i)
			{
				mOffsets[i] = mOffsets[i-1] + mCounters[byteIndex][i-1];
			}
			mOffsets[255] = mCounters[byteIndex][255];
			for (int i = 254; i > 127; --i)
			{
				mOffsets[i] = mOffsets[i+1] + mCounters[byteIndex][i];
			}
			for (int i = 0; i < mSortSize; ++i)
			{
				unsigned char byteVal = getByte(byteIndex, (*mSrc)[i].key);
				if (byteVal > 127)
				{
					(*mDest)[--mOffsets[byteVal]] = (*mSrc)[i];
				}
				else
				{
					(*mDest)[mOffsets[byteVal]++] = (*mSrc)[i];
				}
			}
		}
		inline unsigned char getByte(int byteIndex, TCompValueType val)
		{
			return ((unsigned char*)(&val))[byteIndex];
		}
	public:
		RadixSort() {}
		~RadixSort() {}
		template <class TFunction>
		void sort(TContainer& container, TFunction func)
		{
			if (container.empty())
				return;
			mSortSize = static_cast<int>(container.size());
			mSortArea1.resize(container.size());
			mSortArea2.resize(container.size());
			mTmpContainer = container;
			mNumPasses = sizeof(TCompValueType);
			int p;
			for (p = 0; p < mNumPasses; ++p)
				memset(mCounters[p], 0, sizeof(int) * 256);
			ContainerIter i = mTmpContainer.begin();
			TCompValueType prevValue = func.operator()(*i);
			bool needsSorting = false;
			for (int u = 0; i != mTmpContainer.end(); ++i, ++u)
			{
				TCompValueType val = func.operator()(*i);
				if (!needsSorting && val < prevValue)
					needsSorting = true;
				mSortArea1[u].key = val;
				mSortArea1[u].iter = i;
				for (p = 0; p < mNumPasses; ++p)
				{
					unsigned char byteVal = getByte(p, val);
					mCounters[p][byteVal]++;
				}
				prevValue = val;
			}
			if (!needsSorting)
				return;
			mSrc = &mSortArea1;
			mDest = &mSortArea2;
			for (p = 0; p < mNumPasses - 1; ++p)
			{
				sortPass(p);
				std::vector<SortEntry>* tmp = mSrc;
				mSrc = mDest;
				mDest = tmp;
			}
			finalPass(p, prevValue);
			int c = 0;
			for (i = container.begin();
				i != container.end(); ++i, ++c)
			{
				*i = *((*mDest)[c].iter);
			}
		}
	};
}

#endif
