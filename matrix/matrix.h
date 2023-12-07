#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

struct Matrix {
    int** data;
    int size;
};

Matrix create_matrix(int size);

void fill_matrix(Matrix& matrix);

void formula_calculations(const Matrix& matrix, std::vector<float>& vector);

void print_matrix(const Matrix& matrix);

void delete_matrix(Matrix& matrix);

#endif //INPUT_H - > MATRIX_H
