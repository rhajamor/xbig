
#include <iostream>
#include "t35.h"

int main(int argc, char* argv[]) 
{
	Ogre::ConcreteSceneManager csm;
	Ogre::SceneManager::AnimationIterator ai1 = csm.getAnimationIterator();
	Ogre::ConcreteSceneManager::AnimationIterator ai2 = csm.getAnimationIterator();
	std::cout << "AnimationIterator 1 type: " << typeid(ai1).name() << "\n";
	std::cout << "\n";
	std::cout << "AnimationIterator 2 type: " << typeid(ai2).name() << "\n";
	std::cout << "\n";
	std::cout << "are they equal?: " << (typeid(ai1) == typeid(ai2)) << "\n";
}
