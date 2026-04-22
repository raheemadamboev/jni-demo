#include "include/xyz_teamgravity_jnidemo_core_util_FileReader.h"
#include <string>
#include <fstream>

static jfieldID file_field;
static std::ifstream file_input;

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_FileReader_initIds(JNIEnv *env, jclass file_reader_class) {
    file_field = env->GetFieldID(file_reader_class, "file", "Ljava/lang/String;");
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_FileReader_open0(JNIEnv *env, jobject file_reader_object) {
    auto file_name = (jstring) env->GetObjectField(file_reader_object, file_field);
    const char *file_name_chars = env->GetStringUTFChars(file_name, nullptr);
    file_input.open(file_name_chars);
    env->ReleaseStringUTFChars(file_name, file_name_chars);
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_FileReader_close0(JNIEnv *, jobject) {
    file_input.close();
}

extern "C"
JNIEXPORT jstring JNICALL
Java_xyz_teamgravity_jnidemo_core_util_FileReader_next0(JNIEnv *env, jobject) {
    std::string next;
    file_input >> next;
    return env->NewStringUTF(next.c_str());
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_xyz_teamgravity_jnidemo_core_util_FileReader_eof(JNIEnv *, jobject) {
    return file_input.eof();
}