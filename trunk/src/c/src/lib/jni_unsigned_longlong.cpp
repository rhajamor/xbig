#include <jni_unsigned_longlong.h>

jlong org::xbig::jni::getShiftedULongLongValue(JNIEnv* env, jobject obj) {
	jclass cls = env->GetObjectClass(obj);
	
	jmethodID mid = env->GetMethodID(cls, "getShiftedValue", "()J");
	
	if (mid == NULL) {
		return 0; /* method not found */
	}
	
	return env->CallLongMethod(obj, mid);
}
