#ifndef MATRIX_H
#define MATRIX_H

#include "../input/input.h"
#include <iostream>
#include <vector>

struct Matrix {
    int** data;
    int size;
};

Matrix create_matrix(int size);

void fill_matrix(Matrix& matrix);

int formula_calculations(Matrix& matrix, std::vector<float>& vector);

void print_matrix(Matrix& matrix);

void delete_matrix(Matrix& matrix);

#endif //INPUT_H

