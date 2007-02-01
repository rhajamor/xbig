

#include "t04.h"
#include <iostream>

ShadowRenderable::ShadowRenderable() {
	std::cout << "t04: ShadowRenderable::ShadowRenderable()" << std::endl;
}
ManualObject::ManualObjectSectionShadowRenderable::ManualObjectSectionShadowRenderable (ManualObject *parent, HardwareIndexBufferSharedPtr *indexBuffer, const VertexData* vertexData, bool createSeparateLightCap, bool isLightCap) {
	std::cout << "t04: ManualObject::ManualObjectSectionShadowRenderable::ManualObjectSectionShadowRenderable (ManualObject *parent, HardwareIndexBufferSharedPtr *indexBuffer, const VertexData* vertexData, bool createSeparateLightCap, bool isLightCap=false)" << std::endl;
}
