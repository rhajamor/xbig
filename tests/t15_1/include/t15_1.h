/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * Ogre1.7 Test 
 * See "OgrePrerequisites.h" "OGRE_CONTAINERS_USE_CUSTOM_MEMORY_ALLOCATOR"
 *  
 *
 ******************************************************************/
#include <vector>

	class GeneralAllocPolicy;
	template<typename T, typename T2>
	class STLAllocator;
	
	/**********************/
 	template <typename T, typename A = STLAllocator<T, GeneralAllocPolicy> > 
	struct vector 
	{ 
		typedef typename std::vector<T> type;    
	};

	template <typename T > 
	struct vector2 
	{ 
		typedef typename std::vector<T> type;    
	}; 

	
	/**********************/
	typedef vector<float>::type BoneBlendMask;
	typedef vector2<float>::type BoneBlendMask2;

	class test15_3
	{
		void _setBlendMask(const BoneBlendMask* blendMask);
		void _setBlendMask2(const BoneBlendMask2* blendMask);
	};