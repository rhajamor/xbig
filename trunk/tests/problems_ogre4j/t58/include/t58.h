
#ifndef __T58_H__
#define __T58_H__

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * wrong c-tor, see bug 1728992
 ******************************************************************/

#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif


#include <string>


namespace Ogre {

	typedef std::string String;
	typedef float Real;


	enum WaveformType {
	    WFT_SINE,
	    WFT_TRIANGLE,
	    WFT_SQUARE,
	    WFT_SAWTOOTH,
	    WFT_INVERSE_SAWTOOTH,
	    WFT_PWM
	};


	template <class T>
	class EXPORT ControllerFunction {
	public:
		ControllerFunction (bool deltaInput) {}
		virtual ~ControllerFunction () {}
		virtual T calculate (T sourceValue)=0;
	};

	class EXPORT WaveformControllerFunction : public ControllerFunction<Real> {
	public:
		WaveformControllerFunction (WaveformType wType, Real base=0, Real frequency=1, Real phase=0, Real amplitude=1, bool deltaInput=true, Real dutyCycle=0.5) : ControllerFunction<Real>(deltaInput){}
		Real calculate (Real source) {return source;}
	};
}

#endif
