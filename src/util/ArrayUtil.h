//
// Created by 李能 on 2025/11/17.
//

#ifndef INTRODUCTIONTOALGORITHMS_ARRAYUTIL_H
#define INTRODUCTIONTOALGORITHMS_ARRAYUTIL_H
#include <vector>
#include <iostream>
#include <type_traits>


namespace ArrayUtil {
    template<typename T>
    void printArray(const std::vector<T> &arr) {
        static_assert(std::is_arithmetic_v<T>, "printArray only supports arithmetic types (int, float, double, etc.)");
        std::cout << "[";
        const size_t n = arr.size();
        for (size_t i = 0; i < n; ++i) {
            std::cout << arr[i];
            if (i < n - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
};


#endif //INTRODUCTIONTOALGORITHMS_ARRAYUTIL_H
