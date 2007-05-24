

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * default constructors needed
 ******************************************************************/
#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


class EXPORT ShadowRenderable {
public:
	ShadowRenderable();
};

class EXPORT HardwareIndexBufferSharedPtr {};
class EXPORT VertexData {};

class EXPORT ManualObject {
public:
	class EXPORT ManualObjectSectionShadowRenderable : public ShadowRenderable {
	public:
			ManualObjectSectionShadowRenderable (ManualObject *parent, HardwareIndexBufferSharedPtr *indexBuffer, const VertexData* vertexData, bool createSeparateLightCap, bool isLightCap=false);
	};
};
