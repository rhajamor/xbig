#include <jni_integer_pointer.h>

/*
 * Class:     base_intPointer
 * Method:    _create
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_IntegerPointer__1create
  (JNIEnv *env, jclass that, jint value)
{
	int * ptr = new int;
	*ptr = value;
	return reinterpret_cast<long>(ptr);
}

/*
 * Class:     base_intPointer
 * Method:    _dispose
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_IntegerPointer__1dispose
  (JNIEnv *env, jobject that, jlong pInstance)
{
	int * ptr = reinterpret_cast<int*>(pInstance);
	delete ptr;
}

/*
 * Class:     base_intPointer
 * Method:    _get
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_xbig_base_IntegerPointer__1get
  (JNIEnv *env, jobject that, jlong pInstance)
{
	int * ptr = reinterpret_cast<int*>(pInstance);
	return * ptr;
}

/*
 * Class:     base_intPointer
 * Method:    _next
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_IntegerPointer__1next
  (JNIEnv *env, jobject that, jlong pInstance)
{
	int * ptr = reinterpret_cast<int*>(pInstance);
	ptr++;
	return reinterpret_cast<long>(ptr);
}

/*
 * Class:     base_intPointer
 * Method:    _set
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_IntegerPointer__1set
  (JNIEnv *env, jobject that, jint pInstance, jint value)
{
	int * ptr = reinterpret_cast<int*>(pInstance);
	*ptr = value;
}

/*
 * Class:     base_intPointer
 * Method:    _set
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_IntegerPointer__1set
  (JNIEnv *env, jobject that, jlong pInstance, jint value)
{
	int * ptr = reinterpret_cast<int*>(pInstance);
	*ptr = value;
}
