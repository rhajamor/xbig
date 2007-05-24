
#ifndef __T45_H__
#define __T45_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * protected enums are not in meta, see bug 1724320
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif



namespace Ogre {

	class EXPORT CompositorScriptCompiler
	{
	protected:
		enum TokenID {
			ID_UNKOWN = 0,
			ID_TARGET_WIDTH, ID_TARGET_HEIGHT,
			ID_PF_A8R8G8B8, ID_PF_R8G8B8A8, ID_PF_R8G8B8, 
			ID_PF_FLOAT16_R, ID_PF_FLOAT16_RGB, ID_PF_FLOAT16_RGBA,
			ID_PF_FLOAT32_R, ID_PF_FLOAT32_RGB, ID_PF_FLOAT32_RGBA,
			ID_PF_FLOAT16_GR, ID_PF_FLOAT32_GR,
			ID_PREVIOUS, ID_NONE,
			ID_RENDER_QUAD, ID_CLEAR, ID_STENCIL, ID_RENDER_SCENE,
			ID_CLR_COLOUR, ID_CLR_DEPTH,
            ID_ST_ALWAYS_FAIL, ID_ST_ALWAYS_PASS, ID_ST_LESS,
            ID_ST_LESS_EQUAL, ID_ST_EQUAL, ID_ST_NOT_EQUAL,
            ID_ST_GREATER_EQUAL, ID_ST_GREATER,
            ID_ST_KEEP, ID_ST_ZERO, ID_ST_REPLACE, ID_ST_INCREMENT,
            ID_ST_DECREMENT, ID_ST_INCREMENT_WRAP, ID_ST_DECREMENT_WRAP,
            ID_ST_INVERT,
			ID_ON, ID_OFF, ID_TRUE, ID_FALSE,
            ID_AUTOTOKENSTART
		};
		enum CompositorScriptSection
		{
			CSS_NONE,
			CSS_COMPOSITOR,
			CSS_TECHNIQUE,
			CSS_TARGET,
			CSS_PASS
		};
		struct CompositorScriptContext
		{
			CompositorScriptSection section;
		};

		CompositorScriptContext mScriptContext;
	};
}

#endif
