cmake_minimum_required(VERSION 4.0)
project(Introduction_to_Algorithms_CPP)

set(CMAKE_CXX_STANDARD 26)
set(BUILD_SHARED_LIBS OFF)

add_subdirectory(libs/googletest)

add_library(AlgorithmLibrary
        src/getting_started/Insertion_sort.cpp
        src/util/ArrayUtil.cpp
)

target_include_directories(AlgorithmLibrary PUBLIC
        ${PROJECT_SOURCE_DIR}/src/getting_started
        ${PROJECT_SOURCE_DIR}/libs/googletest/googletest/include
)

add_executable(MainDemo main.cpp)
target_link_libraries(MainDemo AlgorithmLibrary)

add_subdirectory(tests)