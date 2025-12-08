//
// Created by 李能 on 2025/12/8.
//
#include "gtest/gtest.h"

#include "Find_max_subarray.h"

TEST(MaxSubarrayTest, BruteForce_PrintOnly) {
    const std::vector prices = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    Find_max_subarray::maxSubarrayByBruteForce(prices);
}