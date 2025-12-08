//
// Created by 李能 on 2025/11/17.
//

#include "Insertion_sort.h"

void Insertion_sort::sort(std::vector<int> &arr) {
    const size_t n = arr.size();
    for (int i = 1; i < n; ++i) {
        const int current_value = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current_value) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current_value;
    }
}
//Reverse order
void Insertion_sort::reverseSort(std::vector<int> &arr) {
    const size_t n = arr.size();
    for (int i = 0; i < n; ++i) {
        const int current_value = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < current_value) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current_value;
    }
}
