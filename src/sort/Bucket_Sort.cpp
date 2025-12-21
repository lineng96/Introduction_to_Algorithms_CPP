//
// Created by 李能 on 2025/12/21.
//

#include "vector"
#include "Bucket_Sort.h"

#include <algorithm>

using namespace std;
using namespace Bucket_Sort;


void BucketSort::bucketSort(vector<float> &A) {
    const int n = A.size();

    vector<vector<float> > buckets(n);

    // 将元素分发到各个桶
    for (int i = 0; i < n; i++) {
        const int bucketIndex = n * A[i];
        buckets[bucketIndex].push_back(A[i]);
    }

    // 对每个桶排序
    for (int i = 0; i < n; i++) {
        ranges::sort(buckets[i]);
    }

    // 合并桶中的结果
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (const float val: buckets[i]) {
            A[index++] = val;
        }
    }
}
