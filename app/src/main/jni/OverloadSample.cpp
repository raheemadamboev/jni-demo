#include "include/xyz_teamgravity_jnidemo_core_sample_OverloadSample.h"
#include <string>
#include <android/log.h>

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_add__D(JNIEnv *, jobject, jdouble a) {
    return a;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_add__DD(JNIEnv *, jobject, jdouble a, jdouble b) {
    return a + b;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_add__DLjava_lang_String_2(JNIEnv *env, jobject, jdouble a, jstring b) {
    const char *bStr = env->GetStringUTFChars(b, nullptr);
    jdouble bDouble = std::stod(bStr);
    env->ReleaseStringUTFChars(b, bStr);
    return a + bDouble;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_minus(JNIEnv *, jobject, jdouble a) {
    return a;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_multiply__D(JNIEnv *, jobject, jdouble a) {
    return a;
}

extern "C"
JNIEXPORT jdoubleArray JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_multiply___3D(JNIEnv *, jobject, jdoubleArray a) {
    return a;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_multiply__DLjava_lang_String_2(JNIEnv *, jobject, jdouble a, jstring) {
    return a;
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_multiply__Lxyz_teamgravity_jnidemo_core_sample_OverloadSample_2Lxyz_teamgravity_jnidemo_core_sample_OverloadSample_2(JNIEnv *, jobject, jobject, jobject) {
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "multiply!");
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_divide_1me__D(JNIEnv *, jobject, jdouble a) {
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "divide_me %f", a);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_divide_1me__I(JNIEnv *, jobject, jint a) {
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "divide_me %d", a);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_hello__D(JNIEnv *, jobject, jdouble a) {
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "hello %f", a);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_OverloadSample_hello__I(JNIEnv *, jclass, jint a) {
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "hello %d", a);
}