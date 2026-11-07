#include "Matrix.h"
#include <cstdlib>
#include <algorithm>

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data.resize(rows, std::vector<double>(cols, 0.0));
}

void Matrix::randomize() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        }
    }
}

Matrix Matrix::multiply(const Matrix& a, const Matrix& b) {
    Matrix result(a.rows, b.cols);
    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < b.cols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < a.cols; ++k) {
                sum += a.data[i][k] * b.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

void Matrix::addBias(const std::vector<double>& bias) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] += bias[j];
        }
    }
}

void Matrix::applyReLU() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = std::max(0.0, data[i][j]);
        }
    }
}
