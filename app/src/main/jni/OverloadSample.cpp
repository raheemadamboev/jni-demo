#include "xyz_teamgravity_jnidemo_core_sample_OverloadSample.h"
#include <string>

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
    double bDouble = std::stod(bStr);
    env->ReleaseStringUTFChars(b, bStr);
    return a + bDouble;
}
