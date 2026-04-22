#include "include/xyz_teamgravity_jnidemo_core_util_manager_AnimalManager.h"
#include <android/log.h>

namespace {
    jclass s_animal_class = nullptr;
    jmethodID s_animal_speak_method = nullptr;
    jclass s_dog_class = nullptr;
    jmethodID s_dog_speak_method = nullptr;
    jclass s_cat_class = nullptr;
    jmethodID s_cat_speak_method = nullptr;
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *) {
    JNIEnv *env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get JNIEnv.");
        return JNI_ERR;
    }

    jclass local_animal_class = env->FindClass("xyz/teamgravity/jnidemo/data/model/AnimalModel");
    if (local_animal_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to find AnimalModel class.");
        return JNI_ERR;
    }

    s_animal_class = static_cast<jclass>(env->NewGlobalRef(local_animal_class));
    env->DeleteLocalRef(local_animal_class);

    if (s_animal_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to create global ref for AnimalModel.");
        return JNI_ERR;
    }

    s_animal_speak_method = env->GetMethodID(s_animal_class, "speak", "()Ljava/lang/String;");
    if (s_animal_speak_method == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get Animal.speak method.");
        return JNI_ERR;
    }

    jclass local_dog_class = env->FindClass("xyz/teamgravity/jnidemo/data/model/DogModel");
    if (local_dog_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to find DogModel class.");
        return JNI_ERR;
    }

    s_dog_class = static_cast<jclass>(env->NewGlobalRef(local_dog_class));
    env->DeleteLocalRef(local_dog_class);

    if (s_dog_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to create global ref for DogModel.");
        return JNI_ERR;
    }

    s_dog_speak_method = env->GetMethodID(s_dog_class, "speak", "()Ljava/lang/String;");
    if (s_dog_speak_method == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get Dog.speak method.");
        return JNI_ERR;
    }

    jclass local_cat_class = env->FindClass("xyz/teamgravity/jnidemo/data/model/CatModel");
    if (local_cat_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to find CatModel class.");
        return JNI_ERR;
    }

    s_cat_class = static_cast<jclass>(env->NewGlobalRef(local_cat_class));
    env->DeleteLocalRef(local_cat_class);

    if (s_cat_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to create global ref for CatModel.");
        return JNI_ERR;
    }

    s_cat_speak_method = env->GetMethodID(s_cat_class, "speak", "()Ljava/lang/String;");
    if (s_cat_speak_method == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get Cat.speak method.");
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

    if (s_animal_class != nullptr) {
        env->DeleteGlobalRef(s_animal_class);
        s_animal_class = nullptr;
    }

    s_animal_speak_method = nullptr;

    if (s_dog_class != nullptr) {
        env->DeleteGlobalRef(s_dog_class);
        s_dog_class = nullptr;
    }

    s_dog_speak_method = nullptr;

    if (s_cat_class != nullptr) {
        env->DeleteGlobalRef(s_cat_class);
        s_cat_class = nullptr;
    }

    s_cat_speak_method = nullptr;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_AnimalManager_speak(JNIEnv *env, jclass, jobject animal) {
    auto value = (jstring) env->CallObjectMethod(animal, s_animal_speak_method);
    return value;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_AnimalManager_animalSpeak(JNIEnv *env, jclass, jobject animal) {
    auto value = (jstring) env->CallNonvirtualObjectMethod(animal, s_animal_class, s_animal_speak_method);
    return value;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_AnimalManager_dogSpeak(JNIEnv *env, jclass, jobject animal) {
    auto value = (jstring) env->CallNonvirtualObjectMethod(animal, s_dog_class, s_dog_speak_method);
    return value;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_AnimalManager_catSpeak(JNIEnv *env, jclass, jobject animal) {
    auto value = (jstring) env->CallNonvirtualObjectMethod(animal, s_cat_class, s_cat_speak_method);
    return value;
}