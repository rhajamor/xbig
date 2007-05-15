
#ifndef __T38_H__
#define __T38_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * Ogre::MapIterator with std::multimap
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif



#include <string>
#include <vector>
#include <map>


namespace Ogre {


	typedef std::string _StringBase;
	typedef _StringBase String;
	typedef std::vector<String> StringVector;


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



    class EXPORT StringUtil
    {
	public:
//        typedef std::ostringstream StrStreamType;
//        static void trim( String& str, bool left = true, bool right = true ) {}
//		static std::vector< String > split( const String& str, const String& delims = "\t\n ", unsigned int maxSplits = 0) {std::vector< String > vec; return vec;}
//        static void toLowerCase( String& str ) {}
//        static void toUpperCase( String& str ) {}
//        static bool startsWith(const String& str, const String& pattern, bool lowerCase = true) {return false;}
//        static bool endsWith(const String& str, const String& pattern, bool lowerCase = true) {return false;}
//        static String standardisePath( const String &init) {return init;}
//        static void splitFilename(const String& qualifiedName,
//            String& outBasename, String& outPath) {}
//        static bool match(const String& str, const String& pattern, bool caseSensitive = true) {return false;}
//        static const String BLANK;
    };



    template<class T> class SharedPtr {
	protected:
		T* pRep;
		unsigned int* pUseCount;
	public:
/*		OGRE_AUTO_SHARED_MUTEX // public to allow external locking
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
*/	};



	class EXPORT DataStream
	{/*
	protected:
		String mName;		
        size_t mSize;
        #define OGRE_STREAM_TEMP_SIZE 128
	public:
        DataStream() : mSize(0) {}
		DataStream(const String& name) : mName(name), mSize(0) {}
		const String& getName(void) { return mName; }
        virtual ~DataStream() {}
        template<typename T> DataStream& operator>>(T& val);
		virtual size_t read(void* buf, size_t count) = 0;
		virtual size_t readLine(char* buf, size_t maxCount, const String& delim = "\n");
	    virtual String getLine( bool trimAfter = true );
	    virtual String getAsString(void);
		virtual size_t skipLine(const String& delim = "\n");
		virtual void skip(long count) = 0;
	    virtual void seek( size_t pos ) = 0;
	    virtual size_t tell(void) const = 0;
	    virtual bool eof(void) const = 0;
        size_t size(void) const { return mSize; }
        virtual void close(void) = 0;
*/	};
/*
	typedef SharedPtr<DataStream> DataStreamPtr;
	typedef std::list<DataStreamPtr> DataStreamList;
	typedef SharedPtr<DataStreamList> DataStreamListPtr;

	class EXPORT MemoryDataStream : public DataStream
	{
	protected:
	    uchar* mData;
	    uchar* mPos;
	    uchar* mEnd;
		bool mFreeOnClose;			
	public:
		MemoryDataStream(void* pMem, size_t size, bool freeOnClose = false);
		MemoryDataStream(const String& name, void* pMem, size_t size, 
				bool freeOnClose = false);
		MemoryDataStream(DataStream& sourceStream, 
				bool freeOnClose = true);
		MemoryDataStream(DataStreamPtr& sourceStream, 
				bool freeOnClose = true);
		MemoryDataStream(const String& name, DataStream& sourceStream, 
				bool freeOnClose = true);
        MemoryDataStream(const String& name, const DataStreamPtr& sourceStream, 
            bool freeOnClose = true);
		MemoryDataStream(size_t size, bool freeOnClose = true);
		MemoryDataStream(const String& name, size_t size, 
				bool freeOnClose = true);
		~MemoryDataStream();
		uchar* getPtr(void) { return mData; }
		uchar* getCurrentPtr(void) { return mPos; }
		size_t read(void* buf, size_t count);
		size_t readLine(char* buf, size_t maxCount, const String& delim = "\n");
		size_t skipLine(const String& delim = "\n");
		void skip(long count);
	    void seek( size_t pos );
	    size_t tell(void) const;
	    bool eof(void) const;
        void close(void);
		void setFreeOnClose(bool free) { mFreeOnClose = free; }
	};
*/


//	typedef SharedPtr<DataStream> DataStreamPtr;



    class EXPORT ConfigFile
    {
    public:
/*
        ConfigFile() {}
        virtual ~ConfigFile() {}
        /// load from a filename (not using resource group locations)
        void load(const String& filename, const String& separators = "\t:=", bool trimWhitespace = true) {}
        /// load from a filename (using resource group locations)
        void load(const String& filename, const String& resourceGroup, const String& separators = "\t:=", bool trimWhitespace = true) {}
        /// load from a data stream
        void load(const DataStreamPtr& stream, const String& separators = "\t:=", bool trimWhitespace = true) {}
		/// load from a filename (not using resource group locations)
		void loadDirect(const String& filename, const String& separators = "\t:=", bool trimWhitespace = true) {}
		/// load from a filename (using resource group locations)
		void loadFromResourceSystem(const String& filename, const String& resourceGroup, const String& separators = "\t:=", bool trimWhitespace = true) {}
*/
        /** Gets the first setting from the file with the named key. 
        @param key The name of the setting
        @param section The name of the section it must be in (if any)
        */
//        String getSetting(const String& key, const String& section = StringUtil::BLANK) const {return key;}
        /** Gets all settings from the file with the named key. */
//        StringVector getMultiSetting(const String& key, const String& section = StringUtil::BLANK) const {StringVector sv; return sv;}

        typedef std::multimap<String, String> SettingsMultiMap;
        typedef MapIterator<SettingsMultiMap> SettingsIterator;
        /** Gets an iterator for stepping through all the keys / values in the file. */
        typedef std::map<String, SettingsMultiMap*> SettingsBySection;
        typedef MapIterator<SettingsBySection> SectionIterator;
        /** Get an iterator over all the available sections in the config file */
//        SectionIterator getSectionIterator(void) {SectionIterator si(mSettings); return si;}
        /** Get an iterator over all the available settings in a section */
//        SettingsIterator getSettingsIterator(const String& section = StringUtil::BLANK) {SettingsMultiMap smm; SettingsIterator si(smm); return si;}


        
        /** Clear the settings */
//        void clear(void) {}
    protected:
        SettingsBySection mSettings;
    };

}


#endif
