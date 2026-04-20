#include "xyz_teamgravity_jnidemo_core_util_manager_TextManager.h"
#include <string>
#include <android/log.h>

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
    jclass person_class = env->FindClass("xyz/teamgravity/jnidemo/data/model/PersonModel");

    jfieldID name_field = env->GetFieldID(person_class, "name", "Ljava/lang/String;");
    auto name = (jstring) env->GetObjectField(person, name_field);
    const char *c_name = env->GetStringUTFChars(name, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", c_name);
    env->ReleaseStringUTFChars(name, c_name);
    env->DeleteLocalRef(name);

    jfieldID age_field = env->GetFieldID(person_class, "age", "I");
    jint age = env->GetIntField(person, age_field);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%d", age);

    jfieldID is_married_field = env->GetFieldID(person_class, "isMarried", "Z");
    jboolean is_married = env->GetBooleanField(person, is_married_field);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", is_married ? "true" : "false");

    jfieldID debt_field = env->GetFieldID(person_class, "debt", "D");
    jdouble debt = env->GetDoubleField(person, debt_field);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%f", debt);

    jfieldID status_field = env->GetStaticFieldID(person_class, "status", "Ljava/lang/String;");
    auto status = (jstring) env->GetStaticObjectField(person_class, status_field);
    const char *c_status = env->GetStringUTFChars(status, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s", c_status);
    env->ReleaseStringUTFChars(status, c_status);
    env->DeleteLocalRef(status);

    jfieldID budget_field = env->GetStaticFieldID(person_class, "budget", "D");
    jdouble budget = env->GetStaticDoubleField(person_class, budget_field);
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%f", budget);

    env->DeleteLocalRef(person_class);
}