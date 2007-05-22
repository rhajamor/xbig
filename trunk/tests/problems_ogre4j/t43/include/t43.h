
#ifndef __T43_H__
#define __T43_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * protected classes / structs in public API
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
	#pragma warning (disable : 4172)
#else
	#define EXPORT
#endif


#include <vector>
#include <string>


namespace Ogre {

	typedef float Real;
	typedef std::string String;

	class Vector3{};
	class ColourValue{};
	class Camera{};
	class AxisAlignedBox{};
	class MaterialPtr{};
	class Quaternion{};
	class LightList{};
	class VertexData{};
	class IndexData{};
	class TexCoordDirection{};
	class RenderQueue{};
	class RenderOperation{};
	class Matrix4{};


	class ShadowCaster{};
	class AnimableObject{};
	class MovableObject : public AnimableObject, public ShadowCaster{};
	class Renderable{};


	class EXPORT BillboardChain : public MovableObject, public Renderable
	{
	protected:
		class EXPORT Element
		{
		public:
			Element(){}
			Element(Vector3 position,
				Real width,
				Real texCoord,
				ColourValue colour){}
			Vector3 position;
			Real width;
			Real texCoord;
			ColourValue colour;
		};
	public:
		typedef std::vector<Element> ElementList;
		BillboardChain(const String& name, size_t maxElements = 20, size_t numberOfChains = 1, 
			bool useTextureCoords = true, bool useColours = true, bool dynamic = true){}
		virtual ~BillboardChain(){}
		virtual void setMaxChainElements(size_t maxElements){}
		virtual size_t getMaxChainElements(void) const { return mMaxElementsPerChain; }
		virtual void setNumberOfChains(size_t numChains){}
		virtual size_t getNumberOfChains(void) const { return mChainCount; }
		virtual void setUseTextureCoords(bool use){}
		virtual bool getUseTextureCoords(void) const { return mUseTexCoords; }
		enum TexCoordDirection
		{
			TCD_U,
			TCD_V
		};
		virtual void setTextureCoordDirection(TexCoordDirection dir){}
		virtual TexCoordDirection getTextureCoordDirection(void) { return mTexCoordDir; }
		virtual void setOtherTextureCoordRange(Real start, Real end){}
		virtual const Real* getOtherTextureCoordRange(void) const { return mOtherTexCoordRange; }
		virtual void setUseVertexColours(bool use){}
		virtual bool getUseVertexColours(void) const { return mUseVertexColour; }
		virtual void setDynamic(bool dyn){}
		virtual bool getDynamic(void) const { return mDynamic; }
		virtual void addChainElement(size_t chainIndex, 
			const Element& billboardChainElement){}
		virtual void removeChainElement(size_t chainIndex){}
		virtual void updateChainElement(size_t chainIndex, size_t elementIndex, 
			const Element& billboardChainElement){}
		virtual const Element& getChainElement(size_t chainIndex, size_t elementIndex) const {Element e;return e;}
		virtual void clearChain(size_t chainIndex){}
		virtual void clearAllChains(void){}
		virtual const String& getMaterialName(void) const { return mMaterialName; }
		virtual void setMaterialName(const String& name){}
		void _notifyCurrentCamera(Camera* cam){}
		Real getSquaredViewDepth(const Camera* cam) const{return mOtherTexCoordRange[0];}
		Real getBoundingRadius(void) const{return mRadius;}
		const AxisAlignedBox& getBoundingBox(void) const{return mAABB;}
		const MaterialPtr& getMaterial(void) const{return mMaterial;}
		const String& getMovableType(void) const{return mMaterialName;}
		void _updateRenderQueue(RenderQueue *){}
		void getRenderOperation(RenderOperation &){}
		void getWorldTransforms(Matrix4 *) const{}
		const Quaternion& getWorldOrientation(void) const{Quaternion q;return q;}
		const Vector3& getWorldPosition(void) const{Vector3 v;return v;}
		const LightList& getLights(void) const{LightList ll;return ll;}
	protected:
		size_t mMaxElementsPerChain;
		size_t mChainCount;
		bool mUseTexCoords;
		bool mUseVertexColour;
		bool mDynamic;
		VertexData* mVertexData;
		IndexData* mIndexData;
		bool mVertexDeclDirty;
		bool mBuffersNeedRecreating;
		mutable bool mBoundsDirty;
		bool mIndexContentDirty;
		mutable AxisAlignedBox mAABB;
		mutable Real mRadius;
		String mMaterialName;
		MaterialPtr mMaterial;
		TexCoordDirection mTexCoordDir;
		Real mOtherTexCoordRange[2];
		ElementList mChainElementList;
		struct ChainSegment
		{
			size_t start;
			size_t head;
			size_t tail;
		};
		typedef std::vector<ChainSegment> ChainSegmentList;
		ChainSegmentList mChainSegmentList;
		virtual void setupChainContainers(void){}
		virtual void setupVertexDeclaration(void){}
		virtual void setupBuffers(void){}
		virtual void updateVertexBuffer(Camera* cam){}
		virtual void updateIndexBuffer(void){}
		virtual void updateBoundingBox(void) const{}
		static const size_t SEGMENT_EMPTY;
	};
}

#endif
