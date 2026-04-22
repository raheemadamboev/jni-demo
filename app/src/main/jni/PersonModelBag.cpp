#include "include/xyz_teamgravity_jnidemo_data_model_PersonModel_Bag.h"
#include <android/log.h>

namespace {
    jclass s_bag_class;
    jmethodID s_bag_to_string_method;
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *) {
    JNIEnv *env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get JNIEnv.");
        return JNI_ERR;
    }

    jclass local_bag_class = env->FindClass("xyz/teamgravity/jnidemo/data/model/PersonModel$Bag");
    if (local_bag_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to find Bag class.");
        return JNI_ERR;
    }

    s_bag_class = static_cast<jclass>(env->NewGlobalRef(local_bag_class));
    env->DeleteLocalRef(local_bag_class);

    if (s_bag_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to create global ref for Bag.");
        return JNI_ERR;
    }

    s_bag_to_string_method = env->GetMethodID(s_bag_class, "toString", "()Ljava/lang/String;");
    if (s_bag_to_string_method == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get toString method.");
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}

extern "C"
JNIEXPORT void JNICALL
JNI_OnUnload(JavaVM *vm, void *) {
    JNIEnv *env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return;
    }

    if (s_bag_class != nullptr) {
        env->DeleteGlobalRef(s_bag_class);
        s_bag_class = nullptr;
    }

    s_bag_to_string_method = nullptr;
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_data_model_PersonModel_00024Bag_printSize__(JNIEnv *env, jobject bag) {
    auto value = (jstring) env->CallObjectMethod(bag, s_bag_to_string_method);
    const char *value_array = env->GetStringUTFChars(value, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", value_array);
    env->ReleaseStringUTFChars(value, value_array);
    env->DeleteLocalRef(value);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_data_model_PersonModel_00024Bag_printSize__Lxyz_teamgravity_jnidemo_data_model_PersonModel_00024Bag_2(JNIEnv *env, jclass, jobject bag) {
    auto value = (jstring) env->CallObjectMethod(bag, s_bag_to_string_method);
    const char *value_array = env->GetStringUTFChars(value, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", value_array);
    env->ReleaseStringUTFChars(value, value_array);
    env->DeleteLocalRef(value);
}