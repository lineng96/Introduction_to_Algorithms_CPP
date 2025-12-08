//
// Created by 李能 on 2025/12/8.
// 最大连续子数组
//

#include "Find_max_subarray.h"
#include <iostream>

//Brute Force
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
//Divide and Conquer
namespace {
    struct MaxSubarrayResult {
        int start;
        int end;
        int sum;
    };
    MaxSubarrayResult findMaxCrossingSubarray(const std::vector<int> &prices, const int low, const int mid, const int high) {
        //search left
        int left_sum = std::numeric_limits<int>::min();
        int sum = 0;
        int max_left = mid;
        for (int i = mid; i >= low; i--) {
            sum += prices[i];
            if (sum > left_sum) {
                left_sum = sum;
                max_left = i;
            }
        }

        //search right
        int right_sum = std::numeric_limits<int>::min();
        sum = 0;
        int max_right = mid + 1;
        for (int j = mid + 1; j <= high; j++) {
            sum += prices[j];
            if (sum > right_sum) {
                right_sum = sum;
                max_right = j;
            }
        }
        // Return merged results
        return {max_left, max_right, left_sum + right_sum};
    }

    MaxSubarrayResult findMaximumSubarray(const std::vector<int> &prices, const int low, const int high) {
        if (low == high) {
            return {low, high, prices[low]};
        }
        const int mid = (low + high) / 2;
        const MaxSubarrayResult left = findMaximumSubarray(prices, low, mid);
        const MaxSubarrayResult right = findMaximumSubarray(prices, mid + 1, high);
        const MaxSubarrayResult cross = findMaxCrossingSubarray(prices, low, mid, high);

        //Return max
        if (left.sum >= right.sum && left.sum >= cross.sum) {
            return left;
        }
        if (right.sum >= left.sum && right.sum >= cross.sum) {
            return right;
        }
        return cross;
    }
}

void Find_max_subarray::maxSubarrayByDivideAndConquer(const std::vector<int> &prices) {
    if (prices.empty()) {
        std::cout << "The array is empty." << std::endl;
        return;
    }
    auto [start, end, sum] = findMaximumSubarray(prices, 0, prices.size() - 1);

    //Print the result
    std::cout << "Maximum subarray (Divide and Conquer): a["
              << start << ".." << end << "] = { ";
    for (int i = start; i <= end; i++) {
        std::cout << prices[i] << " ";
    }
    std::cout << "}" <<std::endl;
    std::cout << "Sum: " << sum << std::endl;
}