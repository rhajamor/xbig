
#ifndef __T44_H__
#define __T44_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * template inside class
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <algorithm>
#include <typeinfo>


namespace Ogre {

    class Any
    {
    public:
        Any()
          : mContent(0)
        {
        }
        template<typename ValueType>
        explicit Any(const ValueType & value)
          : mContent(new holder<ValueType>(value))
        {
        }
        Any(const Any & other)
          : mContent(other.mContent ? other.mContent->clone() : 0)
        {
        }
        virtual ~Any()
        {
            delete mContent;
        }
    public:
        Any& swap(Any & rhs)
        {
            std::swap(mContent, rhs.mContent);
            return *this;
        }
        template<typename ValueType>
        Any& operator=(const ValueType & rhs)
        {
            Any(rhs).swap(*this);
            return *this;
        }
        Any & operator=(const Any & rhs)
        {
            Any(rhs).swap(*this);
            return *this;
        }
    public:
        bool isEmpty() const
        {
            return !mContent;
        }
        const std::type_info& getType() const
        {
            return mContent ? mContent->getType() : typeid(void);
        }
		inline friend std::ostream& operator <<
			( std::ostream& o, const Any& v )
		{
			if (v.mContent)
				v.mContent->writeToStream(o);
			return o;
		}
    protected:
        class placeholder
        {
        public:
            virtual ~placeholder()
            {
            }
        public:
            virtual const std::type_info& getType() const = 0;
            virtual placeholder * clone() const = 0;
			virtual void writeToStream(std::ostream& o) = 0;
        };
        template<typename ValueType>
        class holder : public placeholder
        {
        public:
            holder(const ValueType & value)
              : held(value)
            {
            }
        public:
            virtual const std::type_info & getType() const
            {
                return typeid(ValueType);
            }
            virtual placeholder * clone() const
            {
                return new holder(held);
            }
			virtual void writeToStream(std::ostream& o)
			{
				o << held;
			}
        public:
            ValueType held;
        };
    protected:
        placeholder * mContent;
        template<typename ValueType>
        friend ValueType * any_cast(Any *);
    public: 
	    template<typename ValueType>
    	ValueType operator()() const
    	{
			if (!mContent) 
			{
//				OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
//					"Bad cast from uninitialised Any", 
//					"Any::operator()");
			}
			else if(getType() == typeid(ValueType))
			{
             	return static_cast<Any::holder<ValueType> *>(mContent)->held;
			}
			else
			{
//				StringUtil::StrStreamType str;
//				str << "Bad cast from type '" << getType().name() << "' "
//					<< "to '" << typeid(ValueType).name() << "'";
//				OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
//					 str.str(), 
//					"Any::operator()");
			}
		}
    };
}

#endif
