

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * default constructors needed
 ****************************************************************************************************************/


class ShadowRenderable {
public:
	ShadowRenderable();
};

class HardwareIndexBufferSharedPtr {};
class VertexData {};

class ManualObject {
public:
	class ManualObjectSectionShadowRenderable : public ShadowRenderable {
	public:
			ManualObjectSectionShadowRenderable (ManualObject *parent, HardwareIndexBufferSharedPtr *indexBuffer, const VertexData* vertexData, bool createSeparateLightCap, bool isLightCap=false);
	};
};
