#include <jni_string_pointer.h>

/*
 * Class:     base_StringPointer
 * Method:    _create
 * Signature: (Ljava/lang/String)J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_StringPointer__1create
  (JNIEnv *env, jclass that, jstring value)
{
	std::string * ptr = new std::string;
	*ptr = org::xbig::jni::to_stdstring(env, value);
	return reinterpret_cast<jlong>(ptr);
}


/*
 * Class:     base_StringPointer
 * Method:    _dispose
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_StringPointer__1dispose
  (JNIEnv *, jobject that, jlong pInstance)
{
	std::string * ptr = reinterpret_cast<std::string*>(pInstance);
	delete ptr;
}

/*
 * Class:     base_StringPointer
 * Method:    _get
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_xbig_base_StringPointer__1get
  (JNIEnv * env, jobject that, jlong pInstance)
{
	std::string * ptr = reinterpret_cast<std::string*>(pInstance);
	return org::xbig::jni::to_jstring(env, *ptr);
}

/*
 * Class:     base_StringPointer
 * Method:    _next
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_xbig_base_StringPointer__1next
  (JNIEnv * env, jobject that, jlong pInstance)
{
	std::string * ptr = reinterpret_cast<std::string*>(pInstance);
	ptr++;
	return reinterpret_cast<jlong>(ptr);
}

/*
 * Class:     base_StringPointer
 * Method:    _set
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_xbig_base_StringPointer__1set
  (JNIEnv * env, jobject that, jlong pInstance, jstring value)
{
	std::string * ptr = reinterpret_cast<std::string*>(pInstance);
	*ptr = org::xbig::jni::to_stdstring(env, value);
}
