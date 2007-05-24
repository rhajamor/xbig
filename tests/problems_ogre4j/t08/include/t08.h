

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * invalid C function names for typedefs
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <map>
#include <vector>
#include <string>

template <class T>
class EXPORT ConstMapIterator{};

template <typename T>
class EXPORT Singleton {};

class EXPORT NumericAnimationTrack {};
class EXPORT RenderSystem {};

typedef std::string _StringBase;
typedef _StringBase String;
typedef std::vector<RenderSystem*> RenderSystemList;

class EXPORT Animation {
public:
	typedef std::map<unsigned short, NumericAnimationTrack*> NumericTrackList;
	typedef ConstMapIterator<NumericTrackList> NumericTrackIterator;

};

class EXPORT Root : public Singleton<Root> {

	friend class RenderSystem;

private:
	RenderSystemList mRenderers;

public:
	Root(const String& pluginFileName = "plugins.cfg", const String& configFileName = "ogre.cfg", const String& logFileName = "Ogre.log");
	~Root();
	void saveConfig(void);
};
