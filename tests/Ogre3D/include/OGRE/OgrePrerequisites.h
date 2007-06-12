/*-------------------------------------------------------------------------
This source file is a part of OGRE
(Object-oriented Graphics Rendering Engine)

For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2006 Torus Knot Software Ltd
Also see acknowledgements in Readme.html

This library is free software; you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License (LGPL) as
published by the Free Software Foundation; either version 2.1 of the
License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, write to the Free Software Foundation,
Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA or go to
http://www.gnu.org/copyleft/lesser.txt
-------------------------------------------------------------------------*/
#ifndef __OgrePrerequisites_H__
#define __OgrePrerequisites_H__

// undefine this to not require new angular units where applicable
#define OGRE_FORCE_ANGLE_TYPES

// Platform-specific stuff
#include "OgrePlatform.h"

#if OGRE_COMPILER == OGRE_COMPILER_MSVC
// Turn off warnings generated by long std templates
// This warns about truncation to 255 characters in debug/browse info
#   pragma warning (disable : 4786)

// Turn off warnings generated by long std templates
// This warns about truncation to 255 characters in debug/browse info
#   pragma warning (disable : 4503)

// disable: "conversion from 'double' to 'float', possible loss of data
#   pragma warning (disable : 4244)

// disable: "truncation from 'double' to 'float'
#   pragma warning (disable : 4305)

// disable: "<type> needs to have dll-interface to be used by clients'
// Happens on STL member variables which are not public therefore is ok
#   pragma warning (disable : 4251)

// disable: "non dll-interface class used as base for dll-interface class"
// Happens when deriving from Singleton because bug in compiler ignores
// template export
#   pragma warning (disable : 4275)

// disable: "C++ Exception Specification ignored"
// This is because MSVC 6 did not implement all the C++ exception
// specifications in the ANSI C++ draft.
#   pragma warning( disable : 4290 )

// disable: "no suitable definition provided for explicit template
// instantiation request" Occurs in VC7 for no justifiable reason on all
// #includes of Singleton
#   pragma warning( disable: 4661)

// disable: deprecation warnings when using CRT calls in VC8
// These show up on all C runtime lib code in VC8, disable since they clutter
// the warnings with things we may not be able to do anything about (e.g.
// generated code from nvparse etc). I doubt very much that these calls
// will ever be actually removed from VC anyway, it would break too much code.
#	pragma warning( disable: 4996)

// disable: "conditional expression constant", always occurs on 
// OGRE_MUTEX_CONDITIONAL when no threading enabled
#   pragma warning (disable : 201)

#endif

/* Include all the standard header *after* all the configuration
   settings have been made.
*/
//#include "OgreStdHeaders.h"


#include "OgreMemoryManager.h"

namespace Ogre {
    // Define ogre version
    #define OGRE_VERSION_MAJOR 1
    #define OGRE_VERSION_MINOR 4
    #define OGRE_VERSION_PATCH 1
	#define OGRE_VERSION_SUFFIX ""
    #define OGRE_VERSION_NAME "Eihort"

    #define OGRE_VERSION    ((OGRE_VERSION_MAJOR << 16) | (OGRE_VERSION_MINOR << 8) | OGRE_VERSION_PATCH)

    // define the real number values to be used
    // default to use 'float' unless precompiler option set
    #if OGRE_DOUBLE_PRECISION == 1
		/** Software floating point type.
		@note Not valid as a pointer to GPU buffers / parameters
		*/
        typedef double Real;
    #else
		/** Software floating point type.
		@note Not valid as a pointer to GPU buffers / parameters
		*/
        typedef float Real;
    #endif

    #if OGRE_COMPILER == OGRE_COMPILER_GNUC && OGRE_COMP_VER >= 310 && !defined(STLPORT)
    #   define HashMap ::__gnu_cxx::hash_map
    #else
    #   if OGRE_COMPILER == OGRE_COMPILER_MSVC
    #       if OGRE_COMP_VER > 1300 && !defined(_STLP_MSVC)
    #           define HashMap ::stdext::hash_map
    #       else
    #           define HashMap ::std::hash_map
    #       endif
    #   else
    #       define HashMap ::std::hash_map
    #   endif
    #endif

    /** In order to avoid finger-aches :)
    */
    typedef unsigned char uchar;
    typedef unsigned short ushort;
    typedef unsigned int uint;
	typedef unsigned long ulong;

    /// Useful macros
    #define OGRE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
    #define OGRE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }

	#if OGRE_WCHAR_T_STRINGS
		typedef std::wstring _StringBase;
	#else
		typedef std::string _StringBase;
	#endif

	typedef _StringBase String;

	// Useful threading defines
	#define OGRE_AUTO_MUTEX_NAME mutex
	#if OGRE_THREAD_SUPPORT
		#define OGRE_AUTO_MUTEX mutable boost::recursive_mutex OGRE_AUTO_MUTEX_NAME;
		#define OGRE_LOCK_AUTO_MUTEX boost::recursive_mutex::scoped_lock ogreAutoMutexLock(OGRE_AUTO_MUTEX_NAME);
		#define OGRE_MUTEX(name) mutable boost::recursive_mutex name;
		#define OGRE_STATIC_MUTEX(name) static boost::recursive_mutex name;
		#define OGRE_STATIC_MUTEX_INSTANCE(name) boost::recursive_mutex name;
		#define OGRE_LOCK_MUTEX(name) boost::recursive_mutex::scoped_lock ogrenameLock(name);
		#define OGRE_LOCK_MUTEX_NAMED(mutexName, lockName) boost::recursive_mutex::scoped_lock lockName(mutexName);
		// like OGRE_AUTO_MUTEX but mutex held by pointer
		#define OGRE_AUTO_SHARED_MUTEX mutable boost::recursive_mutex *OGRE_AUTO_MUTEX_NAME;
		#define OGRE_LOCK_AUTO_SHARED_MUTEX assert(OGRE_AUTO_MUTEX_NAME); boost::recursive_mutex::scoped_lock ogreAutoMutexLock(*OGRE_AUTO_MUTEX_NAME);
		#define OGRE_NEW_AUTO_SHARED_MUTEX assert(!OGRE_AUTO_MUTEX_NAME); OGRE_AUTO_MUTEX_NAME = new boost::recursive_mutex();
        #define OGRE_DELETE_AUTO_SHARED_MUTEX assert(OGRE_AUTO_MUTEX_NAME); delete OGRE_AUTO_MUTEX_NAME;
		#define OGRE_COPY_AUTO_SHARED_MUTEX(from) assert(!OGRE_AUTO_MUTEX_NAME); OGRE_AUTO_MUTEX_NAME = from;
        #define OGRE_SET_AUTO_SHARED_MUTEX_NULL OGRE_AUTO_MUTEX_NAME = 0;
        #define OGRE_MUTEX_CONDITIONAL(mutex) if (mutex)
		#define OGRE_THREAD_SYNCHRONISER(sync) boost::condition sync;
		#define OGRE_THREAD_WAIT(sync, lock) sync.wait(lock);
		#define OGRE_THREAD_NOTIFY_ONE(sync) sync.notify_one(); 
		#define OGRE_THREAD_NOTIFY_ALL(sync) sync.notify_all(); 
		// Thread-local pointer
		#define OGRE_THREAD_POINTER(T, var) boost::thread_specific_ptr<T> var
		#define OGRE_THREAD_POINTER_SET(var, expr) var.reset(expr)
		#define OGRE_THREAD_POINTER_DELETE(var) var.reset(0)
		#define OGRE_THREAD_POINTER_GET(var) var.get()
	#else
		#define OGRE_AUTO_MUTEX
		#define OGRE_LOCK_AUTO_MUTEX
		#define OGRE_MUTEX(name)
		#define OGRE_STATIC_MUTEX(name)
		#define OGRE_STATIC_MUTEX_INSTANCE(name)
		#define OGRE_LOCK_MUTEX(name)
		#define OGRE_LOCK_MUTEX_NAMED(mutexName, lockName)
		#define OGRE_AUTO_SHARED_MUTEX
		#define OGRE_LOCK_AUTO_SHARED_MUTEX
		#define OGRE_NEW_AUTO_SHARED_MUTEX
		#define OGRE_DELETE_AUTO_SHARED_MUTEX
		#define OGRE_COPY_AUTO_SHARED_MUTEX(from)
        #define OGRE_SET_AUTO_SHARED_MUTEX_NULL
        #define OGRE_MUTEX_CONDITIONAL(name) if(true)
		#define OGRE_THREAD_SYNCHRONISER(sync) 
		#define OGRE_THREAD_WAIT(sync, lock) 
		#define OGRE_THREAD_NOTIFY_ONE(sync) 
		#define OGRE_THREAD_NOTIFY_ALL(sync) 
		#define OGRE_THREAD_POINTER(T, var) T* var
		#define OGRE_THREAD_POINTER_SET(var, expr) var = expr
		#define OGRE_THREAD_POINTER_DELETE(var) delete var; var = 0
		#define OGRE_THREAD_POINTER_GET(var) var
	#endif


// Pre-declare classes
// Allows use of pointers in header files without including individual .h
// so decreases dependencies between files
    class Angle;
    class Animation;
    class AnimationState;
    class AnimationStateSet;
    class AnimationTrack;
    class Archive;
    class ArchiveFactory;
    class ArchiveManager;
    class AutoParamDataSource;
    class AxisAlignedBox;
    class AxisAlignedBoxSceneQuery;
    class Billboard;
    class BillboardChain;
    class BillboardSet;
    class Bone;
    class Camera;
    class Codec;
    class ColourValue;
    class ConfigDialog;
    template <typename T> class Controller;
    template <typename T> class ControllerFunction;
    class ControllerManager;
    template <typename T> class ControllerValue;
    class Degree;
    class DynLib;
    class DynLibManager;
    class EdgeData;
    class EdgeListBuilder;
    class Entity;
    class ErrorDialog;
    class ExternalTextureSourceManager;
    class Factory;
    class Font;
    class FontPtr;
    class FontManager;
    struct FrameEvent;
    class FrameListener;
    class Frustum;
    class GpuProgram;
    class GpuProgramPtr;
    class GpuProgramManager;
	class GpuProgramUsage;
    class HardwareIndexBuffer;
    class HardwareOcclusionQuery;
    class HardwareVertexBuffer;
	class HardwarePixelBuffer;
    class HardwarePixelBufferSharedPtr;
	class HighLevelGpuProgram;
    class HighLevelGpuProgramPtr;
	class HighLevelGpuProgramManager;
	class HighLevelGpuProgramFactory;
    class IndexData;
    class IntersectionSceneQuery;
    class IntersectionSceneQueryListener;
    class Image;
    class KeyFrame;
    class Light;
    class Log;
    class LogManager;
	class ManualResourceLoader;
	class ManualObject;
    class Material;
    class MaterialPtr;
    class MaterialManager;
    class MaterialScriptCompiler;
    class Math;
    class Matrix3;
    class Matrix4;
    class MemoryManager;
    class Mesh;
    class MeshPtr;
    class MeshSerializer;
    class MeshSerializerImpl;
    class MeshManager;
    class MovableObject;
    class MovablePlane;
    class Node;
	class NodeAnimationTrack;
	class NodeKeyFrame;
	class NumericAnimationTrack;
	class NumericKeyFrame;
    class Overlay;
    class OverlayContainer;
    class OverlayElement;
    class OverlayElementFactory;
    class OverlayManager;
    class Particle;
    class ParticleAffector;
    class ParticleAffectorFactory;
    class ParticleEmitter;
    class ParticleEmitterFactory;
    class ParticleSystem;
    class ParticleSystemManager;
    class ParticleSystemRenderer;
    class ParticleSystemRendererFactory;
    class ParticleVisualData;
    class Pass;
    class PatchMesh;
    class PixelBox;
    class Plane;
    class PlaneBoundedVolume;
	class Plugin;
    class Pose;
    class ProgressiveMesh;
    class Profile;
	class Profiler;
    class Quaternion;
	class Radian;
    class Ray;
    class RaySceneQuery;
    class RaySceneQueryListener;
    class Renderable;
    class RenderPriorityGroup;
    class RenderQueue;
    class RenderQueueGroup;
	class RenderQueueInvocation;
	class RenderQueueInvocationSequence;
    class RenderQueueListener;
    class RenderSystem;
    class RenderSystemCapabilities;
    class RenderTarget;
    class RenderTargetListener;
    class RenderTexture;
	class MultiRenderTarget;
    class RenderWindow;
    class RenderOperation;
    class Resource;
	class ResourceBackgroundQueue;
	class ResourceGroupManager;
    class ResourceManager;
    class RibbonTrail;
	class Root;
    class SceneManager;
    class SceneManagerEnumerator;
    class SceneNode;
    class SceneQuery;
    class SceneQueryListener;
	class ScriptLoader;
    class Serializer;
    class ShadowCaster;
    class ShadowRenderable;
	class ShadowTextureManager;
    class SimpleRenderable;
    class SimpleSpline;
    class Skeleton;
    class SkeletonPtr;
    class SkeletonInstance;
    class SkeletonManager;
    class Sphere;
    class SphereSceneQuery;
	class StaticGeometry;
    class StringConverter;
    class StringInterface;
    class SubEntity;
    class SubMesh;
	class TagPoint;
    class Technique;
	class TempBlendedBufferInfo;
	class ExternalTextureSource;
    class TextureUnitState;
    class Texture;
    class TexturePtr;
	class TextureFont;
    class TextureManager;
    class TransformKeyFrame;
	class Timer;
    class UserDefinedObject;
    class Vector2;
    class Vector3;
    class Vector4;
    class Viewport;
	class VertexAnimationTrack;
    class VertexBufferBinding;
    class VertexData;
    class VertexDeclaration;
	class VertexMorphKeyFrame;
    class WireBoundingBox;
    class Compositor;
    class CompositorManager;
    class CompositorChain;
    class CompositorInstance;
    class CompositionTechnique;
    class CompositionPass;
    class CompositionTargetPass;
}

#endif // __OgrePrerequisites_H__


