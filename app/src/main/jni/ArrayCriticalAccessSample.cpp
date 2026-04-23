#include "xyz_teamgravity_jnidemo_core_sample_ArrayCriticalAccessSample.h"
#include <string>

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_ArrayCriticalAccessSample_addRegion(JNIEnv *env, jclass, jdoubleArray array, jdouble x) {
    jint length = env->GetArrayLength(array);
    jdouble c_array[length];
    env->GetDoubleArrayRegion(array, 0, length, c_array);
    for (int i = 0; i < length; i++) {
        c_array[i] += x;
    }
    env->SetDoubleArrayRegion(array, 0, length, c_array);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_ArrayCriticalAccessSample_addElements(JNIEnv *env, jclass, jdoubleArray array, jdouble x) {
    jint length = env->GetArrayLength(array);
    jboolean isCopy{false};
    jdouble *c_array = env->GetDoubleArrayElements(array, &isCopy);
    for (int i = 0; i < length; i++) {
        c_array[i] += x;
    }
    env->ReleaseDoubleArrayElements(array, c_array, 0);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_ArrayCriticalAccessSample_addCritical(JNIEnv *env, jclass, jdoubleArray array, jdouble x) {
    jint length = env->GetArrayLength(array);
    jboolean isCopy{false};
    auto c_array = (jdouble *) env->GetPrimitiveArrayCritical(array, &isCopy);
    for (int i = 0; i < length; i++) {
        c_array[i] += x;
    }
    env->ReleasePrimitiveArrayCritical(array, c_array, 0);
}