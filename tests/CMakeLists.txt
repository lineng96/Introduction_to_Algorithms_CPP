add_executable(run_tests
        Insertion_sort_Test.cpp
)

target_link_libraries(run_tests
        AlgorithmLibrary
        gtest_main
)

target_include_directories(run_tests PUBLIC
        ${PROJECT_SOURCE_DIR}/src/getting_started
)

include(GoogleTest)
gtest_discover_tests(run_tests)