#include <jni_base.h>

#include <iostream>

std::string org::xbig::jni::to_stdstring(JNIEnv* env, jstring jString) {
	const char* c_str = env->GetStringUTFChars(jString, JNI_FALSE); // false: create a copy
	return std::string(c_str);
}

char* org::xbig::jni::to_cstring(JNIEnv* env, jstring jString) {
	char* c_str = (char*)env->GetStringUTFChars(jString, JNI_FALSE); // false: create a copy
	return c_str;
}


jstring org::xbig::jni::to_jstring(JNIEnv* env, const std::string& str) {
	return env->NewStringUTF(str.c_str());
}


jstring org::xbig::jni::to_jstring(JNIEnv* env, const char* str) {
	return env->NewStringUTF(str);
}
