#include "xyz_teamgravity_jnidemo_core_util_manager_MathManager.h"
#include <android/log.h>

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_sayHi(JNIEnv *env, jclass clazz) {
    __android_log_print(ANDROID_LOG_DEBUG, "MathManager", "Hello from C++!!");
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_multiply(JNIEnv *env, jobject thiz, jdouble a, jdouble b) {
    return a * b;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_isOdd(JNIEnv *, jobject, jint a) {
    jboolean isOdd = a % 2 ? JNI_TRUE : JNI_FALSE;
    return isOdd;
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_damage(JNIEnv *, jobject, jlong a) {
    jfloat result = a * 1.3f;
    return result;
}