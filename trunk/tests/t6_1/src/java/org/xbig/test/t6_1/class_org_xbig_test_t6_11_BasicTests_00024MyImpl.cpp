/****************************************************************************************
 * 
 * 
 * This is needed for the junit test
 * 
 * 
 ***************************************************************************************/



// use base library for cpp2j
//#include "jni_base_all.h"

// import declaration of all functions
#include "class_org_xbig_test_t6_11_BasicTests_00024MyImpl.h"

// import header files of original library
#include "t6_1.h"


JNIEXPORT void JNICALL Java_org_xbig_test_t6_11_BasicTests_00024MyImpl_b (
  JNIEnv* _jni_env_, /* interface pointer */
  jobject _jni_this_, /* Java object */
  jlong _jni_pointer_, /* C++ pointer */
  jlong a
) {
  C _cpp_a = *reinterpret_cast< C* >(a); 
  A< C >* _cpp_this = reinterpret_cast<A< C >*>(_jni_pointer_); 
  _cpp_this->b(_cpp_a); 
}

JNIEXPORT jlong JNICALL Java_org_xbig_test_t6_11_BasicTests_00024MyImpl_a (
  JNIEnv* _jni_env_, /* interface pointer */
  jobject _jni_this_, /* Java object */
  jlong _jni_pointer_ /* C++ pointer */
) {
  A< C >* _cpp_this = reinterpret_cast<A< C >*>(_jni_pointer_); 
  C _cpp_result = _cpp_this->a(); 
  return reinterpret_cast<jlong>(&_cpp_result);
}

JNIEXPORT jlong JNICALL Java_org_xbig_test_t6_11_BasicTests_00024MyImpl_c (
  JNIEnv* _jni_env_, /* interface pointer */
  jobject _jni_this_, /* Java object */
  jlong _jni_pointer_, /* C++ pointer */
  jlong a
) {
  C _cpp_a = *reinterpret_cast< C* >(a); 
  A< C >* _cpp_this = reinterpret_cast<A< C >*>(_jni_pointer_); 
  C _cpp_result = _cpp_this->c(_cpp_a); 
  return reinterpret_cast<jlong>(&_cpp_result);
}

JNIEXPORT void JNICALL Java_org_xbig_test_t6_11_BasicTests_00024MyImpl__1_1delete (
  JNIEnv* _jni_env_, /* interface pointer */
  jobject _jni_this_, /* Java object */
  jlong _jni_pointer_ /* C++ pointer */
) {
  // cast pointer to C++ object 
  A< C >* _cpp_this = reinterpret_cast<A< C >*>(_jni_pointer_); 
  // delete object if it exists 
  if(_cpp_this != NULL) delete _cpp_this;
}

JNIEXPORT jlong JNICALL Java_org_xbig_test_t6_11_BasicTests_00024MyImpl_MyImpl (
  JNIEnv* _jni_env_, /* interface pointer */
  jclass _jni_class_  /* class pointer */
)
{
  A< C >* _cpp_this = new A< C >(); 
  jlong _jni_pointer_ = reinterpret_cast<jlong>(_cpp_this); 
  return _jni_pointer_;
}
