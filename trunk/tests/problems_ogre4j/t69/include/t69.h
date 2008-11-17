
#ifndef __T69_H__
#define __T69_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * OGRE 1.6 customized allocators
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#include <stdlib.h>
#include <memory>
#include <limits>
#include <string>

namespace Ogre {

	class EXPORT StdAllocPolicy
	{
	public:
		static inline void* allocateBytes(size_t count,
			const char* file = 0, int line = 0, const char* func = 0)
		{
			void* ptr = malloc(count);
			return ptr;
		}

		static inline void deallocateBytes(void* ptr)
		{
			free(ptr);
		}

		/// Get the maximum size of a single allocation
		static inline size_t getMaxAllocationSize()
		{
			return std::numeric_limits<size_t>::max();
		}
	private:
		// no instantiation
		StdAllocPolicy()
		{ }

	};

	#define OGRE_SIMD_ALIGNMENT  16

	class EXPORT AlignedMemory
	{
	public:
        static void* allocate(size_t size, size_t alignment)
        {
			//assert(0 < alignment && alignment <= 128 && Bitwise::isPO2(alignment));

			unsigned char* p = new unsigned char[size + alignment];
			size_t offset = alignment - (size_t(p) & (alignment-1));

			unsigned char* result = p + offset;
			result[-1] = (unsigned char)offset;

			return result;
		}

        static void* allocate(size_t size)
		{
			return allocate(size, OGRE_SIMD_ALIGNMENT);
		}

        static void deallocate(void* p)
        {
            if (p)
            {
                unsigned char* mem = (unsigned char*)p;
                mem = mem - mem[-1];
                delete [] mem;
            }
        }
	};

	template <size_t Alignment = 0>
	class StdAlignedAllocPolicy
	{
	public:
		// compile-time check alignment is available.
		typedef int IsValidAlignment
			[Alignment <= 128 && ((Alignment & (Alignment-1)) == 0) ? +1 : -1];

		static inline void* allocateBytes(size_t count,
			const char* file = 0, int line = 0, const char* func = 0)
		{
			void* ptr = Alignment ? AlignedMemory::allocate(count, Alignment)
				: AlignedMemory::allocate(count);
			// avoid unused params warning
			file;line;func;
			return ptr;
		}

		static inline void deallocateBytes(void* ptr)
		{
			AlignedMemory::deallocate(ptr);
		}

		/// Get the maximum size of a single allocation
		static inline size_t getMaxAllocationSize()
		{
			return std::numeric_limits<size_t>::max();
		}
	private:
		// No instantiation
		StdAlignedAllocPolicy()
		{ }
	};

	enum MemoryCategory
	{
		/// General purpose
		MEMCATEGORY_GENERAL = 0,
		/// Geometry held in main memory
		MEMCATEGORY_GEOMETRY = 1,
		/// Animation data like tracks, bone matrices
		MEMCATEGORY_ANIMATION = 2,
		/// Nodes, control data
		MEMCATEGORY_SCENE_CONTROL = 3,
		/// Scene object instances
		MEMCATEGORY_SCENE_OBJECTS = 4,
		/// Other resources
		MEMCATEGORY_RESOURCE = 5,
		/// Scripting
		MEMCATEGORY_SCRIPTING = 6,
		/// Rendersystem structures
		MEMCATEGORY_RENDERSYS = 7,


		// sentinel value, do not use
		MEMCATEGORY_COUNT = 8
	};

	template <MemoryCategory Cat> class CategorisedAllocPolicy : public StdAllocPolicy{};
	template <MemoryCategory Cat, size_t align = 0> class CategorisedAlignAllocPolicy : public StdAlignedAllocPolicy<align>{};

	typedef CategorisedAllocPolicy<MEMCATEGORY_ANIMATION> AnimationAllocPolicy;

	template <class Alloc>
	class EXPORT AllocatedObject
	{
	public:
		void* operator new[] ( size_t sz, const char* file, int line, const char* func )
		{
			return Alloc::allocateBytes(sz, file, line, func);
		}
		void operator delete[] ( void* ptr, const char* , int , const char*  )
		{
			Alloc::deallocateBytes(ptr);
		}
	};

	typedef AllocatedObject<AnimationAllocPolicy> AnimationAllocatedObject;
	typedef AnimationAllocatedObject AnimationAlloc;

	class EXPORT Animation : public AnimationAlloc
	{
	public:
		Animation(const std::string & name, float length){}
	};

}

#endif
