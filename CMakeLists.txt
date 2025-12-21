cmake_minimum_required(VERSION 4.0)
project(Introduction_to_Algorithms_CPP)

set(CMAKE_CXX_STANDARD 26)
set(BUILD_SHARED_LIBS OFF)

add_subdirectory(libs/googletest)

add_library(AlgorithmLibrary
        src/util/ArrayUtil.cpp
        src/getting_started/Insertion_sort.cpp
        src/getting_started/Merge_sort.cpp
        src/divide_and_conquer/Find_max_subarray.cpp
        src/divide_and_conquer/Matrix_multiplication.cpp
        src/sort/Heap_Sort.cpp
        src/sort/Quick_Sort.cpp
        src/sort/Counting_Sort.cpp
        src/sort/Radix_Sort.cpp
        src/sort/Bucket_Sort.cpp
)

target_include_directories(AlgorithmLibrary PUBLIC
        ${PROJECT_SOURCE_DIR}/libs/googletest/googletest/include
        ${PROJECT_SOURCE_DIR}/src/getting_started
        ${PROJECT_SOURCE_DIR}/src/util
        ${PROJECT_SOURCE_DIR}/src/divide_and_conquer
        ${PROJECT_SOURCE_DIR}/src/sort
)

add_executable(MainDemo main.cpp)
target_link_libraries(MainDemo AlgorithmLibrary)

add_subdirectory(tests)