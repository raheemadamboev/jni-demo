cmake_minimum_required(VERSION 3.4.1)
project(JNIDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(math_manager SHARED src/main/jni/MathManager.cpp)
add_library(loan_manager SHARED src/main/jni/LoanManager.cpp)

target_include_directories(math_manager PRIVATE src/main/jni/)
target_include_directories(loan_manager PRIVATE src/main/jni/)

find_library(log-lib log)
target_link_libraries(math_manager ${log-lib})
target_link_libraries(loan_manager ${log-lib})