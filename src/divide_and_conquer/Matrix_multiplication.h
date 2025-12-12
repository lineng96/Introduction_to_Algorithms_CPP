//
// Created by 李能 on 2025/12/12.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_CPP_MATRIX_MULTIPLICATION_H
#define INTRODUCTION_TO_ALGORITHMS_CPP_MATRIX_MULTIPLICATION_H
#include <vector>

namespace Matrix_multiplication {
    class MatrixMultiplication {
    public:

        // 打印
        static void printMatrix(const std::vector<std::vector<int> > &C);

        // 暴力求解
        static std::vector<std::vector<int> > bruteForce(const std::vector<std::vector<int> > &A,
                                                         const std::vector<std::vector<int> > &B,
                                                         int n);

        // Strassen 算法
        static std::vector<std::vector<int> > matrixStrassen(const std::vector<std::vector<int> > &A,
                                                             const std::vector<std::vector<int> > &B,
                                                             int n);

    private:
        // Addition: A + B = C
        static std::vector<std::vector<int> > matrixAdd(const std::vector<std::vector<int> > &A,
                                                        const std::vector<std::vector<int> > &B,
                                                        int n);

        // Subtraction: C = A - B
        static std::vector<std::vector<int> > matrixSub(const std::vector<std::vector<int> > &A,
                                                        const std::vector<std::vector<int> > &B,
                                                        int n);

        // Split M into 4 sub-matrices
        static void matrixSplit(const std::vector<std::vector<int> > &M,
                                std::vector<std::vector<int> > &M11,
                                std::vector<std::vector<int> > &M12,
                                std::vector<std::vector<int> > &M21,
                                std::vector<std::vector<int> > &M22,
                                int n);

        // Join 4 sub-matrices into M
        static void matrixJoin(std::vector<std::vector<int> > &M,
                               const std::vector<std::vector<int> > &M11,
                               const std::vector<std::vector<int> > &M12,
                               const std::vector<std::vector<int> > &M21,
                               const std::vector<std::vector<int> > &M22,
                               int n);
    };
}

#endif //INTRODUCTION_TO_ALGORITHMS_CPP_MATRIX_MULTIPLICATION_H