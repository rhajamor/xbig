

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * template function in template class
 ******************************************************************/



#include <iostream>

template <class TContainer, class TContainerValueType, typename TCompValueType>
class RadixSort {
public:
	template <class TFunction>
	void sort ( TContainer & container, TFunction func) {
		std::cout << "t28: RadixSort::sort(TContainer & container, TFunction func)" << std::endl;
		std::cout << "TContainer: " << typeid(container).name() << std::endl;
		//std::cout << "TContainerValueType: " << typeid().name() << std::endl;
		//std::cout << "TCompValueType: " << typeid().name() << std::endl;
		std::cout << "TFunction: " << typeid(func).name() << std::endl;
	}
};
