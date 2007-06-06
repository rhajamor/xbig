
#ifndef __T53_H__
#define __T53_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * Inhertance from a template, see bug 1728990
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <assert.h>


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


namespace Ogre {

	class EXPORT Resource {};
	class EXPORT Texture : public Resource {};


	template<class T> class EXPORT SharedPtr {
	protected:
		T* pRep;
		unsigned int* pUseCount;
	public:
		OGRE_AUTO_SHARED_MUTEX // public to allow external locking
		/** Constructor, does not initialise the SharedPtr.
			@remarks
				<b>Dangerous!</b> You have to call bind() before using the SharedPtr.
		*/
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
			// lock & copy other mutex pointer
            
            OGRE_SET_AUTO_SHARED_MUTEX_NULL
            OGRE_MUTEX_CONDITIONAL(r.OGRE_AUTO_MUTEX_NAME)
            {
			    OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
			    OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
			    pRep = r.pRep;
			    pUseCount = r.pUseCount; 
			    // Handle zero pointer gracefully to manage STL containers
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
			// lock & copy other mutex pointer
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
				// RHS must be a null pointer
				assert(r.isNull() && "RHS must be null if it has no mutex!");
				setNull();
			}
			return *this;
		}
		
		template< class Y>
		SharedPtr(const SharedPtr<Y>& r)
            : pRep(0), pUseCount(0)
		{
			// lock & copy other mutex pointer

            OGRE_SET_AUTO_SHARED_MUTEX_NULL
            OGRE_MUTEX_CONDITIONAL(r.OGRE_AUTO_MUTEX_NAME)
            {
			    OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
			    OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
			    pRep = r.getPointer();
			    pUseCount = r.useCountPointer();
			    // Handle zero pointer gracefully to manage STL containers
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
			// lock & copy other mutex pointer
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

		/** Binds rep to the SharedPtr.
			@remarks
				Assumes that the SharedPtr is uninitialised!
		*/
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
				// can't scope lock mutex before release incase deleted
				release();
				pRep = 0;
				pUseCount = 0;
			}
        }

    protected:

        inline void release(void)
        {
			bool destroyThis = false;

            /* If the mutex is not initialized to a non-zero value, then
               neither is pUseCount nor pRep.
             */

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
            // IF YOU GET A CRASH HERE, YOU FORGOT TO FREE UP POINTERS
            // BEFORE SHUTTING OGRE DOWN
            // Use setNull() before shutdown or make sure your pointer goes
            // out of scope before OGRE shuts down to avoid this.
            delete pRep;
            delete pUseCount;
			OGRE_DELETE_AUTO_SHARED_MUTEX
        }
	};


	typedef SharedPtr<Resource> ResourcePtr;


   class EXPORT TexturePtr : public SharedPtr<Texture> 
    {
    public:
        TexturePtr() : SharedPtr<Texture>() {}
        explicit TexturePtr(Texture* rep) : SharedPtr<Texture>(rep) {}
        TexturePtr(const TexturePtr& r) : SharedPtr<Texture>(r) {} 
        TexturePtr(const ResourcePtr& r) : SharedPtr<Texture>()
        {
			// lock & copy other mutex pointer
            OGRE_MUTEX_CONDITIONAL(r.OGRE_AUTO_MUTEX_NAME)
            {
			    OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
			    OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
                pRep = static_cast<Texture*>(r.getPointer());
                pUseCount = r.useCountPointer();
                if (pUseCount)
                {
                    ++(*pUseCount);
                }
            }
        }

        /// Operator used to convert a ResourcePtr to a TexturePtr
        TexturePtr& operator=(const ResourcePtr& r)
        {
            if (pRep == static_cast<Texture*>(r.getPointer()))
                return *this;
            release();
			// lock & copy other mutex pointer
            OGRE_MUTEX_CONDITIONAL(r.OGRE_AUTO_MUTEX_NAME)
            {
			    OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
			    OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
                pRep = static_cast<Texture*>(r.getPointer());
                pUseCount = r.useCountPointer();
                if (pUseCount)
                {
                    ++(*pUseCount);
                }
            }
			else
			{
				// RHS must be a null pointer
				assert(r.isNull() && "RHS must be null if it has no mutex!");
				setNull();
			}
            return *this;
        }
    };

}

#endif
