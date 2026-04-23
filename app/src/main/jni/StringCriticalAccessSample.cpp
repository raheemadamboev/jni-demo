#include "xyz_teamgravity_jnidemo_core_sample_StringCriticalAccessSample.h"
#include <android/log.h>
#include <string>

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_StringCriticalAccessSample_printStringRegular(JNIEnv *env, jclass, jstring value) {
    jboolean isCopy{false};
    const char *value_array = env->GetStringUTFChars(value, &isCopy);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", value_array);
    env->ReleaseStringUTFChars(value, value_array);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_StringCriticalAccessSample_printStringCritical(JNIEnv *env, jclass, jstring value) {
    const jsize length = env->GetStringLength(value);
    const jchar *chars = env->GetStringCritical(value, nullptr);
    if (chars == nullptr) return;

    std::u16string copy(reinterpret_cast<const char16_t *>(chars), length);
    env->ReleaseStringCritical(value, chars);

    std::string utf8;
    utf8.reserve(copy.size());
    for (char16_t c : copy) {
        if (c < 0x80) {
            utf8.push_back(static_cast<char>(c));
        } else {
            utf8.append("?");
        }
    }
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", utf8.c_str());
}