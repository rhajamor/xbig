
#ifndef __T48_H__
#define __T48_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * Invalid type parameters, see bug 1724324
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>
#include <map>


namespace Ogre {

	typedef float Real;
	typedef std::string String;

	class EXPORT TextureUnitState {
	public:
		enum TextureEffectType {
			ET_ENVIRONMENT_MAP,
			ET_PROJECTIVE_TEXTURE,
			ET_UVSCROLL,
			ET_USCROLL,
			ET_VSCROLL,
			ET_ROTATE,
			ET_TRANSFORM
		};
		struct EXPORT TextureEffect {
		};
	};

	struct EXPORT MaterialScriptContext {
	};

	typedef bool (*ATTRIBUTE_PARSER)(String& params, MaterialScriptContext& context);

	class EXPORT MaterialSerializer {
	public:
		typedef std::map<String, ATTRIBUTE_PARSER> AttribParserList;
		typedef std::multimap<TextureUnitState::TextureEffectType, TextureUnitState::TextureEffect> EffectMap;
	};
}

#endif
