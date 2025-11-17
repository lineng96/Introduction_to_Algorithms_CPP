//
// Created by 李能 on 2025/11/17.
//

#include "ArrayUtil.h"

#include <iostream>

void ArrayUtil::printArray(const std::vector<int> &arr) {
    std::cout << "";
    size_t n = arr.size();
    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}
