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
    jboolean is_odd = a % 2 ? JNI_TRUE : JNI_FALSE;
    return is_odd;
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_damage(JNIEnv *, jobject, jlong a) {
    jfloat result = a * 1.3f;
    return result;
}

extern "C"
JNIEXPORT jdoubleArray JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_linearSpace(JNIEnv *env, jobject, jdouble start, jdouble end, jint number) {
    auto *c_array = new jdouble[number];
    jdouble dx = (end - start) / (number - 1.0);
    for (int i = 0; i < number; i++) {
        c_array[i] = start + (i * dx);
    }

    jdoubleArray result = env->NewDoubleArray(number);
    env->SetDoubleArrayRegion(result, 0, number, c_array);

    delete[] c_array;

    return result;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_sum(JNIEnv *env, jobject, jdoubleArray values) {
    jint length = env->GetArrayLength(values);
    jdouble c_array[length];
    env->GetDoubleArrayRegion(values, 0, length, c_array);

    jdouble sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += c_array[i];
    }

    return sum;
}

extern "C"
JNIEXPORT jdoubleArray JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_squareOf(JNIEnv *env, jobject, jdoubleArray values) {
    jint length = env->GetArrayLength(values);
    jdouble c_array[length];
    env->GetDoubleArrayRegion(values, 0, length, c_array);

    for (int i = 0; i < length; i++) {
        c_array[i] *= c_array[i];
    }

    jdoubleArray result = env->NewDoubleArray(length);
    env->SetDoubleArrayRegion(result, 0, length, c_array);

    return result;
}

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_ones__II(JNIEnv *env, jobject, jint rows, jint columns) {
    jclass object_class = env->FindClass("[D");
    jobjectArray object_array = env->NewObjectArray(rows, object_class, nullptr);

    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        jdoubleArray columns_array = env->NewDoubleArray(columns);
        jdouble c_array[columns];
        for (int columnIndex = 0; columnIndex < columns; columnIndex++) {
            c_array[columnIndex] = 1.0;
        }
        env->SetDoubleArrayRegion(columns_array, 0, columns, c_array);
        env->SetObjectArrayElement(object_array, rowIndex, columns_array);
    }

    return object_array;
}

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_ones___3_3D(JNIEnv *env, jobject MathManager, jobjectArray) {
    return Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_ones__II(env, MathManager, 3, 4);
}
