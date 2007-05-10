
#ifndef __T37_H__
#define __T37_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problems:
 * - 'const' as part of typename (bug 1714365) (change ignore_list.xml to test this)
 * - template typedef inside template inside template (bug 1714372)
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <iostream>
#include <stdlib.h>


namespace Ogre {

	class EXPORT AlignedMemory
	{
	public:
        static void* allocate(size_t size, size_t alignment) {return malloc(size);}
        static void* allocate(size_t size) {return malloc(size);}
        static void deallocate(void* p) {free(p);}
	};

    template <typename T, unsigned Alignment = 0>
    class EXPORT AlignedAllocator
    {
        // compile-time check alignment is available.
        typedef int IsValidAlignment
            [Alignment <= 128 && ((Alignment & (Alignment-1)) == 0) ? +1 : -1];

    public:
        //--- typedefs for STL compatible

        typedef T value_type;

        typedef value_type * pointer;
        typedef const value_type * const_pointer;
        typedef value_type & reference;
        typedef const value_type & const_reference;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;

        template <typename U>
        struct rebind
        {
            typedef AlignedAllocator<U, Alignment> other;
        };

    public:/*
        AlignedAllocator() {}

        template <typename U, unsigned A>
        AlignedAllocator(const AlignedAllocator<U, A> &) {}

        static pointer address(reference r)
        { return &r; }*/
        static const_pointer address(const_reference s)
        { return &s; }/*
        static size_type max_size()
        { return (std::numeric_limits<size_type>::max)(); }
        static void construct(const pointer ptr, const value_type & t)
        { new (ptr) T(t); }
        static void destroy(const pointer ptr)
        {
            ptr->~T();
            (void) ptr; // avoid unused variable warning
        }

        bool operator==(const AlignedAllocator &) const
        { return true; }
        bool operator!=(const AlignedAllocator &) const
        { return false; }

        static pointer allocate(const size_type n)
        {
            // use default platform dependent alignment if 'Alignment' equal to zero.
            const pointer ret = static_cast<pointer>(Alignment ?
                AlignedMemory::allocate(sizeof(T) * n, Alignment) :
                AlignedMemory::allocate(sizeof(T) * n));
            return ret;
        }
        static pointer allocate(const size_type n, const void * const)
        {
            return allocate(n);
        }
        static void deallocate(const pointer ptr, const size_type)
        {
            AlignedMemory::deallocate(ptr);
        }*/
        static void test(const value_type *) {}
    };
}



#endif
