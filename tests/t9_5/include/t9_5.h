/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles unnamed enums
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <vector>


enum
{
    ENUM
};


namespace n {


	enum
	{
	    ENUM
	};



	typedef float Real;
	class VertexDeclaration{};
	class AxisAlignedBox{};
	class HardwareVertexBufferSharedPtr{};
	class HardwareIndexBufferSharedPtr{};
	class Vector3{};


    class EXPORT A
    {
    public:
        A() {}
        ~A() {}
        enum PatchSurfaceType
        {
            PST_BEZIER
        };
        enum
        {
            AUTO_LEVEL = -1
        };
        enum VisibleSide {
            VS_FRONT,
            VS_BACK,
            VS_BOTH
        };
        void defineSurface(void* controlPointBuffer, 
            VertexDeclaration *declaration, size_t width, size_t height,
            PatchSurfaceType pType = PST_BEZIER, 
            size_t uMaxSubdivisionLevel = AUTO_LEVEL, size_t vMaxSubdivisionLevel = AUTO_LEVEL,
            VisibleSide visibleSide = VS_FRONT) {}
        size_t getRequiredVertexCount(void) const {return 0;}
        size_t getRequiredIndexCount(void) const {return 0;}
        size_t getCurrentIndexCount(void) const {return 0;}
        size_t getIndexOffset(void) const { return mIndexOffset; }
        size_t getVertexOffset(void) const { return mVertexOffset; }
        const AxisAlignedBox& getBounds(void) const {return mAABB;}
        Real getBoundingSphereRadius(void) const {return 0.0;}
        void build(HardwareVertexBufferSharedPtr destVertexBuffer, size_t vertexStart,
            HardwareIndexBufferSharedPtr destIndexBuffer, size_t indexStart) {}
        void setSubdivisionFactor(Real factor) {}
        Real getSubdivisionFactor(void) const {return 0.0;}
        void* getControlPointBuffer(void) const
        {
            return mControlPointBuffer;
        }
        void notifyControlPointBufferDeallocated(void) { 
            mControlPointBuffer = 0;
        }
    protected:
        VertexDeclaration* mDeclaration;
        void* mControlPointBuffer;
        PatchSurfaceType mType;
        size_t mCtlWidth;
        size_t mCtlHeight;
        size_t mCtlCount;
        size_t mULevel;
        size_t mVLevel;
        size_t mMaxULevel;
        size_t mMaxVLevel;
        size_t mMeshWidth;
        size_t mMeshHeight;
        VisibleSide mVSide;
        Real mSubdivisionFactor;
        std::vector<Vector3> mVecCtlPoints;
        size_t findLevel( Vector3& a, Vector3& b, Vector3& c);
        void distributeControlPoints(void* lockedBuffer);
        void subdivideCurve(void* lockedBuffer, size_t startIdx, size_t stepSize, size_t numSteps, size_t iterations);
        void interpolateVertexData(void* lockedBuffer, size_t leftIndex, size_t rightIndex, size_t destIndex);
        void makeTriangles(void);
        size_t getAutoULevel(bool forMax = false);
        size_t getAutoVLevel(bool forMax = false);
        HardwareVertexBufferSharedPtr mVertexBuffer;
        HardwareIndexBufferSharedPtr mIndexBuffer;
        size_t mVertexOffset;
        size_t mIndexOffset;
        size_t mRequiredVertexCount;
        size_t mRequiredIndexCount;
        size_t mCurrIndexCount;
        AxisAlignedBox mAABB;
        Real mBoundingSphere;
    };
}
