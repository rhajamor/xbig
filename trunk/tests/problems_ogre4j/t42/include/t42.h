
#ifndef __T42_H__
#define __T42_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problems:
 * - type modifier __inline
 * - ignorance of template functions
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#define FORCEINLINE   __inline


namespace Ogre {


	typedef unsigned int uint32;


    class Bitwise {
    public:
        static FORCEINLINE unsigned int mostSignificantBitSet(unsigned int value)
        {
            unsigned int result = 0;
            while (value != 0) {
                ++result;
                value >>= 1;
            }
            return result-1;
        }
        static FORCEINLINE uint32 firstPO2From(uint32 n)
        {
            --n;            
            n |= n >> 16;
            n |= n >> 8;
            n |= n >> 4;
            n |= n >> 2;
            n |= n >> 1;
            ++n;
            return n;
        }
        template<typename T>
        static FORCEINLINE bool isPO2(T n)
        {
            return (n & (n-1)) == 0;
        }
		template<typename T>
        static FORCEINLINE unsigned int getBitShift(T mask)
		{
			if (mask == 0)
				return 0;
			unsigned int result = 0;
			while ((mask & 1) == 0) {
				++result;
				mask >>= 1;
			}
			return result;
		}
    };
}

#endif
