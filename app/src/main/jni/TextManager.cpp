#include "xyz_teamgravity_jnidemo_core_util_manager_TextManager.h"
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_hello(JNIEnv *env, jclass) {
    std::string text = "Hello World!";
    return env->NewStringUTF(text.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_print(JNIEnv *env, jclass, jstring message) {
    const char *c_array = env->GetStringUTFChars(message, nullptr);
    printf("printing in C++: %s", c_array);
    env->ReleaseStringUTFChars(message, c_array);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_concat(JNIEnv *env, jclass, jstring a, jstring b) {
    const char *text_1 = env->GetStringUTFChars(a, nullptr);
    std::string text_1_str = text_1;
    const char *text_2 = env->GetStringUTFChars(b, nullptr);
    std::string text_2_str = text_2;
    std::string result = text_1_str + text_2_str;

    env->ReleaseStringUTFChars(a, text_1);
    env->ReleaseStringUTFChars(b, text_2);

    return env->NewStringUTF(result.c_str());
}