//
// Created by 李能 on 2025/12/18.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_CPP_HEAPSORT_H
#define INTRODUCTION_TO_ALGORITHMS_CPP_HEAPSORT_H
#include <vector>

namespace Heap_Sort {
    class HeapSort {
    public:
        static void heapSort(std::vector<int> &A);

    private:
        static void maxHeapify(std::vector<int> &A, int i, int heapSize);

        static void buildMaxHeap(std::vector<int> &A);
    };
}


#endif //INTRODUCTION_TO_ALGORITHMS_CPP_HEAPSORT_H