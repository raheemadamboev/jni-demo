#include "xyz_teamgravity_jnidemo_core_util_manager_LoanManager.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_xyz_teamgravity_jnidemo_core_util_manager_LoanManager_calculateExtra(JNIEnv *, jclass, jdouble amount) {
    return amount * 0.3;
}