#include "include/xyz_teamgravity_jnidemo_core_util_manager_TextManager.h"
#include <string>
#include <android/log.h>

namespace {
    jclass s_person_class = nullptr;
    jfieldID s_name_field = nullptr;
    jfieldID s_age_field = nullptr;
    jfieldID s_is_married_field = nullptr;
    jfieldID s_debt_field = nullptr;
    jfieldID s_status_field = nullptr;
    jfieldID s_budget_field = nullptr;
    jmethodID s_print_method = nullptr;
    jmethodID s_age_period_method = nullptr;
    jmethodID s_evaluate_method = nullptr;
    jmethodID s_bankrupt_method = nullptr;
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *) {
    JNIEnv *env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get JNIEnv.");
        return JNI_ERR;
    }

    jclass local_person_class = env->FindClass("xyz/teamgravity/jnidemo/data/model/PersonModel");
    if (local_person_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to find PersonModel class.");
        return JNI_ERR;
    }

    s_person_class = static_cast<jclass>(env->NewGlobalRef(local_person_class));
    env->DeleteLocalRef(local_person_class);

    if (s_person_class == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to create global ref for PersonModel.");
        return JNI_ERR;
    }

    s_name_field = env->GetFieldID(s_person_class, "name", "Ljava/lang/String;");
    if (s_name_field == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get name field.");
        return JNI_ERR;
    }

    s_age_field = env->GetFieldID(s_person_class, "age", "I");
    if (s_age_field == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get age field.");
        return JNI_ERR;
    }

    s_is_married_field = env->GetFieldID(s_person_class, "isMarried", "Z");
    if (s_is_married_field == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get isMarried field.");
        return JNI_ERR;
    }

    s_debt_field = env->GetFieldID(s_person_class, "debt", "D");
    if (s_debt_field == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get debt field.");
        return JNI_ERR;
    }

    s_status_field = env->GetStaticFieldID(s_person_class, "STATUS", "Ljava/lang/String;");
    if (s_status_field == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get STATUS field.");
        return JNI_ERR;
    }

    s_budget_field = env->GetStaticFieldID(s_person_class, "BUDGET", "D");
    if (s_budget_field == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get BUDGET field.");
        return JNI_ERR;
    }

    s_print_method = env->GetMethodID(s_person_class, "print", "()V");
    if (s_print_method == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get print method.");
        return JNI_ERR;
    }

    s_age_period_method = env->GetMethodID(s_person_class, "agePeriod", "()Ljava/lang/String;");
    if (s_age_period_method == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get agePeriod method.");
        return JNI_ERR;
    }

    s_evaluate_method = env->GetStaticMethodID(s_person_class, "evaluate", "(Lxyz/teamgravity/jnidemo/data/model/PersonModel;)V");
    if (s_evaluate_method == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get evaluate method.");
        return JNI_ERR;
    }

    s_bankrupt_method = env->GetStaticMethodID(s_person_class, "bankrupt", "(Lxyz/teamgravity/jnidemo/data/model/PersonModel;)V");
    if (s_bankrupt_method == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, "MainActivity", "JNI_OnLoad(): failed to get bankrupt method.");
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

    if (s_person_class != nullptr) {
        env->DeleteGlobalRef(s_person_class);
        s_person_class = nullptr;
    }

    s_person_class = nullptr;
    s_name_field = nullptr;
    s_age_field = nullptr;
    s_is_married_field = nullptr;
    s_debt_field = nullptr;
    s_status_field = nullptr;
    s_budget_field = nullptr;
    s_print_method = nullptr;
    s_age_period_method = nullptr;
    s_evaluate_method = nullptr;
    s_bankrupt_method = nullptr;
}

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

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_evaluatePerson(JNIEnv *env, jclass, jobject person) {
    auto name = (jstring) env->GetObjectField(person, s_name_field);
    const char *c_name = env->GetStringUTFChars(name, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", c_name);
    env->ReleaseStringUTFChars(name, c_name);
    env->DeleteLocalRef(name);

    jint age = env->GetIntField(person, s_age_field);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%d", age);

    jboolean is_married = env->GetBooleanField(person, s_is_married_field);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", is_married ? "true" : "false");

    jdouble debt = env->GetDoubleField(person, s_debt_field);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%f", debt);

    auto status = (jstring) env->GetStaticObjectField(s_person_class, s_status_field);
    const char *c_status = env->GetStringUTFChars(status, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", c_status);
    env->ReleaseStringUTFChars(status, c_status);
    env->DeleteLocalRef(status);

    jdouble budget = env->GetStaticDoubleField(s_person_class, s_budget_field);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%f", budget);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_divorcePerson(JNIEnv *env, jclass, jobject person) {
    env->SetBooleanField(person, s_is_married_field, JNI_FALSE);

    jstring status = env->NewStringUTF("Single");
    env->SetStaticObjectField(s_person_class, s_status_field, status);
    env->DeleteLocalRef(status);

    jdouble budget = env->GetStaticDoubleField(s_person_class, s_budget_field) / 2;
    env->SetStaticDoubleField(s_person_class, s_budget_field, budget);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_printPerson(JNIEnv *env, jclass, jobject person) {
    env->CallVoidMethod(person, s_print_method);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_agePeriod(JNIEnv *env, jclass, jobject person) {
    auto age_period = (jstring) env->CallObjectMethod(person, s_age_period_method);
    const char *c_age_period = env->GetStringUTFChars(age_period, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", c_age_period);

    env->ReleaseStringUTFChars(age_period, c_age_period);
    env->DeleteLocalRef(age_period);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_evaluate(JNIEnv *env, jclass, jobject person) {
    env->CallStaticVoidMethod(s_person_class, s_evaluate_method, person);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_bankrupt(JNIEnv *env, jclass, jobject person) {
    env->CallStaticVoidMethod(s_person_class, s_bankrupt_method, person);
}

extern "C"
JNIEXPORT jlong JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_freeMemory(JNIEnv *env, jclass) {
    jclass runtime_class = env->FindClass("java/lang/Runtime");
    jmethodID get_runtime_method = env->GetStaticMethodID(runtime_class, "getRuntime", "()Ljava/lang/Runtime;");

    jobject runtime = env->CallStaticObjectMethod(runtime_class, get_runtime_method);
    jmethodID free_memory_method = env->GetMethodID(runtime_class, "freeMemory", "()J");
    jlong free_memory = env->CallLongMethod(runtime, free_memory_method);

    env->DeleteLocalRef(runtime);
    env->DeleteLocalRef(runtime_class);

    return free_memory / 1024 / 1024;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_createPerson__Ljava_lang_String_2IZD(JNIEnv *env, jclass, jstring name, jint age, jboolean is_married, jdouble debt) {
    jmethodID constructor = env->GetMethodID(s_person_class, "<init>", "(Ljava/lang/String;IZD)V");
    jobject value = env->NewObject(s_person_class, constructor, name, age, is_married, debt);
    return value;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_TextManager_createPerson__Ljava_lang_String_2(JNIEnv *env, jclass, jstring name) {
    jmethodID constructor = env->GetMethodID(s_person_class, "<init>", "(Ljava/lang/String;)V");
    jobject value = env->NewObject(s_person_class, constructor, name);
    return value;
}