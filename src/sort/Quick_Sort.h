//
// Created by 李能 on 2025/12/20.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_CPP_QUICK_SORT_H
#define INTRODUCTION_TO_ALGORITHMS_CPP_QUICK_SORT_H
#include <vector>

namespace Quick_Sort {
    class QuickSort {
    public:
        static void quickSort(std::vector<int> &A, int p, int r);

    private:
        static int partition(std::vector<int> &A, int p, int r);
    };
}


#endif //INTRODUCTION_TO_ALGORITHMS_CPP_QUICK_SORT_H
