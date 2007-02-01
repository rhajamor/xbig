#include <jni_native_object_pointer.h>

/*
 * Class:     org_xbig_base_NativeObjectPointer
 * Method:    _getObject
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_NativeObjectPointer__1getObject
  (JNIEnv *env, jobject that, jlong pInstance) 
{
	void **ptr = reinterpret_cast<void**>(pInstance);
	return reinterpret_cast<jlong>(*ptr);
}  	