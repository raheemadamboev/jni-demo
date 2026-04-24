#include "include/PeopleModel.h"
#include "include/xyz_teamgravity_jnidemo_data_model_PeopleModel.h"

People::People(std::string name, int age) : name(name), age(age) {
}

People::~People() noexcept = default;

std::string &People::getName() {
    return this->name;
}

int People::getAge() const {
    return this->age;
}

void People::sayHi() {
}

extern "C"
JNIEXPORT jlong JNICALL
Java_xyz_teamgravity_jnidemo_data_model_PeopleModel_allocate0(JNIEnv *env, jclass, jstring name, jint age) {
    const char *name_c = env->GetStringUTFChars(name, nullptr);
    auto *people = new People(name_c, age);
    env->ReleaseStringUTFChars(name, name_c);
    return (jlong) people;
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_data_model_PeopleModel_free0(JNIEnv *, jclass, jlong pointer) {
    auto people = (People *) pointer;
    delete people;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_xyz_teamgravity_jnidemo_data_model_PeopleModel_getName0(JNIEnv *env, jobject, jlong pointer) {
    auto people = (People *) pointer;
    return env->NewStringUTF(people->getName().c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_xyz_teamgravity_jnidemo_data_model_PeopleModel_getAge0(JNIEnv *, jobject, jlong pointer) {
    auto people = (People *) pointer;
    return people->getAge();
}

extern "C"
JNIEXPORT void JNICALL
Java_xyz_teamgravity_jnidemo_data_model_PeopleModel_sayHi0(JNIEnv *, jobject, jlong pointer) {
    auto people = (People *) pointer;
    people->sayHi();
}