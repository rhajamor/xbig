
#include "t04.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
   ManualObject * parent;
   HardwareIndexBufferSharedPtr *indexBuffer;
   VertexData* vertexData;

   ManualObject::ManualObjectSectionShadowRenderable::ManualObjectSectionShadowRenderable a(parent, indexBuffer, vertexData, false);

   std::cout << "done" << std::endl;
}
