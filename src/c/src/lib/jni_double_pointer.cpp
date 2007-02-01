#include <jni_double_pointer.h>

/*
 * Class:     base_DoublePointer
 * Method:    _create
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_DoublePointer__1create
  (JNIEnv *env, jclass that, jdouble value)
{
	double * ptr = new double;
	*ptr = value;
	return reinterpret_cast<long>(ptr);
}

/*
 * Class:     base_DoublePointer
 * Method:    _dispose
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_DoublePointer__1dispose
  (JNIEnv *env, jobject that, jlong pInstance)
{
	double * ptr = reinterpret_cast<double*>(pInstance);
	delete ptr;
}

/*
 * Class:     base_DoublePointer
 * Method:    _get
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_org_xbig_base_DoublePointer__1get
  (JNIEnv *env, jobject that, jlong pInstance)
{
	double * ptr = reinterpret_cast<double*>(pInstance);
	return * ptr;
}

/*
 * Class:     base_DoublePointer
 * Method:    _next
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_DoublePointer__1next
  (JNIEnv *env, jobject that, jlong pInstance)
{
	double * ptr = reinterpret_cast<double*>(pInstance);
	ptr++;
	return reinterpret_cast<long>(ptr);
}

/*
 * Class:     base_DoublePointer
 * Method:    _set
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_DoublePointer__1set
  (JNIEnv *env, jobject that, jlong pInstance, jdouble value)
{
	double * ptr = reinterpret_cast<double*>(pInstance);
	*ptr = value;
}
