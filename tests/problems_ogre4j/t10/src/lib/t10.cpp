

#include "t10.h"
#include <iostream>

RenderWindow* Root::createRenderWindow  	(
		const String &   	 name,
		unsigned int  	width,
		unsigned int  	height,
		bool  	fullScreen,
		const NameValuePairList *  	miscParams) {
	std::cout << "t10: Root::createRenderWindow()" << std::endl;
	std::cout << "width: " << width << std::endl;
	std::cout << "height: " << height << std::endl;

	RenderWindow* a;
	return a;
}

SceneManager* Root::createSceneManager  	(
		SceneTypeMask   	 typeMask,
		const String &  	instanceName	) {
	std::cout << "t10: Root::createSceneManager()" << std::endl;
	std::cout << "typeMask: " << typeMask << std::endl;

	SceneManager* a;
	return a;
}

const String StringUtil::BLANK = "";
