//
// Created by 李能 on 2025/12/21.
//

#include "vector"
#include "Counting_Sort.h"

using namespace std;
using namespace Counting_Sort;

vector<int> CountingSort::countingSort(const vector<int> &A, const int k) {
    const int n = A.size();
    vector<int> B(n);
    vector C(k + 1, 0);

    // 1. 频率
    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }
    // 2.累加频率
    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }
    // 3.反向填充
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
    return B;
}
