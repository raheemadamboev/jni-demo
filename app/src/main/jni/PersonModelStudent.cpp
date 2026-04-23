#include "xyz_teamgravity_jnidemo_data_model_PersonModel_Student.h"
#include <android/log.h>

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_data_model_PersonModel_000241Student_print(JNIEnv *env, jobject student_obj) {
    jclass student_class = env->GetObjectClass(student_obj);
    jmethodID to_string_method = env->GetMethodID(student_class, "toString", "()Ljava/lang/String;");
    auto value = (jstring) env->CallObjectMethod(student_obj, to_string_method);
    const char *value_array = env->GetStringUTFChars(value, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", value_array);
    env->ReleaseStringUTFChars(value, value_array);
    env->DeleteLocalRef(value);
    env->DeleteLocalRef(student_class);
}