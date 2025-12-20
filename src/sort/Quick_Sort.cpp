//
// Created by 李能 on 2025/12/20.
//

#include "Quick_Sort.h"

#include <vector>

using namespace std;
using namespace Quick_Sort;

int QuickSort::partition(vector<int> &A, const int p, const int r) {
    const int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void QuickSort::quickSort(vector<int> &A, const int p, const int r) {
    if (p < r) {
        // 划分后的基准位置
        const int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}
