#include "xyz_teamgravity_jnidemo_core_sample_ArrayCriticalAccessSample.h"
#include <string>
#include <vector>

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_ArrayCriticalAccessSample_addRegion(JNIEnv *env, jclass, jdoubleArray array, jdouble x) {
    if (array == nullptr) return;

    jint length = env->GetArrayLength(array);
    std::vector<jdouble> c_array(length);

    env->GetDoubleArrayRegion(array, 0, length, c_array.data());
    if (env->ExceptionCheck()) return;

    for (jint i = 0; i < length; i++) {
        c_array[i] += x;
    }

    env->SetDoubleArrayRegion(array, 0, length, c_array.data());
    if (env->ExceptionCheck()) return;
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_ArrayCriticalAccessSample_addElements(JNIEnv *env, jclass, jdoubleArray array, jdouble x) {
    if (array == nullptr) return;

    jint length = env->GetArrayLength(array);
    jboolean isCopy;
    jdouble *c_array = env->GetDoubleArrayElements(array, &isCopy);
    if (c_array == nullptr) return;

    for (jint i = 0; i < length; i++) {
        c_array[i] += x;
    }

    env->ReleaseDoubleArrayElements(array, c_array, 0);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_ArrayCriticalAccessSample_addCritical(JNIEnv *env, jclass, jdoubleArray array, jdouble x) {
    if (array == nullptr) return;

    jint length = env->GetArrayLength(array);
    jboolean isCopy;
    auto c_array = static_cast<jdouble *>(env->GetPrimitiveArrayCritical(array, &isCopy));
    if (c_array == nullptr) return;

    for (jint i = 0; i < length; i++) {
        c_array[i] += x;
    }

    env->ReleasePrimitiveArrayCritical(array, c_array, 0);
}