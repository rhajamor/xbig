/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It tests the stl wrapper
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#include <string>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <set>
#ifdef __GNUC__
	#include <ext/hash_map>
	namespace __gnu_cxx
	{
	        template<> struct hash< std::string >
	        {
	                size_t operator()( const std::string& x ) const
	                {
	                        return hash< const char* >()( x.c_str() );
	                }
	        };
	}
#else
	#include <hash_map>
#endif
//#include <bitset>


class EXPORT A {
public:
};


typedef std::vector<std::string>         StringVector;
typedef std::map<std::string, A>         AMap;
typedef std::deque<std::string>          StringDeque;
typedef std::list<std::string>           StringList;
typedef std::priority_queue<std::string> StringPriorityQueue;
typedef std::queue<std::string>          StringQueue;
typedef std::stack<std::string>          StringStack;
typedef std::set<std::string>            StringSet;
typedef std::multiset<std::string>       StringMultiset;
typedef std::multimap<std::string, A>    AMultimap;
typedef std::pair<std::string, A>   	 APair;
#ifdef __GNUG__
	typedef __gnu_cxx::hash_map<std::string, A> AHashMap;
#else
	typedef std::hash_map<std::string, A> AHashMap;
#endif
//typedef std::bitset<unsigned int>        IntBitset;
