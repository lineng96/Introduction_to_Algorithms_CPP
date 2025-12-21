//
// Created by 李能 on 2025/12/21.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_CPP_RADIX_SORT_H
#define INTRODUCTION_TO_ALGORITHMS_CPP_RADIX_SORT_H

namespace Radix_Sort {
    class RadixSort {
    public:
        static void radixSort(std::vector<int> &A);

    private:
        static int getMax(const std::vector<int> &A);

        static void countingSortForRadix(std::vector<int> &A, int exp);
    };
}


#endif //INTRODUCTION_TO_ALGORITHMS_CPP_RADIX_SORT_H
