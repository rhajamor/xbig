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
#include <hash_map>
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
typedef std::hash_map<std::string, A>    AHashMap;
//typedef std::bitset<unsigned int>        IntBitset;
