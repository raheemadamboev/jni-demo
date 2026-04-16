#include "xyz_teamgravity_jnidemo_core_sample_override_Child.h"
#include <android/log.h>

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_sample_override_Child_malibu(JNIEnv *, jobject) {
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "Child.malibu.xl");
    return 233.0;
}