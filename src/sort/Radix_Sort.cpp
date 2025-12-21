//
// Created by 李能 on 2025/12/21.
//

#include "vector"
#include "Radix_Sort.h"

using namespace std;
using namespace Radix_Sort;

// 获取数组中的最大值，确定需要排多少位
int RadixSort::getMax(const vector<int> &A) {
    int maxValue = A[0];
    for (const int x: A) {
        if (x > maxValue) {
            maxValue = x;
        }
    }
    return maxValue;
}

// 对于特定的位进行稳定的计数排序（exp，例如：1，10，100，...）
void RadixSort::countingSortForRadix(vector<int> &A, const int exp) {
    const int n = A.size();
    vector<int> output(n);
    int count[10] = {0};

    // 1.统计当前位(A[i] / exp) % 10出现的次数
    for (int i = 0; i < n; i++) {
        count[A[i] / exp % 10]++;
    }

    // 2.累加频率，确定位置
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 3.反向填充（保持稳定性）
    for (int i = n - 1; i >= 0; i--) {
        const int digit = A[i] / exp % 10;
        output[count[digit] - 1] = A[i];
        count[digit]--;
    }

    //4.写回原数组
    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

void RadixSort::radixSort(vector<int> &A) {
    const int m = getMax(A);

    //从个位开始执行
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSortForRadix(A, exp);
    }
}
