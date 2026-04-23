#include "xyz_teamgravity_jnidemo_core_util_Unsafe.h"

extern "C"
JNIEXPORT jlong JNICALL
Java_xyz_teamgravity_jnidemo_core_util_Unsafe_allocateMemory(JNIEnv *env, jclass, jlong bytes) {
    char *pointer = new char[bytes];
    return (jlong) pointer;
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_Unsafe_freeMemory(JNIEnv *env, jclass, jlong address) {
    char *pointer = (char *) address;
    delete[] pointer;
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_Unsafe_putInt(JNIEnv *, jclass, jlong address, jint value) {
    auto *pointer = (jint *) address;
    *pointer = value;
}

extern "C"
JNIEXPORT jint JNICALL
Java_xyz_teamgravity_jnidemo_core_util_Unsafe_getInt(JNIEnv *, jclass, jlong address) {
    auto *pointer = (jint *) address;
    return *pointer;
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_Unsafe_putDouble(JNIEnv *, jclass, jlong address, jdouble value) {
    auto *pointer = (jdouble *) address;
    *pointer = value;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_util_Unsafe_getDouble(JNIEnv *, jclass, jlong address) {
    auto *pointer = (jdouble *) address;
    return *pointer;
}