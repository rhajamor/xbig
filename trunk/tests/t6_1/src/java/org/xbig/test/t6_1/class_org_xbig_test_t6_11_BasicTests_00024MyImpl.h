/****************************************************************************************
 * 
 * 
 * This is needed for the junit test
 * 
 * 
 ***************************************************************************************/



#ifndef __Included_org_xbig_MyImpl__
#define __Included_org_xbig_MyImpl__


//#include "jni_base.h"
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

JNIEXPORT void JNICALL Java_org_xbig_test_t6_11_BasicTests_00024MyImpl_b (
  JNIEnv* _jni_env_, /* interface pointer */
  jobject _jni_this_, /* Java object */
  jlong _jni_pointer_, /* C++ pointer */
  jlong a
);

JNIEXPORT jlong JNICALL Java_org_xbig_test_t6_11_BasicTests_00024MyImpl_a (
  JNIEnv* _jni_env_, /* interface pointer */
  jobject _jni_this_, /* Java object */
  jlong _jni_pointer_ /* C++ pointer */
);

JNIEXPORT jlong JNICALL Java_org_xbig_test_t6_11_BasicTests_00024MyImpl_c (
  JNIEnv* _jni_env_, /* interface pointer */
  jobject _jni_this_, /* Java object */
  jlong _jni_pointer_, /* C++ pointer */
  jlong a
);

JNIEXPORT void JNICALL Java_org_xbig_test_t6_11_BasicTests_00024MyImpl__1_1delete (
  JNIEnv* _jni_env_, /* interface pointer */
  jobject _jni_this_, /* Java object */
  jlong _jni_pointer_ /* C++ pointer */
);

JNIEXPORT jlong JNICALL Java_org_xbig_test_t6_11_BasicTests_00024MyImpl_MyImpl (
  JNIEnv* _jni_env_, /* interface pointer */
  jclass _jni_class_  /* class pointer */
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
