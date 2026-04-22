#include "include/xyz_teamgravity_jnidemo_core_sample_override_Parent.h"
#include <android/log.h>

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_override_Parent_mustang (JNIEnv *, jobject) {
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "Parent.mustang.shelby");
    return 500.0;
}
