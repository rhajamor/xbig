

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


#include <map>
#include <vector>
#include <string>

template <class T>
class ConstMapIterator{};

template <typename T>
class Singleton {};

class NumericAnimationTrack {};
class RenderSystem {};

typedef std::string _StringBase;
typedef _StringBase String;
typedef std::vector<RenderSystem*> RenderSystemList;

class Animation {
public:
	typedef std::map<unsigned short, NumericAnimationTrack*> NumericTrackList;
	typedef ConstMapIterator<NumericTrackList> NumericTrackIterator;

};

class Root : public Singleton<Root> {

	friend class RenderSystem;

private:
	RenderSystemList mRenderers;

public:
	Root(const String& pluginFileName = "plugins.cfg", const String& configFileName = "ogre.cfg", const String& logFileName = "Ogre.log");
	~Root();
	void saveConfig(void);
};
