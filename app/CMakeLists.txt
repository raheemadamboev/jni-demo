cmake_minimum_required(VERSION 3.22.1)
project(JNIDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GSL_DIR ${CMAKE_SOURCE_DIR}/src/main/jni/third_party/gsl)

add_library(gsl STATIC IMPORTED)
set_target_properties(gsl PROPERTIES IMPORTED_LOCATION ${GSL_DIR}/lib/${ANDROID_ABI}/libgsl.a)

add_library(gslcblas STATIC IMPORTED)
set_target_properties(gslcblas PROPERTIES IMPORTED_LOCATION ${GSL_DIR}/lib/${ANDROID_ABI}/libgslcblas.a)

add_library(math_manager SHARED src/main/jni/MathManager.cpp)
add_library(loan_manager SHARED src/main/jni/LoanManager.cpp)
add_library(overload_sample SHARED src/main/jni/OverloadSample.cpp)
add_library(parent SHARED src/main/jni/Parent.cpp)
add_library(child SHARED src/main/jni/Child.cpp)
add_library(text_manager SHARED src/main/jni/TextManager.cpp)
add_library(animal_manager SHARED src/main/jni/AnimalManager.cpp)

target_include_directories(math_manager PRIVATE src/main/jni/ ${GSL_DIR}/include)
target_include_directories(loan_manager PRIVATE src/main/jni/)
target_include_directories(overload_sample PRIVATE src/main/jni)
target_include_directories(parent PRIVATE src/main/jni)
target_include_directories(child PRIVATE src/main/jni)
target_include_directories(text_manager PRIVATE src/main/jni)
target_include_directories(animal_manager PRIVATE src/main/jni)

find_library(log-lib log)

target_link_libraries(math_manager gsl gslcblas ${log-lib} m)
target_link_libraries(overload_sample ${log-lib})
target_link_libraries(parent ${log-lib})
target_link_libraries(child ${log-lib})
target_link_libraries(text_manager ${log-lib})
target_link_libraries(animal_manager ${log-lib})