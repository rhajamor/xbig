#include <jni_byte_pointer.h>

/*
 * Class:     base_BytePointer
 * Method:    _create
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_BytePointer__1create
  (JNIEnv *env, jclass that, jbyte value)
{
	signed char * ptr = new signed char;
	*ptr = value;
	return reinterpret_cast<jlong>(ptr);
}

/*
 * Class:     base_BytePointer
 * Method:    _dispose
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_BytePointer__1dispose
  (JNIEnv *env, jobject that, jlong pInstance)
{
	signed char * ptr = reinterpret_cast<signed char*>(pInstance);
	delete ptr;
}

/*
 * Class:     base_BytePointer
 * Method:    _get
 * Signature: (J)C
 */
JNIEXPORT jchar JNICALL Java_org_xbig_base_BytePointer__1get
  (JNIEnv *env, jobject that, jlong pInstance)
{
	signed char * ptr = reinterpret_cast<signed char*>(pInstance);
	return * ptr;
}

/*
 * Class:     base_BytePointer
 * Method:    _next
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_BytePointer__1next
  (JNIEnv *env, jobject that, jlong pInstance)
{
	signed char * ptr = reinterpret_cast<signed char*>(pInstance);
	ptr++;
	return reinterpret_cast<jlong>(ptr);
}

/*
 * Class:     base_BytePointer
 * Method:    _set
 * Signature: (JC)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_BytePointer__1set
  (JNIEnv *env, jobject that, jlong pInstance, jbyte value)
{
	signed char * ptr = reinterpret_cast<signed char*>(pInstance);
	*ptr = value;
}
