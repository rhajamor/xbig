

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * void ptr
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


class EXPORT SceneQuery {
public:
	struct EXPORT WorldFragment {
		WorldFragment() {geometry = (void*)1;}
		void* geometry;
	};
};
