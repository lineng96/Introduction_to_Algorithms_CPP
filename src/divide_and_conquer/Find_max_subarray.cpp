//
// Created by 李能 on 2025/12/8.
// 最大连续子数组
//

#include "Find_max_subarray.h"
#include <iostream>

void Find_max_subarray::maxSubarrayByBruteForce(const std::vector<int> &prices) {
    const size_t n = prices.size();
    int max_profit = 0;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += prices[j];
            if (current_sum > max_profit) {
                max_profit = current_sum;
                start = i;
                end = j;
            }
        }
    }
    std::cout << "Maximum subarray: a[" << start << ".." << end << "] = { ";
    for (int i = start; i <= end; i++) {
        std::cout << prices[i] << " ";
    }
    std::cout << "}" << std::endl;
    std::cout << "Sum: " << max_profit << std::endl;
}