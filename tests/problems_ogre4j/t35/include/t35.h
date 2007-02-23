

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * inherited type with pointer as parameter
 ******************************************************************/


#include <map>
#include <string>


namespace Ogre {
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

	typedef std::string String;

	class Animation {
	};

	class SceneManager {
	protected:
	//public:
		typedef std::map<String, Animation*> AnimationList;

	public:
		typedef MapIterator<AnimationList> AnimationIterator;
		virtual const String & getTypeName (void) const =0;
	};

	class DefaultSceneManager : public SceneManager {
	public:
		DefaultSceneManager() {str = "Bulldozer";}
		AnimationIterator getAnimationIterator() {AnimationIterator a(m); return a;}
		const String & getTypeName (void) const {return str;}

	private:
		AnimationList m;
		String str;
	};
}
