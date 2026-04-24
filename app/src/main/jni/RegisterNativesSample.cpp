#include <jni.h>
#include <android/log.h>

jint function_a(JNIEnv *env, jclass, jint value) {
    return value * 2;
}

jstring function_b(JNIEnv *env, jobject) {
    return env->NewStringUTF("RegisterNatives for registering Java native methods dynamically!");
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *) {
    JNIEnv *env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get JNIEnv.");
        return JNI_ERR;
    }

    jclass register_natives_sample_class = env->FindClass("xyz/teamgravity/jnidemo/core/sample/RegisterNativesSample");
    if (register_natives_sample_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to find RegisterNativesSample class.");
        return JNI_ERR;
    }

    static const JNINativeMethod methods[] = {
            {"doubleValue", "(I)I", (void *) function_a},
            {"sayHi", "()Ljava/lang/String;", (void *) function_b},
    };
    jint result = env->RegisterNatives(register_natives_sample_class, methods, sizeof(methods) / sizeof(methods[0]));
    if (result != JNI_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to register native methods.");
        return JNI_ERR;
    }

    env->DeleteLocalRef(register_natives_sample_class);

    return JNI_VERSION_1_6;
}