#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
public:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

    Matrix(int r, int c);
    void randomize();
    static Matrix multiply(const Matrix& a, const Matrix& b);
    void addBias(const std::vector<double>& bias);
    void applyReLU();
};

#endif // MATRIX_H
