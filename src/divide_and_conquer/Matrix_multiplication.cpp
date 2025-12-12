//
// Created by 李能 on 2025/12/12.
// 矩阵乘法
//

#include "Matrix_multiplication.h"
#include <iomanip>
#include <iostream>
#include <ostream>

using namespace std;
using namespace Matrix_multiplication;

//print
void MatrixMultiplication::printMatrix(const vector<vector<int> > &C) {
    const int n = C.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(4) << C[i][j] << " ";
        }
        cout << endl;
    }
}

//bruteForce
vector<vector<int> > MatrixMultiplication::bruteForce(const vector<vector<int> > &A, const vector<vector<int> > &B,
                                                       const int n) {
    vector C(n, vector(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

//addition: A + B = C
vector<vector<int> > MatrixMultiplication::matrixAdd(const vector<vector<int> > &A,
                                                                const vector<vector<int> > &B,
                                                                const int n) {
    vector C(n, vector(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

//Subtraction: C = A - B
vector<vector<int> > MatrixMultiplication::matrixSub(const vector<vector<int> > &A,
                                                                const vector<vector<int> > &B,
                                                                const int n) {
    vector C(n, vector(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

/* 将矩阵 M 分割成 4 个 n/2 × n/2 的矩阵
 * M                 : 原矩阵
 * M11, M12, M21, M22: 输出的四个子矩阵
 * n                 : 原矩阵维度
 */
void MatrixMultiplication::matrixSplit(const vector<vector<int> > &M, vector<vector<int> > &M11,
                                                  vector<vector<int> > &M12,
                                                  vector<vector<int> > &M21, vector<vector<int> > &M22, const int n) {
    const int half = n / 2;
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            M11[i][j] = M[i][j];
            M12[i][j] = M[i][j + half];
            M21[i][j] = M[i + half][j];
            M22[i][j] = M[i + half][j + half];
        }
    }
}

/*
 * 将 4 个 n/2 × n/2 的矩阵合并成一个矩阵 M
 * M                 : 输出
 * M11, M12, M21, M22: 输入的四个子矩阵
 * n                 : 结果矩阵维度
 */
void MatrixMultiplication::matrixJoin(vector<vector<int> > &M, const vector<vector<int> > &M11,
                                                 const vector<vector<int> > &M12,
                                                 const vector<vector<int> > &M21, const vector<vector<int> > &M22,
                                                 const int n) {
    const int half = n / 2;
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            M[i][j]                 = M11[i][j];
            M[i][j + half]          = M12[i][j];
            M[i + half][j]          = M21[i][j];
            M[i + half][j + half]   = M22[i][j];
        }
    }
}

//核心 Strassen 算法
vector<vector<int> > MatrixMultiplication::matrixStrassen(const vector<vector<int> > &A,
                                                           const vector<vector<int> > &B,
                                                           const int n) {
    if (n == 1) {
        return {{A[0][0] * B[0][0]}}; // 1x1 矩阵直接相乘
    }
    //省略各种校验，例如规模、判空。。。
    //1、分割 A 和 B
    const int half = n / 2;
    vector<vector<int> > A11(half, vector<int>(half)), A12(half, vector<int>(half)),
                         A21(half, vector<int>(half)), A22(half, vector<int>(half));
    vector<vector<int> > B11(half, vector<int>(half)), B12(half, vector<int>(half)),
                         B21(half, vector<int>(half)), B22(half, vector<int>(half));

    matrixSplit(A, A11, A12, A21, A22, n);
    matrixSplit(B, B11, B12, B21, B22, n);

    //2、计算10个中间加减法矩阵 S1——S10

    // S1 = B12 - B22
    vector<vector<int> > S1 = matrixSub(B12, B22, half);
    // S2 = A11 + A12
    vector<vector<int> > S2 = matrixAdd(A11, A12, half);
    // S3 = A21 + A22
    vector<vector<int> > S3 = matrixAdd(A21, A22, half);
    // S4 = B21 - B11
    vector<vector<int> > S4 = matrixSub(B21, B11, half);
    // S5 = A11 + A22
    vector<vector<int> > S5 = matrixAdd(A11, A22, half);
    // S6 = B11 + B22
    vector<vector<int> > S6 = matrixAdd(B11, B22, half);
    // S7 = A12 - A22
    vector<vector<int> > S7 = matrixSub(A12, A22, half);
    // S8 = B21 + B22
    vector<vector<int> > S8 = matrixAdd(B21, B22, half);
    // S9 = A11 - A21
    vector<vector<int> > S9 = matrixSub(A11, A21, half);
    // S10 = B11 + B12
    vector<vector<int> > S10 = matrixAdd(B11, B12, half);

    //3、递归计算 7 个中间乘积 P1——P7
    vector<vector<int> > P1 = matrixStrassen(A11, S1, half);
    vector<vector<int> > P2 = matrixStrassen(S2, B22, half);
    vector<vector<int> > P3 = matrixStrassen(S3, B11, half);
    vector<vector<int> > P4 = matrixStrassen(A22, S4, half);
    vector<vector<int> > P5 = matrixStrassen(S5, S6, half);
    vector<vector<int> > P6 = matrixStrassen(S7, S8, half);
    vector<vector<int> > P7 = matrixStrassen(S9, S10, half);

    //4、组合结果 C_ij
    // C11 = P5 + P4 - P2 + P6
    vector<vector<int> > C11_temp1 = matrixAdd(P5, P4, half);
    vector<vector<int> > C11_temp2 = matrixSub(C11_temp1, P2, half);
    vector<vector<int> > C11 = matrixAdd(C11_temp2, P6, half);

    // C12 = P1 + P2
    vector<vector<int> > C12 = matrixAdd(P1, P2, half);

    // C21 = P3 + P4
    vector<vector<int> > C21 = matrixAdd(P3, P4, half);

    // C22 = P5 + P1 - P3 - P7
    vector<vector<int> > C22_temp1 = matrixAdd(P5, P1, half);
    vector<vector<int> > C22_temp2 = matrixSub(C22_temp1, P3, half);
    vector<vector<int> > C22 = matrixSub(C22_temp2, P7, half);

    //5、合并 C_ij 结果得到矩阵 C
    vector C(n, vector<int>(n));
    matrixJoin(C, C11, C12, C21, C22, n);

    return C;
}
