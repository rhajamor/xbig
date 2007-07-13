#include <jni_enum_pointer.h>

/*
 * Class:     org_xbig_base_EnumPointer
 * Method:    _get
 * Signature: (I)J
 */
JNIEXPORT jint JNICALL Java_org_xbig_base_EnumPointer__1get
  (JNIEnv *, jobject, jlong pInstance)
{
	int* _cpp_this = reinterpret_cast<int*>(pInstance);
	return *_cpp_this;
}

/*
 * Class:     org_xbig_base_EnumPointer
 * Method:    _set
 * Signature: ()I
 */
JNIEXPORT void JNICALL Java_org_xbig_base_EnumPointer__1set
  (JNIEnv *, jobject, jlong pInstance, jint _jni_value)
{
	int* _cpp_this = reinterpret_cast<int*>(pInstance);
	*_cpp_this = _jni_value;
}

/*
 * Class:     org_xbig_base_EnumPointer
 * Method:    __createEnumPointer
 * Signature: (J)
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_EnumPointer__1_1createEnumPointer
  (JNIEnv *, jclass, jint _jni_value)
{
	int* _cpp_this = new int(_jni_value);
	return reinterpret_cast<long>(_cpp_this);
}

/*
 * Class:     org_xbig_base_EnumPointer
 * Method:    __delete(long)
 * Signature: ()
 */
JNIEXPORT void JNICALL Java_org_xbig_base_EnumPointer__1_1delete
  (JNIEnv *, jobject, jlong pInstance)
{
	int* _cpp_this = reinterpret_cast<int*>(pInstance);
	delete _cpp_this;
}
