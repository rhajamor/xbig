/******************************************************************
 *
 * Test file for the XSLT Bindings Generator (XBiG)
 *
 * It handles an enum with own values
 *
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

enum EXPORT Vocals {
	a = 101,
	e = 102,
	i = 103,
	o = 104,
	u = 105
};
