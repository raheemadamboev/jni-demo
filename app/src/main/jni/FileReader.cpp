#include "include/xyz_teamgravity_jnidemo_core_util_FileReader.h"
#include <string>
#include <fstream>

static jfieldID file_field;
static jfieldID handle_field;

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_FileReader_initIds(JNIEnv *env, jclass file_reader_class) {
    file_field = env->GetFieldID(file_reader_class, "file", "Ljava/lang/String;");
    handle_field = env->GetFieldID(file_reader_class, "handle", "J");
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_FileReader_open0(JNIEnv *env, jobject file_reader_object) {
    auto file_name = reinterpret_cast<jstring>(env->GetObjectField(file_reader_object, file_field));
    const char *file_name_chars = env->GetStringUTFChars(file_name, nullptr);
    if (file_name_chars == nullptr) {
        env->DeleteLocalRef(file_name);
        return;
    }

    auto *stream = new std::ifstream(file_name_chars);
    env->ReleaseStringUTFChars(file_name, file_name_chars);
    env->DeleteLocalRef(file_name);

    if (!stream->is_open()) {
        delete stream;
        jclass exception = env->FindClass("java/io/IOException");
        if (exception != nullptr) env->ThrowNew(exception, "Could not open file!");
        return;
    }

    env->SetLongField(file_reader_object, handle_field, reinterpret_cast<jlong>(stream));
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_core_util_FileReader_close0(JNIEnv *env, jobject file_reader_object) {
    auto *stream = reinterpret_cast<std::ifstream *>(env->GetLongField(file_reader_object, handle_field));
    if (stream == nullptr) return;

    delete stream;
    env->SetLongField(file_reader_object, handle_field, jlong{0});
}

extern "C"
JNIEXPORT jstring JNICALL
Java_xyz_teamgravity_jnidemo_core_util_FileReader_next0(JNIEnv *env, jobject file_reader_object) {
    auto *stream = reinterpret_cast<std::ifstream *>(env->GetLongField(file_reader_object, handle_field));
    if (stream == nullptr) return nullptr;

    std::string next;
    if (!(*stream >> next)) return nullptr;

    return env->NewStringUTF(next.c_str());
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_xyz_teamgravity_jnidemo_core_util_FileReader_eof(JNIEnv *env, jobject file_reader_object) {
    auto *stream = reinterpret_cast<std::ifstream *>(env->GetLongField(file_reader_object, handle_field));
    if (stream == nullptr) return JNI_TRUE;

    return stream->good() ? JNI_FALSE : JNI_TRUE;
}