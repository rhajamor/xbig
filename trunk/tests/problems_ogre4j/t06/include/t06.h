

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * inner struct with template field and typedef as type parameter
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


typedef float Real;

template <typename T>
class EXPORT Controller {};

class EXPORT TextureUnitState {
public:
	struct EXPORT TextureEffect {
		TextureEffect() {controller = (Controller<Real>*)1;}
		Controller<Real>* controller;
	};
};
