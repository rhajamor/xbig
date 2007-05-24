

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * template_function
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <iostream>

class EXPORT Bitwise {
public:
	template<typename SrcT, typename DestT>
	static DestT convertBitPattern ( SrcT srcValue, SrcT srcBitMask, DestT destBitMask) ;
};

template<typename SrcT, typename DestT>
DestT Bitwise::convertBitPattern(SrcT srcValue, SrcT srcBitMask, DestT destBitMask) {
	std::cout << "Bitwise::convertBitPattern(SrcT srcValue, SrcT srcBitMask, DestT destBitMask)" << std::endl;
	std::cout << "SrcT: " << typeid(srcValue).name() << std::endl;
	std::cout << "DestT: " << typeid(destBitMask).name() << std::endl;
	return destBitMask;
}
