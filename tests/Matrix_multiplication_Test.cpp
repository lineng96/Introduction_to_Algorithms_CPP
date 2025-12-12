//
// Created by 李能 on 2025/12/12.
//

#include "gtest/gtest.h"
#include "Matrix_multiplication.h"

using namespace std;
using namespace Matrix_multiplication;

using namespace std;
TEST(MatrixMultiplicationTest, bruteForce) {
    constexpr int N = 2;
    const vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };
    const vector<vector<int>> B = {
        {5, 6},
        {7, 8}
    };
    cout << "--- 矩阵乘法 (暴力法) 示例 ---" << endl;
    cout << "矩阵 A:" << endl;
    MatrixMultiplication::printMatrix(A);
    cout << endl;

    cout << "矩阵 B:" << endl;
    MatrixMultiplication::printMatrix(B);
    cout << endl;

    cout << "结果矩阵 C = A * B:" << endl;
    MatrixMultiplication::printMatrix(MatrixMultiplication::bruteForce(A, B, N));
}

TEST(MatrixMultiplicationTest, Strassen) {
    constexpr int N = 2;
    const vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };
    const vector<vector<int>> B = {
        {5, 6},
        {7, 8}
    };

    cout << "--- 矩阵乘法 (Strassen 算法) 示例 ---" << endl;
    cout << "矩阵 A:" << endl;
    MatrixMultiplication::printMatrix(A);
    cout << endl;

    cout << "矩阵 B:" << endl;
    MatrixMultiplication::printMatrix(B);
    cout << endl;

    cout << "结果矩阵 C = A * B:" << endl;
    MatrixMultiplication::printMatrix(MatrixMultiplication::matrixStrassen(A, B, N));
}
