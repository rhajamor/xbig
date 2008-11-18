

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

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <map>
#include <string>
#include <typeinfo>


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

	typedef std::string String;

	class EXPORT Animation {
	};

	class EXPORT SceneManager {
	protected:
	//public:
		typedef std::map<String, Animation*> AnimationList;

		typedef std::map<String, const Animation> ConstAnimationList;
		typedef std::map<String, const Animation*> ConstAnimationPointerList;

	public:
		typedef MapIterator<AnimationList> AnimationIterator;
		virtual const String & getTypeName (void) const =0;

		typedef MapIterator<ConstAnimationList> ConstAnimationIterator;
		typedef MapIterator<ConstAnimationPointerList> ConstAnimationPointerIterator;
	};

	class EXPORT ConcreteSceneManager : public SceneManager {
	public:

		ConcreteSceneManager() {
			str = "Bulldozer";
			ai = new AnimationIterator(m);
			cai = new ConstAnimationIterator(mcal);
			capi = new ConstAnimationPointerIterator(mcapl);
		}

		ConcreteSceneManager(const ConcreteSceneManager& dsm) {
			str = "Bulldozer";
			ai = new AnimationIterator(m);
			cai = new ConstAnimationIterator(mcal);
			capi = new ConstAnimationPointerIterator(mcapl);
		}

		virtual ~ConcreteSceneManager() {
			delete ai;
			delete cai;
			delete capi;
		}

		AnimationIterator getAnimationIterator() {return *ai;}
		const String & getTypeName (void) const {return str;}

		ConstAnimationIterator getConstAnimationIterator() {return *cai;}
		ConstAnimationPointerIterator getConstAnimationPointerIterator() {return *capi;}

	private:
		AnimationList m;
		AnimationIterator* ai;
		String str;

		ConstAnimationList mcal;
		ConstAnimationPointerList mcapl;
		ConstAnimationIterator* cai;
		ConstAnimationPointerIterator* capi;
	};
}
