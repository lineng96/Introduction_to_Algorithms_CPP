//
// Created by 李能 on 2025/11/17.
//
#include "gtest/gtest.h"

#include "../src/getting_started/Insertion_sort.h"
#include <vector>
#include "../src/util/ArrayUtil.h"

TEST(InsertionSortTest, HandlesEmptyArray) {
    std::vector<int> arr = {};
    Insertion_sort::sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(InsertionSortTest, SortsAscendingOrder) {
    std::vector arr = {1, 2, 3, 4, 5};
    std::vector expected = {1, 3, 2, 5, 4};

    Insertion_sort::sort(expected);
    ArrayUtil::printArray(expected);

    //Reverse orderf
    Insertion_sort::reverseSort(expected);
    ArrayUtil::printArray(expected);
}
