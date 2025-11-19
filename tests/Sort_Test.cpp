//
// Created by 李能 on 2025/11/17.
//
#include "gtest/gtest.h"

#include "ArrayUtil.h"
#include "Insertion_sort.h"
#include "Merge_sort.h"
#include <vector>


TEST(InsertionSortTest, HandlesEmptyArray) {
    std::vector<int> arr = {};
    Insertion_sort::sort(arr);
    EXPECT_TRUE(arr.empty());
}

//insertion_sort
TEST(InsertionSortTest, SortsAscendingAndDescendingOrder) {
    std::vector expected = {1, 3, 2, 5, 4};

    Insertion_sort::sort(expected);
    ArrayUtil::printArray(expected);

    //Descending order
    Insertion_sort::reverseSort(expected);
    ArrayUtil::printArray(expected);
}

TEST(MergeSortTest, SortsAscendingOrder) {
    std::vector data = {12, 11, 13, 5, 6, 7};
    const int n = data.size();

    std::cout << "原始数组: ";
    ArrayUtil::printArray(data);

    // MergeSort
    Merge_sort::mergeSort(data, 0, n - 1);

    std::cout << "排序结果: ";
    ArrayUtil::printArray(data);
}
