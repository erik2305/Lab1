#include "matrix.h"
#include <iostream>
#include "../input/input.h"

//creates matrix
Matrix create_matrix(int size)
{
	Matrix matrix;
	matrix.data = new int* [size];
        for (int i = 0; i < size +1; i++)
        {
            matrix.data[i] = new int[i];
            //ok, last time I had a lot of questions of what im doing in line
            //we never know when we get bad alloc it can happen when matrix not fully created
            //so we have to track how many rows we've created
            //I change size of the matrix every iteration to know exactly how much of RAM to clear
            matrix.size = i;
        }
    return matrix;
}

//fills matrix with numbers
void fill_matrix(Matrix& matrix)
{
    for (int i = 0; i < matrix.size; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            std::cout << "enter a[" << i + 1 << "][" << j + 1 << "]: ";
            matrix.data[i][j] = int_input();
        }
    }

}

//calculates vector values
int formula_calculations(const Matrix& matrix, std::vector<float>& vector)
{
    int cMin, cMax;
    std::vector<int> rowSum(matrix.size);
    for (int i = 0; i < matrix.size; i++)
    {
        for (int j = 0; j < matrix.size; j++)
        {
            if (j < i + 1) {
                rowSum[i] += matrix.data[i][j];
            }
            else {
                rowSum[i] += matrix.data[j][i];
            }
        }
    }

    cMin = *min_element(rowSum.begin(),rowSum.end());;

    cMax = *max_element(rowSum.begin(),rowSum.end());

    try {
        if(cMin == cMax){
            throw(cMin - cMax);
        }
        else
        for (int i = 0; i < matrix.size; i++) {
            vector[i] = ((float) (rowSum[i] - cMin)) / ((cMax - cMin));
        }
        return 1;
    }
    catch(int denominator) {
        return -1;
    }
}

//prints matrix
void print_matrix(const Matrix& matrix)
{
    for (int i = 0; i < matrix.size; i++)
    {
        for (int j = 0; j < matrix.size; j++) {
            if (j < i + 1) {
                std::cout << matrix.data[i][j] << " ";
            } else {
                std::cout << matrix.data[j][i] << " ";
            }
        }
        std::cout << "\n";
    }
}

//clears space in RAM
void delete_matrix(Matrix& matrix)
{
    for (int i = 0; i < matrix.size+1; i++)
    {
        delete[] matrix.data[i];
    }
    delete[] matrix.data;
}