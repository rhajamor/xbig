#include <jni_long_pointer.h>

/*
 * Class:     base_LongPointer
 * Method:    _create
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_LongPointer__1create
  (JNIEnv *env, jclass that, jlong value)
{
	long * ptr = new long;
	*ptr = value;
	return reinterpret_cast<long>(ptr);
}

/*
 * Class:     base_LongPointer
 * Method:    _dispose
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_LongPointer__1dispose
  (JNIEnv *env, jobject that, jlong pInstance)
{
	long * ptr = reinterpret_cast<long*>(pInstance);
	delete ptr;
}

/*
 * Class:     base_LongPointer
 * Method:    _get
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_LongPointer__1get
  (JNIEnv *env, jobject that, jlong pInstance)
{
	long * ptr = reinterpret_cast<long*>(pInstance);
	return * ptr;
}

/*
 * Class:     base_LongPointer
 * Method:    _next
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_LongPointer__1next
  (JNIEnv *env, jobject that, jlong pInstance)
{
	long * ptr = reinterpret_cast<long*>(pInstance);
	ptr++;
	return reinterpret_cast<long>(ptr);
}

/*
 * Class:     base_LongPointer
 * Method:    _set
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_LongPointer__1set
  (JNIEnv *env, jobject that, jlong pInstance, jlong value)
{
	long * ptr = reinterpret_cast<long*>(pInstance);
	*ptr = value;
}
