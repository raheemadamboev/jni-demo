#include "include/xyz_teamgravity_jnidemo_data_model_PersonModel_Book.h"
#include <android/log.h>

namespace {
    jclass s_book_class;
    jmethodID s_book_to_string_method;
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *) {
    JNIEnv *env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get JNIEnv.");
        return JNI_ERR;
    }

    jclass local_book_class = env->FindClass("xyz/teamgravity/jnidemo/data/model/PersonModel$Book");
    if (local_book_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to find Book class.");
        return JNI_ERR;
    }

    s_book_class = static_cast<jclass>(env->NewGlobalRef(local_book_class));
    env->DeleteLocalRef(local_book_class);

    if (s_book_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to create global ref for Book.");
        return JNI_ERR;
    }

    s_book_to_string_method = env->GetMethodID(s_book_class, "toString", "()Ljava/lang/String;");
    if (s_book_to_string_method == nullptr) {
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

    if (s_book_class != nullptr) {
        env->DeleteGlobalRef(s_book_class);
        s_book_class = nullptr;
    }

    s_book_to_string_method = nullptr;
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_data_model_PersonModel_00024Book_printTitle(JNIEnv *env, jobject book) {
    auto value = (jstring) env->CallObjectMethod(book, s_book_to_string_method);
    const char *value_array = env->GetStringUTFChars(value, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", value_array);
    env->ReleaseStringUTFChars(value, value_array);
    env->DeleteLocalRef(value);
}