

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * typedef for type parameter member
 ****************************************************************************************************************/


template <class TContainer, class TContainerValueType, typename TCompValueType>
class RadixSort {
public:
	typedef typename TContainer::iterator ContainerIter;
};
