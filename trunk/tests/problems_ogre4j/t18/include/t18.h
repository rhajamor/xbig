

/******************************************************************
 * This file has been created to test
 * the XSLT Bindings Generator (XBiG)
 *
 * It is based on a problem occured
 * during the generation of ogre4j
 *
 * Problem:
 * overloaded method, parameter by ptr and value
 ******************************************************************/


class Vector2 {
public:
	Vector2 (const float scaler);
	Vector2 (float *const r);
};
