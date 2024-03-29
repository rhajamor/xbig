/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2006 Torus Knot Software Ltd
Also see acknowledgements in Readme.html

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.

You may alternatively use this source under the terms of a specific version of
the OGRE Unrestricted License provided you have obtained such a license from
Torus Knot Software Ltd.
-----------------------------------------------------------------------------
*/
#ifndef _Resource_H__
#define _Resource_H__

#include "OgrePrerequisites.h"
#include "OgreString.h"
#include "OgreSharedPtr.h"
#include "OgreStringInterface.h"

namespace Ogre {

    typedef unsigned long ResourceHandle;


	// Forward declaration
	class ManualResourceLoader;

	/** Abstract class reprensenting a loadable resource (e.g. textures, sounds etc)
        @remarks
            Resources are data objects that must be loaded and managed throughout
			an application. A resource might be a mesh, a texture, or any other
			piece of data - the key thing is that they must be identified by 
			a name which is unique, must be loaded only once,
			must be managed efficiently in terms of retrieval, and they may
			also be unloadable to free memory up when they have not been used for
			a while and the memory budget is under stress.
		@par
			All Resource instances must be a member of a resource group; see
			ResourceGroupManager for full details.
        @par
            Subclasses must implement:
			<ol>
			<li>A constructor, overriding the same parameters as the constructor
			    defined by this class. Subclasses are not allowed to define
				constructors with other parameters; other settings must be
				settable through accessor methods before loading.</li>
            <li>The loadImpl() and unloadImpl() methods - mSize must be set 
				after loadImpl()</li>
			<li>StringInterface ParamCommand and ParamDictionary setups
			    in order to allow setting of core parameters (prior to load)
				through a generic interface.</li>
			</ol>
    */
	class _OgreExport Resource : public StringInterface
    {
	public:
		OGRE_AUTO_MUTEX // public to allow external locking
		class Listener
		{
		public:
		   	Listener() {}
			virtual ~Listener() {}

			/** Callback to indicate that background loading has completed.
			@remarks
				This callback is only relevant when a Resource has been
				marked as background loaded (@see Resource::setBackgroundLoaded)
				, and occurs when that loading has completed. The call itself
				does not itself occur in the thread which is doing the loading;
				when loading is complete a response indicator is placed with the
				ResourceGroupManager, which will then be sent back to the 
				listener as part of the application's primary frame loop thread.
			*/
			virtual void backgroundLoadingComplete(Resource*) {}
			
		};
		
		/// Enum identifying the loading state of the resource
		enum LoadingState
		{
			/// Not loaded
			LOADSTATE_UNLOADED,
			/// Loading is in progress
			LOADSTATE_LOADING,
			/// Fully loaded
			LOADSTATE_LOADED,
			/// Currently unloading
			LOADSTATE_UNLOADING
		};
    protected:
		/// Creator
		ResourceManager* mCreator;
		/// Unique name of the resource
        String mName;
		/// The name of the resource group
		String mGroup;
		/// Numeric handle for more efficient look up than name
        ResourceHandle mHandle;
		/// Is the resource currently loaded?
        volatile LoadingState mLoadingState;
		/// Is this resource going to be background loaded? Only applicable for multithreaded
		volatile bool mIsBackgroundLoaded;
		/// Mutex to cover the status of loading
		OGRE_MUTEX(mLoadingStatusMutex)
		/// The size of the resource in bytes
        size_t mSize;
		/// Is this file manually loaded?
		bool mIsManual;
		/// Origin of this resource (e.g. script name) - optional
		String mOrigin;
		/// Optional manual loader; if provided, data is loaded from here instead of a file
		ManualResourceLoader* mLoader;

		typedef std::list<Listener*> ListenerList;
		ListenerList mListenerList;

		/** Protected unnamed constructor to prevent default construction. 
		*/
		Resource() 
			: mCreator(0), mHandle(0), mLoadingState(LOADSTATE_UNLOADED), 
			mIsBackgroundLoaded(false),	mSize(0), mIsManual(0), mLoader(0)
		{ 
		}

		/** Internal hook to perform actions before the load process, but
			after the resource has been marked as 'loading'.
		@note Mutex will have already been acquired by the loading thread.
			Also, this call will occur even when using a ManualResourceLoader 
			(when loadImpl is not actually called)
		*/
		virtual void preLoadImpl(void) {}
		/** Internal hook to perform actions after the load process, but
			before the resource has been marked as fully loaded.
		@note Mutex will have already been acquired by the loading thread.
			Also, this call will occur even when using a ManualResourceLoader 
			(when loadImpl is not actually called)
		*/
		virtual void postLoadImpl(void) {}

		/** Internal hook to perform actions before the unload process.
		@note Mutex will have already been acquired by the unloading thread.
		*/
		virtual void preUnloadImpl(void) {}
		/** Internal hook to perform actions after the unload process, but
		before the resource has been marked as fully unloaded.
		@note Mutex will have already been acquired by the unloading thread.
		*/
		virtual void postUnloadImpl(void) {}

		/** Internal implementation of the meat of the 'load' action, only called if this 
			resource is not being loaded from a ManualResourceLoader. 
		*/
		virtual void loadImpl(void) = 0;
		/** Internal implementation of the 'unload' action; called regardless of
			whether this resource is being loaded from a ManualResourceLoader. 
		*/
		virtual void unloadImpl(void) = 0;
		/** Calculate the size of a resource; this will only be called after 'load' */
		virtual size_t calculateSize(void) const = 0;

		/// Queue the firing of background loading complete event
		virtual void queueFireBackgroundLoadingComplete(void);

    public:
		/** Standard constructor.
		@param creator Pointer to the ResourceManager that is creating this resource
		@param name The unique name of the resource
		@param group The name of the resource group to which this resource belongs
		@param isManual Is this resource manually loaded? If so, you should really
			populate the loader parameter in order that the load process
			can call the loader back when loading is required. 
		@param loader Pointer to a ManualResourceLoader implementation which will be called
			when the Resource wishes to load (should be supplied if you set
			isManual to true). You can in fact leave this parameter null 
			if you wish, but the Resource will never be able to reload if 
			anything ever causes it to unload. Therefore provision of a proper
			ManualResourceLoader instance is strongly recommended.
		*/
		Resource(ResourceManager* creator, const String& name, ResourceHandle handle,
			const String& group, bool isManual = false, ManualResourceLoader* loader = 0);

        /** Virtual destructor. Shouldn't need to be overloaded, as the resource
            deallocation code should reside in unload()
            @see
                Resource::unload()
        */
        virtual ~Resource();

        /** Loads the resource, if it is not already.
		@remarks
			If the resource is loaded from a file, loading is automatic. If not,
			if for example this resource gained it's data from procedural calls
			rather than loading from a file, then this resource will not reload 
			on it's own.
		@param backgroundThread Indicates whether the caller of this method is
			the background resource loading thread. 
			
        */
        virtual void load(bool backgroundThread = false);

		/** Reloads the resource, if it is already loaded.
		@remarks
			Calls unload() and then load() again, if the resource is already
			loaded. If it is not loaded already, then nothing happens.
		*/
		virtual void reload(void);

        /** Returns true if the Resource is reloadable, false otherwise.
        */
        bool isReloadable(void) const
        {
            return !mIsManual || mLoader;
        }

        /** Is this resource manually loaded?
		*/
		bool isManuallyLoaded(void) const
		{
			return mIsManual;
		}

		/** Unloads the resource; this is not permanent, the resource can be
			reloaded later if required.
        */
		virtual void unload(void);

        /** Retrieves info about the size of the resource.
        */
        size_t getSize(void) const
        { 
            return mSize; 
        }

        /** 'Touches' the resource to indicate it has been used.
        */
        virtual void touch(void);

        /** Gets resource name.
        */
        const String& getName(void) const 
        { 
            return mName; 
        }

        ResourceHandle getHandle(void) const
        {
            return mHandle;
        }

        /** Returns true if the Resource has been loaded, false otherwise.
        */
        bool isLoaded(void) const 
        { 
			// No lock required to read this state since no modify
            return (mLoadingState == LOADSTATE_LOADED); 
        }

		/** Returns whether the resource is currently in the process of
			background loading.
		*/
		LoadingState isLoading() const
		{
			return mLoadingState;
		}

		/** Returns the current loading state.
		*/
		LoadingState getLoadingState() const
		{
			return mLoadingState;
		}



		/** Returns whether this Resource has been earmarked for background loading.
		@remarks
			This option only makes sense when you have built Ogre with 
			thread support (OGRE_THREAD_SUPPORT). If a resource has been marked
			for background loading, then it won't load on demand like normal
			when load() is called. Instead, it will ignore request to load()
			except if the caller indicates it is the background loader. Any
			other users of this resource should check isLoaded(), and if that
			returns false, don't use the resource and come back later.
		*/
		bool isBackgroundLoaded(void) const { return mIsBackgroundLoaded; }

		/** Tells the resource whether it is background loaded or not.
		@remarks
			@see Resource::isBackgroundLoaded . Note that calling this only
			defers the normal on-demand loading behaviour of a resource, it
			does not actually set up a thread to make sure the resource gets
			loaded in the background. You should use ResourceBackgroundLoadingQueue
			to manage the actual loading (which will call this method itself).
		*/
		void setBackgroundLoaded(bool bl) { mIsBackgroundLoaded = bl; }

		/** Escalates the loading of a background loaded resource. 
		@remarks
			If a resource is set to load in the background, but something needs
			it before it's been loaded, there could be a problem. If the user
			of this resource really can't wait, they can escalate the loading
			which basically pulls the loading into the current thread immediately.
			If the resource is already being loaded but just hasn't quite finished
			then this method will simply wait until the background load is complete.
		*/
		void escalateLoading();

		/** Register a listener on this resource.
			@see Resource::Listener
		*/
		void addListener(Listener* lis);

		/** Remove a listener on this resource.
			@see Resource::Listener
		*/
		void removeListener(Listener* lis);

		/// Gets the group which this resource is a member of
		const String& getGroup(void) { return mGroup; }

		/** Change the resource group ownership of a Resource.
		@remarks
			This method is generally reserved for internal use, although
			if you really know what you're doing you can use it to move
			this resource from one group to another.
		@param newGroup Name of the new group
		*/
		void changeGroupOwnership(const String& newGroup);

		/// Gets the manager which created this resource
		ResourceManager* getCreator(void) { return mCreator; }
		/** Get the origin of this resource, e.g. a script file name.
		@remarks
			This property will only contain something if the creator of
			this resource chose to populate it. Script loaders are advised
			to populate it.
		*/
		const String& getOrigin(void) const { return mOrigin; }
		/// Notify this resource of it's origin
		void _notifyOrigin(const String& origin) { mOrigin = origin; }

    };

	/** Shared pointer to a Resource.
	@remarks
		This shared pointer allows many references to a resource to be held, and
		when the final reference is removed, the resource will be destroyed. 
		Note that the ResourceManager which created this Resource will be holding
		at least one reference, so this resource will not get destroyed until 
		someone removes the resource from the manager - this at least gives you
		strong control over when resources are freed. But the nature of the 
		shared pointer means that if anyone refers to the removed resource in the
		meantime, the resource will remain valid.
	@par
		You may well see references to ResourcePtr (i.e. ResourcePtr&) being passed 
		around internally within Ogre. These are 'weak references' ie they do 
		not increment the reference count on the Resource. This is done for 
		efficiency in temporary operations that shouldn't need to incur the 
		overhead of maintaining the reference count; however we don't recommend 
		you do it yourself since these references are not guaranteed to remain valid.
	*/
	typedef SharedPtr<Resource> ResourcePtr;

	/** Interface describing a manual resource loader.
	@remarks
		Resources are usually loaded from files; however in some cases you
		want to be able to set the data up manually instead. This provides
		some problems, such as how to reload a Resource if it becomes
		unloaded for some reason, either because of memory constraints, or
		because a device fails and some or all of the data is lost.
	@par
		This interface should be implemented by all classes which wish to
		provide manual data to a resource. They provide a pointer to themselves
		when defining the resource (via the appropriate ResourceManager), 
		and will be called when the Resource tries to load. 
		They should implement the loadResource method such that the Resource 
		is in the end set up exactly as if it had loaded from a file, 
		although the implementations will likely differ	between subclasses 
		of Resource, which is why no generic algorithm can be stated here. 
	@note
		The loader must remain valid for the entire life of the resource,
		so that if need be it can be called upon to re-load the resource
		at any time.
	*/
	class _OgreExport ManualResourceLoader
	{
	public:
		ManualResourceLoader() {}
		virtual ~ManualResourceLoader() {}

		/** Called when a resource wishes to load.
		@param resource The resource which wishes to load
		*/
		virtual void loadResource(Resource* resource) = 0;
	};
}

#endif
