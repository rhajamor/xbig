
#include "t65.h"

int main(int argc, char* argv[]) 
{
	Ogre::AMap map;
	Ogre::AConstIterator it1(map);
	Ogre::AConstIterator it2(map);
	it1 = it2;
/*
	Ogre::AIterator itNonConst(map);
	it1 = itNonConst;
*/
/*
	typedef Ogre::SharedPtr<Ogre::A> APtr;
	APtr aPtr;
	Ogre::CodecDataPtr cdPtr;
	aPtr = cdPtr;
*/
}
