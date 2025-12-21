//
// Created by 李能 on 2025/11/17.
//
#include "gtest/gtest.h"

#include "ArrayUtil.h"
#include "Insertion_sort.h"
#include "Merge_sort.h"
#include "Heap_Sort.h"
#include "Quick_Sort.h"
#include "Counting_Sort.h"
#include "Radix_Sort.h"
#include "Bucket_Sort.h"
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
    const size_t n = data.size();

    std::cout << "原始数组: ";
    ArrayUtil::printArray(data);

    // MergeSort
    Merge_sort::mergeSort(data, 0, n - 1);

    std::cout << "排序结果: ";
    ArrayUtil::printArray(data);
}

TEST(HeapSort, HeapSort) {
    std::vector data = {12, 11, 13, 5, 6, 7};

    std::cout << "原始数组: ";
    ArrayUtil::printArray(data);

    // HeapSort
    Heap_Sort::HeapSort::heapSort(data);

    std::cout << "排序结果: ";
    ArrayUtil::printArray(data);
}

TEST(QuickSort, QuickSort) {
    std::vector data = {12, 11, 13, 5, 6, 7};
    std::cout << "原始数组: ";
    ArrayUtil::printArray(data);

    // QuickSort
    Quick_Sort::QuickSort::quickSort(data, 0, data.size() - 1);

    std::cout << "排序结果: ";
    ArrayUtil::printArray(data);
}

TEST(CountingSort, CountingSort) {
    std::vector data = {12, 11, 13, 5, 6, 7};
    std::cout << "原始数组: ";
    ArrayUtil::printArray(data);

    // CountingSort
    constexpr int k = 13;
    const std::vector<int> B = Counting_Sort::CountingSort::countingSort(data, k);

    std::cout << "排序结果: ";
    ArrayUtil::printArray(B);
}

TEST(RadixSort, RadixSort) {
    std::vector data = {12, 11, 13, 5, 6, 7};
    std::cout << "原始数组: ";
    ArrayUtil::printArray(data);

    // RadixSort
    Radix_Sort::RadixSort::radixSort(data);

    std::cout << "排序结果: ";
    ArrayUtil::printArray(data);
}

TEST(BucketSort, BucketSort) {
    std::vector<float> data = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    std::cout << "原始数组: ";
    ArrayUtil::printArray(data);

    // bucketSort
    Bucket_Sort::BucketSort::bucketSort(data);

    std::cout << "排序结果: ";
    ArrayUtil::printArray(data);
}