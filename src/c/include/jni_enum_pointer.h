#include <jni.h>
/* Header for class org_xbig_base_EnumPointer */

#ifndef _Included_org_xbig_base_EnumPointer
#define _Included_org_xbig_base_EnumPointer
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     org_xbig_base_EnumPointer
 * Method:    _get
 * Signature: (I)J
 */
JNIEXPORT jint JNICALL Java_org_xbig_base_EnumPointer__1get
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_xbig_base_EnumPointer
 * Method:    _set
 * Signature: ()I
 */
JNIEXPORT void JNICALL Java_org_xbig_base_EnumPointer__1set
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     org_xbig_base_EnumPointer
 * Method:    __createEnumPointer
 * Signature: (J)
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_EnumPointer__1_1createEnumPointer
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_xbig_base_EnumPointer
 * Method:    __delete(long)
 * Signature: ()
 */
JNIEXPORT void JNICALL Java_org_xbig_base_EnumPointer__1_1delete
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
