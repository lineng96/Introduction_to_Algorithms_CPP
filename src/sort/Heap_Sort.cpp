//
// Created by 李能 on 2025/12/18.
//

#include "Heap_Sort.h"
#include <vector>
#include <algorithm>

using namespace std;
using namespace Heap_Sort;

void HeapSort::maxHeapify(vector<int> &A, const int i, const int heapSize) {
    const int left_child = 2 * i + 1;
    const int right_child = 2 * i + 2;
    int largest = i;

    if (left_child < heapSize && A[left_child] > A[largest]) {
        largest = left_child;
    }
    if (right_child < heapSize && A[right_child] > A[largest]) {
        largest = right_child;
    }
    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, largest, heapSize);
    }
}

void HeapSort::buildMaxHeap(vector<int> &A) {
    const int heapSize = A.size();
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        maxHeapify(A, i, heapSize);
    }
}

void HeapSort::heapSort(vector<int> &A) {
    int heapSize = A.size();
    buildMaxHeap(A);
    for (int i = heapSize - 1; i > 0; i--) {
        swap(A[i], A[0]);
        heapSize--;
        maxHeapify(A, 0, heapSize);
    }
}
