#include <jni_void_pointer.h>

/*
 * Class:     alwaysthere_VoidPointer
 * Method:    _dispose
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_VoidPointer__1dispose
  (JNIEnv *env, jobject that, jlong pInstance)
{
	void * ptr = reinterpret_cast<void*>(pInstance);
	delete ptr;
}
