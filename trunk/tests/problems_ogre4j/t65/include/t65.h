
#ifndef __T65_H__
#define __T65_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * assignment operators of templates
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <map>
#include <string>
#include <iostream>
#include <assert.h>


namespace Ogre {


	template <class T>
	class EXPORT MapIterator
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



    template <class T>
    class ConstMapIterator
    {
    private:
        mutable typename T::const_iterator mCurrent;
        typename T::const_iterator mEnd;
        ConstMapIterator() {};
    public:
        typedef typename T::mapped_type MappedType;
        typedef typename T::key_type KeyType;
        ConstMapIterator(typename T::const_iterator start, typename T::const_iterator end)
            : mCurrent(start), mEnd(end)
        {
        }
        explicit ConstMapIterator(const T& c)
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
        typename T::mapped_type peekNextValue(void) const
        {
            return mCurrent->second;
        }
        typename T::key_type peekNextKey(void) const
        {
            return mCurrent->first;
        }
        /** Required to overcome intermittent bug */
        //ConstMapIterator<T> & operator=( ConstMapIterator<T> &rhs )
        MapIterator<T> & operator=( MapIterator<T> &rhs )
        {
        	std::cout << "MapIterator<T> & operator=( MapIterator<T> &rhs )" << std::endl;
            mCurrent = rhs.mCurrent;
            mEnd = rhs.mEnd;
            return *this;
        }
        const typename T::mapped_type* peekNextValuePtr(void) const
        {
            return &(mCurrent->second);
        }
        void moveNext(void) const
        {
            ++mCurrent;
        }        
    };


	class EXPORT A {
		int m;
	public:
		A(int val = 0) {m = val;}
		void setM(int val) {m = val;}
		int getM() {return m;}
	};

	typedef std::map<std::string, A> AMap;
	typedef ConstMapIterator<AMap> AConstIterator;
	typedef MapIterator<AMap> AIterator;


////////////////////////////////////////////////////////////////////////////////////////////////////


	#define OGRE_AUTO_MUTEX
	#define OGRE_LOCK_AUTO_MUTEX
	#define OGRE_MUTEX(name)
	#define OGRE_LOCK_MUTEX(name)
	#define OGRE_LOCK_MUTEX_NAMED(mutexName, lockName)
	#define OGRE_AUTO_SHARED_MUTEX
	#define OGRE_LOCK_AUTO_SHARED_MUTEX
	#define OGRE_NEW_AUTO_SHARED_MUTEX
	#define OGRE_DELETE_AUTO_SHARED_MUTEX
	#define OGRE_COPY_AUTO_SHARED_MUTEX(from)
	#define OGRE_SET_AUTO_SHARED_MUTEX_NULL
	#define OGRE_MUTEX_CONDITIONAL(name) if(true)
	#define OGRE_THREAD_SYNCHRONISER(sync) 
	#define OGRE_THREAD_WAIT(sync, lock) 
	#define OGRE_THREAD_NOTIFY_ONE(sync) 
	#define OGRE_THREAD_NOTIFY_ALL(sync) 
	#define OGRE_THREAD_POINTER(T, var) T* var
	#define OGRE_THREAD_POINTER_SET(var, expr) var = expr
	#define OGRE_THREAD_POINTER_DELETE(var) delete var; var = 0
	#define OGRE_THREAD_POINTER_GET(var) var



    template<class T> class SharedPtr {
	protected:
		T* pRep;
		unsigned int* pUseCount;
	public:
		OGRE_AUTO_SHARED_MUTEX // public to allow external locking
		SharedPtr() : pRep(0), pUseCount(0)
        {
            OGRE_SET_AUTO_SHARED_MUTEX_NULL
        }
        template< class Y>
		explicit SharedPtr(Y* rep) : pRep(rep), pUseCount(new unsigned int(1))
		{
            OGRE_SET_AUTO_SHARED_MUTEX_NULL
			OGRE_NEW_AUTO_SHARED_MUTEX
		}
		SharedPtr(const SharedPtr& r)
            : pRep(0), pUseCount(0)
		{
            OGRE_SET_AUTO_SHARED_MUTEX_NULL
            OGRE_MUTEX_CONDITIONAL(r.OGRE_AUTO_MUTEX_NAME)
            {
			    OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
			    OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
			    pRep = r.pRep;
			    pUseCount = r.pUseCount; 
			    if(pUseCount)
			    {
				    ++(*pUseCount); 
			    }
            }
		}
		SharedPtr& operator=(const SharedPtr& r) {
			if (pRep == r.pRep)
				return *this;
			release();
            OGRE_MUTEX_CONDITIONAL(r.OGRE_AUTO_MUTEX_NAME)
            {
			    OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
			    OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
			    pRep = r.pRep;
			    pUseCount = r.pUseCount;
			    if (pUseCount)
			    {
				    ++(*pUseCount);
			    }
            }
			else
			{
				assert(r.isNull() && "RHS must be null if it has no mutex!");
				setNull();
			}
			return *this;
		}
		template< class Y>
		SharedPtr(const SharedPtr<Y>& r)
            : pRep(0), pUseCount(0)
		{
            OGRE_SET_AUTO_SHARED_MUTEX_NULL
            OGRE_MUTEX_CONDITIONAL(r.OGRE_AUTO_MUTEX_NAME)
            {
			    OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
			    OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
			    pRep = r.getPointer();
			    pUseCount = r.useCountPointer();
			    if(pUseCount)
			    {
				    ++(*pUseCount);
			    }
            }
		}
		template< class Y>
		SharedPtr& operator=(const SharedPtr<Y>& r) {
			if (pRep == r.pRep)
				return *this;
			release();
            OGRE_MUTEX_CONDITIONAL(r.OGRE_AUTO_MUTEX_NAME)
            {
			    OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
			    OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
			    pRep = r.getPointer();
			    pUseCount = r.useCountPointer();
			    if (pUseCount)
			    {
				    ++(*pUseCount);
			    }
            }
			return *this;
		}
		virtual ~SharedPtr() {
            release();
		}
		inline T& operator*() const { assert(pRep); return *pRep; }
		inline T* operator->() const { assert(pRep); return pRep; }
		inline T* get() const { return pRep; }
		void bind(T* rep) {
			assert(!pRep && !pUseCount);
            OGRE_NEW_AUTO_SHARED_MUTEX
			OGRE_LOCK_AUTO_SHARED_MUTEX
			pUseCount = new unsigned int(1);
			pRep = rep;
		}
		inline bool unique() const { OGRE_LOCK_AUTO_SHARED_MUTEX assert(pUseCount); return *pUseCount == 1; }
		inline unsigned int useCount() const { OGRE_LOCK_AUTO_SHARED_MUTEX assert(pUseCount); return *pUseCount; }
		inline unsigned int* useCountPointer() const { return pUseCount; }
		inline T* getPointer() const { return pRep; }
		inline bool isNull(void) const { return pRep == 0; }
        inline void setNull(void) { 
			if (pRep)
			{
				release();
				pRep = 0;
				pUseCount = 0;
			}
        }
    protected:
        inline void release(void)
        {
			bool destroyThis = false;
            OGRE_MUTEX_CONDITIONAL(OGRE_AUTO_MUTEX_NAME)
			{
				// lock own mutex in limited scope (must unlock before destroy)
				OGRE_LOCK_AUTO_SHARED_MUTEX
				if (pUseCount)
				{
					if (--(*pUseCount) == 0) 
					{
						destroyThis = true;
	                }
				}
            }
			if (destroyThis)
				destroy();
            OGRE_SET_AUTO_SHARED_MUTEX_NULL
        }
        virtual void destroy(void)
        {
            delete pRep;
            delete pUseCount;
			OGRE_DELETE_AUTO_SHARED_MUTEX
        }
	};

	class EXPORT CodecData {
		int m;
	public:
		CodecData(int val = 0) {m = val;}
		void setM(int val) {m = val;}
		int getM() {return m;}
	};

	typedef SharedPtr<CodecData> CodecDataPtr;
}
#endif
