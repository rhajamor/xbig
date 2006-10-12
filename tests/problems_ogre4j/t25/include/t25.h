

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * struct contains inner struct of a class as field
 ****************************************************************************************************************/


class SceneQuery {
public:
	struct WorldFragment {};
};

struct RaySceneQueryResultEntry {
	SceneQuery::WorldFragment* worldFragment;
};
