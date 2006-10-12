

/****************************************************************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of Ogre4J
 *
 * Problem:
 * inner struct with template field and typedef as type parameter
 ****************************************************************************************************************/


typedef float Real;

template <typename T>
class Controller {};

class TextureUnitState {
public:
	struct TextureEffect {
		Controller<Real>* controller;
	};
};
