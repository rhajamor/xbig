

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * struct contains inner struct of a class as field
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


class EXPORT SceneQuery {
public:
	struct EXPORT WorldFragment {};
};

struct EXPORT RaySceneQueryResultEntry {
	SceneQuery::WorldFragment* worldFragment;
};
