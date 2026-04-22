#include "include/xyz_teamgravity_jnidemo_core_util_manager_MathManager.h"
#include "third_party/gsl/include/gsl/gsl_mode.h"
#include "third_party/gsl/include/gsl/gsl_sf_airy.h"
#include "third_party/gsl/include/gsl/gsl_roots.h"
#include <android/log.h>
#include <limits>

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
    for (jint i = 0; i < number; i++) {
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
    for (jint i = 0; i < length; i++) {
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

    for (jint i = 0; i < length; i++) {
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

    for (jint rowIndex = 0; rowIndex < rows; rowIndex++) {
        jdoubleArray columns_array = env->NewDoubleArray(columns);
        jdouble c_array[columns];
        for (jint columnIndex = 0; columnIndex < columns; columnIndex++) {
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

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_max(JNIEnv *env, jobject, jobjectArray values) {
    if (values == nullptr) {
        return std::numeric_limits<jdouble>::quiet_NaN();
    }

    jint row_length = env->GetArrayLength(values);
    if (row_length == 0) {
        return std::numeric_limits<jdouble>::quiet_NaN();
    }

    jdouble max = -std::numeric_limits<jdouble>::infinity();

    for (jint row_index = 0; row_index < row_length; row_index++) {
        auto column_array = (jdoubleArray) (env->GetObjectArrayElement(values, row_index));
        if (column_array == nullptr) continue;

        jint column_length = env->GetArrayLength(column_array);
        if (column_length > 0) {

            jdouble *elements = env->GetDoubleArrayElements(column_array, nullptr);
            if (elements != nullptr) {

                for (jint column_index = 0; column_index < column_length; column_index++) {
                    if (max < elements[column_index]) {
                        max = elements[column_index];
                    }
                }

                env->ReleaseDoubleArrayElements(column_array, elements, JNI_ABORT);
            }
        }

        env->DeleteLocalRef(column_array);
    }

    return max;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_callValue(JNIEnv *env, jobject, jobject function, jdouble x) {
    jclass math_function_class = env->FindClass("xyz/teamgravity/jnidemo/core/util/MathFunction");
    jmethodID value_method = env->GetMethodID(math_function_class, "value", "(D)D");
    jdouble value = env->CallDoubleMethod(function, value_method, x);
    env->DeleteLocalRef(math_function_class);
    return value;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_callValueScaled(JNIEnv *env, jobject, jobject function, jdouble x) {
    jclass math_function_class = env->FindClass("xyz/teamgravity/jnidemo/core/util/MathFunction");
    jmethodID value_scaled_method = env->GetMethodID(math_function_class, "valueScaled", "(D)D");
    jdouble value = env->CallDoubleMethod(function, value_scaled_method, x);
    env->DeleteLocalRef(math_function_class);
    return value;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_callFunctionScaled(JNIEnv *env, jobject, jobject function) {
    jclass math_function_class = env->FindClass("xyz/teamgravity/jnidemo/core/util/MathFunction");
    jmethodID function_scaled_method = env->GetStaticMethodID(math_function_class, "functionScaled", "(Lxyz/teamgravity/jnidemo/core/util/MathFunction;)Lxyz/teamgravity/jnidemo/core/util/MathFunction;");
    jobject value = env->CallStaticObjectMethod(math_function_class, function_scaled_method, function);
    env->DeleteLocalRef(math_function_class);
    return value;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_ai(JNIEnv *env, jclass, jdouble x) {
    return gsl_sf_airy_Ai(x, GSL_MODE_DEFAULT);
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_bi(JNIEnv *env, jclass, jdouble x) {
    return gsl_sf_airy_Bi(x, GSL_MODE_DEFAULT);
}

extern "C"
JNIEXPORT jint JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_rooTestResidual(JNIEnv *env, jclass, jobject f, jobject epsabs) {
    jclass double_class = env->FindClass("java/lang/Double");
    jmethodID double_value_method = env->GetMethodID(double_class, "doubleValue", "()D");
    jdouble f_value = env->CallDoubleMethod(f, double_value_method);
    jdouble epsabs_value = env->CallDoubleMethod(epsabs, double_value_method);
    env->DeleteLocalRef(double_class);
    return gsl_root_test_residual(f_value, epsabs_value);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_scale__Ljava_util_List_2(JNIEnv *env, jclass, jobject values) {
    jclass list_class = env->FindClass("java/util/List");
    jmethodID list_get_method = env->GetMethodID(list_class, "get", "(I)Ljava/lang/Object;");
    jmethodID list_set_method = env->GetMethodID(list_class, "set", "(ILjava/lang/Object;)Ljava/lang/Object;");
    jmethodID list_size_method = env->GetMethodID(list_class, "size", "()I");

    jclass double_class = env->FindClass("java/lang/Double");
    jmethodID double_double_value_method = env->GetMethodID(double_class, "doubleValue", "()D");
    jmethodID double_value_of_method = env->GetStaticMethodID(double_class, "valueOf", "(D)Ljava/lang/Double;");

    jint size = env->CallIntMethod(values, list_size_method);

    for (jint i = 0; i < size; i++) {
        jobject element = env->CallObjectMethod(values, list_get_method, i);
        if (element == nullptr) continue;

        jdouble value = env->CallDoubleMethod(element, double_double_value_method);
        jdouble calculated = value * 5.0;
        jobject boxed = env->CallStaticObjectMethod(double_class, double_value_of_method, calculated);
        jobject returned = env->CallObjectMethod(values, list_set_method, i, boxed);

        env->DeleteLocalRef(element);
        env->DeleteLocalRef(boxed);
        env->DeleteLocalRef(returned);
    }

    env->DeleteLocalRef(list_class);
    env->DeleteLocalRef(double_class);

    return values;
}

extern "C"
JNIEXPORT jdoubleArray JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_MathManager_scale___3D(JNIEnv *env, jclass, jdoubleArray values) {
    jint length = env->GetArrayLength(values);

    jdouble *elements = env->GetDoubleArrayElements(values, nullptr);
    if (elements == nullptr) return values;

    for (jint i = 0; i < length; i++) {
        elements[i] *= 5.0;
    }

    env->ReleaseDoubleArrayElements(values, elements, 0);

    return values;
}