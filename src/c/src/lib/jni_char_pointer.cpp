#include <jni_char_pointer.h>

/*
 * Class:     base_CharPointer
 * Method:    _create
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_CharPointer__1create
  (JNIEnv *env, jclass that, jchar value)
{
	char * ptr = new char;
	*ptr = value;
	return reinterpret_cast<jlong>(ptr);
}

/*
 * Class:     base_CharPointer
 * Method:    _dispose
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_CharPointer__1dispose
  (JNIEnv *env, jobject that, jlong pInstance)
{
	char * ptr = reinterpret_cast<char*>(pInstance);
	delete ptr;
}

/*
 * Class:     base_CharPointer
 * Method:    _get
 * Signature: (J)C
 */
JNIEXPORT jchar JNICALL Java_org_xbig_base_CharPointer__1get
  (JNIEnv *env, jobject that, jlong pInstance)
{
	char * ptr = reinterpret_cast<char*>(pInstance);
	return * ptr;
}

/*
 * Class:     base_CharPointer
 * Method:    _next
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_CharPointer__1next
  (JNIEnv *env, jobject that, jlong pInstance)
{
	char * ptr = reinterpret_cast<char*>(pInstance);
	ptr++;
	return reinterpret_cast<jlong>(ptr);
}

/*
 * Class:     base_CharPointer
 * Method:    _set
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_CharPointer__1set
  (JNIEnv *env, jobject that, jlong pInstance, jchar value)
{
	char * ptr = reinterpret_cast<char*>(pInstance);
	*ptr = value;
}
