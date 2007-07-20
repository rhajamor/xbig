#include <jni_bool_pointer.h>

/*
 * Class:     base_boolPointer
 * Method:    _create
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_BooleanPointer__1create
  (JNIEnv *env, jclass that, jboolean value)
{
	bool * ptr = new bool;
	*ptr = value ? 1 : 0;
	return reinterpret_cast<jlong>(ptr);
}

/*
 * Class:     base_boolPointer
 * Method:    _dispose
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_BooleanPointer__1dispose
  (JNIEnv *env, jobject that, jlong pInstance)
{
	bool * ptr = reinterpret_cast<bool*>(pInstance);
	delete ptr;
}

/*
 * Class:     base_boolPointer
 * Method:    _get
 * Signature: (J)I
 */
JNIEXPORT jboolean JNICALL Java_org_xbig_base_BooleanPointer__1get
  (JNIEnv *env, jobject that, jlong pInstance)
{
	bool * ptr = reinterpret_cast<bool*>(pInstance);
	return * ptr;
}

/*
 * Class:     base_boolPointer
 * Method:    _next
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_BooleanPointer__1next
  (JNIEnv *env, jobject that, jlong pInstance)
{
	bool * ptr = reinterpret_cast<bool*>(pInstance);
	ptr++;
	return reinterpret_cast<jlong>(ptr);
}

/*
 * Class:     base_boolPointer
 * Method:    _set
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_BooleanPointer__1set
  (JNIEnv *env, jobject that, jboolean pInstance, jboolean value)
{
	bool * ptr = reinterpret_cast<bool*>(pInstance);
	*ptr = value ? 1 : 0;
}

/*
 * Class:     base_boolPointer
 * Method:    _set
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_BooleanPointer__1set
  (JNIEnv *env, jobject that, jlong pInstance, jboolean value)
{
	bool * ptr = reinterpret_cast<bool*>(pInstance);
	*ptr = value ? 1 : 0;
}
